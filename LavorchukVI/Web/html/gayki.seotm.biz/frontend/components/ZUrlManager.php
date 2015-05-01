<?php
/**
 * Created by PhpStorm.
 * User: Kate
 * Date: 09.02.15
 * Time: 12:43
 */
namespace frontend\components;
use yii\helpers\VarDumper;
use yii\web\UrlManager;
use Yii;

class ZUrlManager  extends UrlManager
{
    public function createUrl($route,$params=array(),$ampersand='&')
    {
        if(!isset($params['language'])){
            $s = '';
            return $s.$this->fixPathSlashes(parent::createUrl($route, $params, $ampersand));
        }

        if((isset($params['language']) && $params['language'] == Yii::$app->sourceLanguage)){
            $s = '';
            unset($params['language']);
            return $s.$this->fixPathSlashes(parent::createUrl($route, $params, $ampersand));
        }

        if(isset($params['language']) && $params['language'] != Yii::$app->sourceLanguage){
            $s = '/'.$params['language'];
            unset($params['language']);
            return $s.$this->fixPathSlashes(parent::createUrl($route, $params, $ampersand));
        }
    }

    protected  function fixPathSlashes($url)
    {
        return preg_replace('|\%2F|i', '/', $url);
    }
}