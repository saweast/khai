<?php
/**
 * Created by PhpStorm.
 * User: Kate
 * Date: 09.02.15
 * Time: 14:13
 */

namespace app\components;
use Yii;

//use yii\web\Controller;

class Controller extends \yii\web\Controller {
    public function init()
    {
//        if (empty($_GET['language']))
//            $_GET['language'] = Yii::$app->sourceLanguage;

//        Yii::$app->language = $_GET['language'];
//        unset($_GET['language']);
        parent::init();
    }
} 