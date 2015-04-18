<?php
namespace frontend\controllers;
use backend\modules\feedback\models\Feedback;
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
 * Feedback controller
 */
class FeedbackController extends \app\components\Controller
{
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

    public function actionSave(){
//        VarDumper::dump(Yii::$app->request->post(),6,1);
//        die();
            $model = new Feedback();
                $model->name=$_REQUEST['name'];
                $model->email=$_REQUEST['email'];
                $model->text=$_REQUEST['text'];

        $res = $model->save();
        if($res)
            echo 'success';
        else
            echo 'fail';
        }
}
