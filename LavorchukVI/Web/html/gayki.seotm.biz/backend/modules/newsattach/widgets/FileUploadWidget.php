<?php
/**
 * Created by PhpStorm.
 * User: chosen1
 * Date: 29.10.13
 * Time: 11:37
 */
namespace backend\modules\newsattach\widgets;
use yii\helpers\VarDumper;
use yii\widgets\InputWidget;
use Yii;

class FileUploadWidget extends InputWidget{

    public $entity;
    public $entity_id;
    public $versions;
    public $tempUrl;
    public $uploadUrl;
    public $webTmp;
    public $webUrl;
    public $filePath;
    public $filesToken;
    public $entity_relation_name;
    public $formName = 'form';
    public $fileTypes = array();
    public function init()
    {
        $filesArray = array(
            'files'=>array(
                'entity'=>$this->entity,
                'entity_id'=> $this->entity_id,
                'versions'=>$this->versions,
                'tempUrl'=>$this->tempUrl,
                'uploadUrl'=>$this->uploadUrl,
                'webTmp'=>$this->webTmp,
                'webUrl'=>$this->webUrl,
                'filePath'=>$this->filePath,
                'entity_relation_name'=>$this->entity_relation_name,
                'fileTypes'=>$this->fileTypes,
            )
        );
        Yii::$app->session['files'] = $filesArray;
    }


    public function run()
    {
        return $this->render('fileUpload');
    }

}