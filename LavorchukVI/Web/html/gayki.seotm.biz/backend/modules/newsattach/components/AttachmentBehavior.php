<?php
/**
 * Created by JetBrains PhpStorm.
 * User: chosen1
 * Date: 22.10.13
 * Time: 12:11
 * To change this template use File | Settings | File Templates.
 */
namespace backend\modules\newsattach\components;

use Yii;
use yii\base\Behavior;
use yii\base\Exception;
use yii\base\InvalidConfigException;
use yii\db\ActiveQuery;
use yii\db\ActiveRecord;
use yii\helpers\VarDumper;
use yii\helpers\BaseJson;
use yii\validators\Validator;
use backend\modules\newsattach\models\Attachment;

class AttachmentBehavior extends Behavior {


    public $entity_id;
    public $upload_path;
    /**
     * @inheritdoc
     */
    public function events()
    {
        return [
//            ActiveRecord::EVENT_BEFORE_INSERT => 'beforeInsert',
            ActiveRecord::EVENT_AFTER_INSERT => 'afterInsert',
//            ActiveRecord::EVENT_BEFORE_UPDATE => 'beforeUpdate',
            ActiveRecord::EVENT_AFTER_UPDATE => 'afterUpdate',
//            ActiveRecord::EVENT_BEFORE_DELETE => 'beforeDelete',
            ActiveRecord::EVENT_AFTER_DELETE => 'afterDelete',
        ];
    }
    /**
     * php delete function that deals with directories recursively
     * @param $target - directory path to work with
     */
    public function delete_files($target) {
        if(is_dir($target)){
            $files = glob( $target . '*', GLOB_MARK ); //GLOB_MARK adds a slash to directories returned
            if(is_array($files)) {
                foreach( $files as $file )
                {
                    $this->delete_files( $file );
                }
            }
            rmdir( $target );
        } elseif(is_file($target)) {
            unlink( $target );
        }
    }

    /**
     * moves files from temporary to destination folder and writes them to DB
     * @param $tmpPath
     * @param $uploadDir
     * @param $model
     */
    protected function moveFiles($tmpPath,$uploadDir,$model)
    {
        $allFiles = is_dir($tmpPath) ? scandir($tmpPath) : null;
        if($allFiles){
            foreach($allFiles as $file){
                if(!is_dir($tmpPath.$file)){
                    $newPath = $uploadDir.$file;
                    if(is_dir($uploadDir)){
                        rename($tmpPath.$file,$newPath);
                    } else {
                        mkdir($uploadDir,0777,true);
                        rename($tmpPath.$file,$newPath);
                    }
                    $modelExist = Attachment::findAll(array('path'=>$file,'entity_id'=>(int)$this->entity_id));
                    if(!$modelExist){
                        $fileExt = strtolower(pathinfo($newPath,PATHINFO_EXTENSION));
                        $newsattachment = new Attachment;
                        $newsattachment->attachment_entity = \yii\helpers\StringHelper::basename(get_class($this->owner));
                        $newsattachment->entity_id = $this->owner->id;
                        $newsattachment->path = $file;
                        switch($fileExt){
                            case 'jpg':
                            case 'jpeg':
                            case 'png':
                            case 'gif':
                                $newsattachment->type = 'image';
                                break;
                            case 'mp3':
                                $newsattachment->type = 'music';
                                break;
                            case 'mpeg4':
                            case 'avi':
                                $newsattachment->type = 'video';
                                break;
                            default :
                                $newsattachment->type = 'file';
                            break;
                        }
                        $sql = "select max(position)
                            from Attachments
                            where attachment_entity='".$newsattachment->attachment_entity."' and entity_id='".$newsattachment->entity_id."'";
                        $max = Yii::$app->db->createCommand($sql)->queryScalar();
                        $newsattachment->position = $max+1;
                        $newsattachment->save(false);
                    }

                } else {
                    if($file ==='.' || $file === '..')
                        continue;
                    else
                        $this->moveFiles($tmpPath.$file.DIRECTORY_SEPARATOR,$uploadDir.$file.DIRECTORY_SEPARATOR,$model);
                }
            }
        }
    }

    public function afterInsert($event)
    {
        $this->save_newsattaches();
    }

    public function afterUpdate($event){
        $this->save_newsattaches();
    }

    public function save_newsattaches(){
        if(isset(Yii::$app->session['files'])){
            $files = Yii::$app->session['files'];
            $this->entity_id = $this->owner->{$files['files']['entity_relation_name']};
            $tmpPath = $files['files']['tempUrl'];
            $uploadDir = $files['files']['uploadUrl'].$files['files']['entity'].DIRECTORY_SEPARATOR.$this->entity_id.DIRECTORY_SEPARATOR;
            $this->moveFiles($tmpPath,$uploadDir,$this->entity_id);
            unset(Yii::$app->session['files']);
            $this->delete_files($tmpPath);
            return true;
        }
    }

    public function afterDelete($event)
    {
        $entity = get_class($this->owner);
        $entity_id = $this->owner->id;

        Attachment::deleteAll(array('attachment_entity'=>$entity,'entity_id'=>$entity_id));
        $this->delete_files($this->upload_path.$entity.DIRECTORY_SEPARATOR.$entity_id.DIRECTORY_SEPARATOR);
    }


}