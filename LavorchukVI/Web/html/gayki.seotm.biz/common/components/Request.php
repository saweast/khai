<?php
/**
 * Created by PhpStorm.
 * User: max
 * Date: 09.02.15
 * Time: 10:23
 */
namespace common\components;
use Yii;
use yii\helpers\VarDumper;

class Request extends \yii\web\Request

{

    public $web;

    public $adminUrl;
    private  $_lang_url;



    public function getBaseUrl()

    {
        return str_replace($this->web, "", parent::getBaseUrl()) . $this->adminUrl;

    }

    public function init()
    {
        $url = $this->getUrl();
        $matches = array();
        preg_match('/^\/([a-z]{2})\//', $url, $matches);
        if(is_array($matches))
        {
            if(!empty($matches))
            {
                Yii::$app->language = $matches[1];
                $this->setUrl(str_replace($matches[0], '/', $url));

            }
        }
        parent::init();
    }

    public function getLangUrl()
    {
        if ($this->_lang_url === null) {
            $this->_lang_url = $this->getUrl();

            $url_list = explode('/', $this->_lang_url);

            $lang_url = isset($url_list[1]) ? $url_list[1] : null;
//            die(VarDumper::dump($this->getUrl(),5,1));
            Yii::$app->language = $lang_url;

//            if( $lang_url !== null && $lang_url === Lang::getCurrent()->url &&
//                strpos($this->_lang_url, Lang::getCurrent()->url) === 1 )
            {
                $this->_lang_url = substr($this->_lang_url, strlen('en')+1);
//                die($this->_lang_url);
            }
        }

        return $this->_lang_url;
    }


    public function resolvePathInfo()
    {
        if ($this->getUrl() === $this->adminUrl) {
            return "";
        } else {
//            die(VarDumper::dump(parent::resolvePathInfo(),5,1));
            return parent::resolvePathInfo();
        }
    }
}