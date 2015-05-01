<?php
$params = array_merge(
    require(__DIR__ . '/../../common/config/params.php'),
    require(__DIR__ . '/../../common/config/params-local.php'),
    require(__DIR__ . '/params.php'),
    require(__DIR__ . '/params-local.php')
);
Yii::setAlias('@img_root', realpath(dirname(__FILE__).'/../../'));
return [
    'id' => 'app-backend',
    'basePath' => dirname(__DIR__),
    'controllerNamespace' => 'backend\controllers',
    'bootstrap' => ['log','gii'],
    'language' => 'ru',
    'sourceLanguage' => 'ru',
    'modules' => [
        'gii'=>[
            'class'=>'yii\gii\Module',
            'allowedIPs'=>['127.0.0.1','46.219.1.171'],
        ],
        'multilanguage' => [
            'class' => 'backend\modules\multilanguage\multilanguage',
        ],
        'newsattach'=>[
            'class'=>'backend\modules\newsattach\Attachment'
        ],
        'page' => [
            'class' => 'backend\modules\page\Page',
        ],
        'contact' => [
            'class' => 'backend\modules\contact\Contact',
        ],
        'news' => [
            'class' => 'backend\modules\news\News',
        ],
        'newscategory' => [
            'class' => 'backend\modules\newscategory\NewsCategory',
        ],
        'history' => [
            'class' => 'backend\modules\history\History',
        ],
        'feedback' => [
            'class' => 'backend\modules\feedback\Feedback',
        ],
    ],
    'components' => [
        'user' => [
            'identityClass' => 'common\models\User',
            'enableAutoLogin' => true,
        ],
        'log' => [
            'traceLevel' => YII_DEBUG ? 3 : 0,
            'targets' => [
                [
                    'class' => 'yii\log\FileTarget',
                    'levels' => ['error', 'warning'],
                ],
            ],
        ],
        'errorHandler' => [
            'errorAction' => 'site/error',
        ],
        'request'=>[
            'class' => 'common\components\Request',
            'web'=> '/backend/web',
            'adminUrl' => '/backend'
        ],
        'urlManager' => [
            'enablePrettyUrl' => true,
            'showScriptName' => false,
            'rules' => [
                '' => 'page/page/index',
                '<controller:\w+>/<action:\w+>' => '<controller>/<action>',
                '<module:\w+>/<controller:\w+>/<action:\w+>' => '<module>/<controller>/<action>',
            ]
        ],
        'assetManager' => [
            'bundles' => [
                'yii\web\JqueryAsset' => [
                    'jsOptions'=>[
                        'position'=>\yii\web\View::POS_HEAD,
                    ]
                ],
            ],
        ],
    ],
    'params' => $params,
];
