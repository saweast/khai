<?php

namespace backend\modules\newsattach\controllers;

use Yii;
use yii\helpers\VarDumper;
use yii\web\Controller;
use yii\web\NotFoundHttpException;
use yii\filters\VerbFilter;
use yii\filters\AccessControl;
use backend\modules\newsattach\assets\server\php\UploadHandler;
use backend\modules\newsattach\assets\server\php\FileHandler;

class DefaultController extends Controller
{
    public function behaviors()
    {
        return [
            'access' => [
                'class' => AccessControl::className(),
                'rules' => [
                    [
                        'actions' => ['login', 'error'],
                        'allow' => true,
                    ],
                    [
                        'actions'=>['index','create','update','clearTmp','show','delete','sort'],
                        'allow'=>true,
                        'roles'=>['admin']
                    ],
                ],
            ],
            'verbs' => [
                'class' => VerbFilter::className(),
                'actions' => [
                    'delete' => ['post'],
                ],
            ],
        ];
    }

	public function actionIndex()
	{
		return $this->render('index',array(
        ));
	}

    public function actionCreate()
    {
        if(Yii::$app->request->isAjax)
        {
            $upload_handler = new UploadHandler(true);
            Yii::$app->end();
        }
    }

    public function actionShow()
    {
        if(Yii::$app->request->isAjax)
        {
            $file_handler = new FileHandler(true);
            Yii::$app->end();
        }
    }

    public function actionClearTmp()
    {
        if(Yii::$app->request->isAjax){
            $url = isset($_POST['tmp']) ? $_POST['tmp'] : null;
            if($url){
                $this->delete_files($url);
            }
        }
    }

    /**
     * php delete function that deals with directories recursively
     * @param $target - directory path to work with
     * @return bool
     */
    public function delete_files($target) {
        if(is_dir($target)){
            $files = glob( $target . '*', GLOB_MARK ); //GLOB_MARK adds a slash to directories returned
            foreach( $files as $file )
            {
                $this->delete_files( $file);
            }
            if(count(glob( $target . '*', GLOB_MARK )) === 0 && $target != Yii::getAlias('@img_root').'/uploads/tmp/')
                rmdir( $target );
        } else {
            unlink( $target );
        }
    }

    public function actionSort()
    {
        $fileSession = Yii::$app->session['files'];
        $current = (isset($_POST['current'])) ? (int)$_POST['current'] : null;
        $previous = (isset($_POST['previous'])) ? (int)$_POST['previous'] : null;
        $id = (isset($_POST['id'])) ? (int)$_POST['id'] : null;
        $entity = $fileSession['files']['entity'];
        $entity_id = $fileSession['files']['entity_id'];

        if(is_int($previous))
        {
            $updateRange = "update Attachments set position = position + 1 where position > '".$previous."' AND position < '".$current."' AND attachment_entity='".$entity."' AND entity_id='".$entity_id."'";
            Yii::$app->db->createCommand($updateRange)->execute();
            $updateCurrent = "update Attachments set position = '".($previous+1)."' where attachment_id='".$id."'";
            Yii::$app->db->createCommand($updateCurrent)->execute();
        } elseif($previous === "undefined") {
            $updateRange = "update Attachments set position = position + 1 where position > '0' AND position < '".$current."' AND attachment_entity='".$entity."' AND entity_id='".$entity_id."'";
            Yii::$app->db->createCommand($updateRange)->execute();
            $updateCurrent = "update Attachments set position = '1' where attachment_id='".$id."'";
            Yii::$app->db->createCommand($updateCurrent)->execute();
        } else {
            $updateRange = "update Attachments set position = position + 1 where position > '0' AND attachment_entity='".$entity."' AND entity_id='".$entity_id."'";
            Yii::$app->db->createCommand($updateRange)->execute();
            $updateCurrent = "update Attachments set position = '1' where attachment_id='".$id."'";
            Yii::$app->db->createCommand($updateCurrent)->execute();
        }
    }

    public function actionDelete()
    {
        if(Yii::$app->request->isAjax)
        {
            $fileHandler = new FileHandler(false);
            $fileHandler->delete();
            Yii::$app->end();
        }
    }

}