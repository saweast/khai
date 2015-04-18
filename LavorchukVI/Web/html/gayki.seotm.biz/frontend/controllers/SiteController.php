<?php
namespace frontend\controllers;
use backend\modules\page\models\Page;
use backend\modules\contact\models\Contact;
use Yii;
use yii\base\InvalidParamException;
use yii\helpers\VarDumper;
use yii\web\BadRequestHttpException;
//use yii\web\Controller;
use yii\filters\VerbFilter;
use yii\filters\AccessControl;
//use app\components;

/**
 * Site controller
 */
class SiteController extends \app\components\Controller
{
    const PAGE_SERVICE = '4';
    const PAGE_CONTACT = '7';
    /**
     * @inheritdoc
     */
    public function behaviors()
    {
        return [
            'access' => [
                'class' => AccessControl::className(),
                'only' => ['logout', 'signup'],
                'rules' => [
                    [
                        'actions' => ['signup'],
                        'allow' => true,
                        'roles' => ['?'],
                    ],
                    [
                        'actions' => ['logout'],
                        'allow' => true,
                        'roles' => ['@'],
                    ],
                ],
            ],
            'verbs' => [
                'class' => VerbFilter::className(),
                'actions' => [
                    'logout' => ['post'],
                ],
            ],
        ];
    }

    /**
     * @inheritdoc
     */
    public function actions()
    {
        return [
            'error' => [
                'class' => 'yii\web\ErrorAction',
            ],
            'captcha' => [
                'class' => 'yii\captcha\CaptchaAction',
                'fixedVerifyCode' => YII_ENV_TEST ? 'testme' : null,
            ],
        ];
    }

    public function actionMainPage(){
        $main_page = Page::find()->with('t')->where(['main_page'=>'1','show'=>'1'])->one();
        if(!$main_page){
            throw new BadRequestHttpException('The requested page does not exist.');
        }
        $page_service = Page::find()->with('t')->where(['id'=>self::PAGE_SERVICE,'show'=>'1'])->one();
        $page_service_children = $page_service->children(1)->orderBy('left')->all();
        $map=Contact::findOne(['is_main'=>'1']);
        return $this->render('main',
            [
                'model'=>$main_page,
                'page_service'=>$page_service,
                'page_service_children'=>$page_service_children,
                'map'=>$map,
            ]);
    }

    public function actionPage($translit){
        $page = Page::find()->with('t','newsattach')->where(['translit'=>substr($translit, 0, strlen($translit)-1),'show'=>'1'])->one();
        $main_page = Page::find()->with('t')->where(['main_page'=>'1','show'=>'1'])->one();
        if(!$page){
            throw new BadRequestHttpException('The requested page does not exist.');
        }
        if($page->id==self::PAGE_CONTACT){
            $contacts = Contact::find()->with('t')->orderBy('is_main')->all();
        }else{
            $contacts='';
        }
        return $this->render('page',
            [
                'model'=>$page,
                'main_page'=>$main_page,
                'contacts'=>$contacts
            ]);
    }
}
