<?php

namespace backend\modules\page\controllers;

use common\components\Translit;
use Yii;
use backend\modules\page\models\Page;
use backend\modules\page\models\PageSearch;
use yii\helpers\VarDumper;
use yii\helpers\Html;
use yii\helpers\ArrayHelper;
use yii\web\Controller;
use yii\web\NotFoundHttpException;
use yii\filters\VerbFilter;
use yii\filters\AccessControl;
use yii\base\Security;
/**
 * PageController implements the CRUD actions for Page model.
 */
class PageController extends Controller
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
                        'actions'=>['index','create','update','delete','movetree', 'get-children', 'deleteimage'],
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

    /**
     * Lists all Page models.
     * @return mixed
     */
    public function actionIndex()
    {
        $model = new Page();
        $searchModel = new PageSearch();
        $dataProvider = $searchModel->search(Yii::$app->request->queryParams);
        return $this->render('index', [
            'searchModel' => $searchModel,
            'dataProvider' => $dataProvider,
            'parent_id' => $searchModel->parent_id,
            'model' => $model,
        ]);
    }

    /**
     * Creates a new Page model.
     * If creation is successful, the browser will be redirected to the 'view' page.
     * @return mixed
     */
    public function actionCreate()
    {
        $model = new Page();
        $model->attachMultilangual();
        $parent_id = Yii::$app->request->queryParams['parent_id'] ? Yii::$app->request->queryParams['parent_id'] : Page::findOne(['left'=>'1'])->id;
        if ($model->load(Yii::$app->request->post()) && $model->validate()) {
            $parent_id=@end(@array_filter(Yii::$app->request->post()['Page']['parent_id']))?@end(@array_filter(Yii::$app->request->post()['Page']['parent_id'])):$parent_id;
            if($model->main_page){
                $model->translit='';
                $model_main_page = Page::findOne(['main_page'=>'1']);
                if($model_main_page){
                    if($model_main_page->t->name){
                        $model_main_page->translit = Translit::cyrillicToLatin($model_main_page->t->name);
                    }else{
                        foreach(Yii::$app->params['languages'] as $lang=>$info) {
                            if($model_main_page->translate[$lang]->name){
                                $model_main_page->translit = Translit::cyrillicToLatin($model_main_page->translate[$lang]->name);
                                break;
                            }
                        }
                    }
                }
                $new_model = new Page();
                $new_model->updateAll(['main_page'=>'0']);
            }else{
                if(!$model->translit){
                    if(Yii::$app->request->post()['PageTranslate'][Yii::$app->language]['name']){
                        $model->translit = Translit::cyrillicToLatin(Yii::$app->request->post()['PageTranslate'][Yii::$app->language]['name']);
                    }else{
                        foreach(Yii::$app->params['languages'] as $lang=>$info) {
                            if(Yii::$app->request->post()['PageTranslate'][$lang]['name']){
                                $model->translit = Translit::cyrillicToLatin(Yii::$app->request->post()['PageTranslate'][$lang]['name']);
                                break;
                            }
                        }
                    }
                }else{
                    $model->translit = Translit::cyrillicToLatin($model->translit);
                }
            }
            if($parent_id){
                $parent = Page::findOne(['id'=>$parent_id]);
                $res = $model->prependTo($parent);
            }else{
                $res = $model->makeRoot();
            }
            if($res){
                if(isset($_FILES['Page']['name']['img']) && $_FILES['Page']['name']['img']){
                    $files=$_FILES['Page'];
                    $name_file=$files['name']['img'];
                    $tmp_name=$files['tmp_name']['img'];
                    $path=Yii::getAlias('@img_root/uploads/'.\yii\helpers\StringHelper::basename(get_class($model)).'/'.$model->id.'/');
                    if(!is_dir($tmp_name)) {
                        $new_name=Security::generateRandomStringStatic(15).'.'.pathinfo($name_file, PATHINFO_EXTENSION);
                        $newPath = $path.$new_name;
                    if (is_dir($path)) {
                        rename($tmp_name, $newPath);
                    } else {
                        mkdir($path, 0777, true);
                        rename($tmp_name, $newPath);
                    }
                     $model->img = $new_name;
                     $model->save(false);
                }
                }
                if($parent_id){
                    return $this->redirect(['index', 'parent_id' => $parent_id]);
                }else{
                    return $this->redirect(['index']);
                }
            }else{
                return $this->render('create', [
                    'model' => $model,
                    'parent_id' => $parent_id,
                ]);
            }
        } else {
            return $this->render('create', [
                'model' => $model,
                'parent_id' => $parent_id,
            ]);
        }
    }

    /**
     * Updates an existing Page model.
     * If update is successful, the browser will be redirected to the 'view' page.
     * @param integer $id
     * @return mixed
     */
    public function actionUpdate($id)
    {
        $model = $this->findModel($id);
        $parent_id = $model->parents(1)->all()[0]->id;
        if ($model->load(Yii::$app->request->post()) && $model->validate()) {
            if(isset($_FILES['Page']['name']['img']) && $_FILES['Page']['name']['img']){
                $files=$_FILES['Page'];
                $name_file=$files['name']['img'];
                $tmp_name=$files['tmp_name']['img'];
                $path=Yii::getAlias('@img_root/uploads/'.\yii\helpers\StringHelper::basename(get_class($model)).'/'.$model->id.'/');
                if(!is_dir($tmp_name)) {
                    $new_name=Security::generateRandomStringStatic(15).'.'.pathinfo($name_file, PATHINFO_EXTENSION);
                    $newPath = $path.$new_name;
                    if (is_dir($path)) {
                        rename($tmp_name, $newPath);
                    } else {
                        mkdir($path, 0777, true);
                        rename($tmp_name, $newPath);
                    }
                    chmod($newPath,0777);
                    $model->img = $new_name;
                }
            }else{
                $model->img = Yii::$app->request->post()['Page']['imgReal'];
            }
            $parent_id=end(array_filter(Yii::$app->request->post()['Page']['parent_id']))?end(array_filter(Yii::$app->request->post()['Page']['parent_id'])):Page::findOne(['left'=>'1'])->id;
            if($model->main_page){
                $model_main_page = Page::findOne(['main_page'=>'1']);
                if($model_main_page){
                    if($model_main_page->t->name){
                        $model_main_page->translit = Translit::cyrillicToLatin($model_main_page->t->name);
                    }else{
                        foreach(Yii::$app->params['languages'] as $lang=>$info) {
                            if($model_main_page->translate[$lang]->name){
                                $model_main_page->translit = Translit::cyrillicToLatin($model_main_page->translate[$lang]->name);
                                break;
                            }
                        }
                    }
                }
                $model->translit='';
                $new_model = new Page();
                $new_model->updateAll(['main_page'=>'0']);
            }else{
                    if(!$model->translit){
                        if(Yii::$app->request->post()['PageTranslate'][Yii::$app->language]['name']){
                            $model->translit = Translit::cyrillicToLatin(Yii::$app->request->post()['PageTranslate'][Yii::$app->language]['name']);
                        }else{
                            foreach(Yii::$app->params['languages'] as $lang=>$info) {
                                if(Yii::$app->request->post()['PageTranslate'][$lang]['name']){
                                    $model->translit = Translit::cyrillicToLatin(Yii::$app->request->post()['PageTranslate'][$lang]['name']);
                                    break;
                                }
                            }
                        }
                    }else{
                        $model->translit = Translit::cyrillicToLatin($model->translit);
                    }
            }
            $parent = Page::findOne(['id'=>$parent_id]);
            $res = $model->prependTo($parent);
            if($res){
                return $this->redirect(['index', 'parent_id' => $parent_id]);
            }else{
                return $this->render('update', [
                    'model' => $model,
                    'parent_id' => $parent_id
                ]);
            }

        } else {
            return $this->render('update', [
                'model' => $model,
                'parent_id' => $parent_id
            ]);
        }
    }

    /**
     * Deletes an existing Page model.
     * If deletion is successful, the browser will be redirected to the 'index' page.
     * @param integer $id
     * @return mixed
     */
    public function actionDelete($id)
    {
//        $this->actionDeleteimage($id);
        $this->findModel($id)->deleteWithChildren();
        return $this->redirect(['index']);
    }

    /**
     * Finds the Page model based on its primary key value.
     * If the model is not found, a 404 HTTP exception will be thrown.
     * @param integer $id
     * @return Page the loaded model
     * @throws NotFoundHttpException if the model cannot be found
     */
    protected function findModel($id)
    {
        if (($model = Page::findOne($id)) !== null) {
            $model->attachMultilangual();
            return $model;
        } else {
            throw new NotFoundHttpException('The requested page does not exist.');
        }
    }
    public function actionMovetree(){

        if(Yii::$app->request->bodyParams['action']){
            $action=Yii::$app->request->bodyParams['action'];
            $id=Yii::$app->request->bodyParams['id'];
            $id_item=Yii::$app->request->bodyParams['id_item'];
            if($action=='moveAfter'){
                $item_after=Page::findOne($id_item);
                $item_our=Page::findOne($id);
                $item_our->moveAfter($item_after);
            }else{
                $item_our=Page::findOne($id);
                $root=$item_our->parents(1)->all();
                $item_our->moveAsFirst($root[0]);
            }
        }
    }

    public function actionGetChildren() {
        if(Yii::$app->request->isAjax) {
            if($_POST['id']) {
                $no_id = '';
                if($_POST['no_id']){
                    $no_id=$_POST['no_id'];
                }
                $model = Page::findOne($_POST['id']);
                $children = $model->children(1)->andWhere('id!='.$no_id)->with('t')->all();
                $categories = ArrayHelper::map($children, 'id', function($model){
                    return $model->t->name;
                });
                $name = isset($_POST['name']) ? $_POST['name'] : 'page[]';
                if(!empty($categories))
                {
                    die(Html::dropDownList($name, null, $categories, [
                            'class'=>'form-control page-select',
                            'data-no_id'=>$no_id,
                            'prompt'=>'Выберите категорию']
                    ));
                }
                else die('');
            } else
                die('');
        } else
            throw HttpExcetion(400, 'Ajax only');
    }

    public function actionDeleteimage($page_id){
        $model = $this->findModel($page_id);
        $this->clear_dir(Yii::getAlias('@img_root/uploads/'.\yii\helpers\StringHelper::basename(get_class($model)).'/'.$model->id.'/'));
        $model->img = '';
        $model->save(false);
    }

    private function myscandir($dir){
            $list = scandir($dir);
            unset($list[0],$list[1]);
            return array_values($list);
    }

    private function clear_dir($dir)
    {
        $list = $this->myscandir($dir);
    
        foreach ($list as $file)
        {
            if (is_dir($dir.$file))
            {
                $this->clear_dir($dir.$file.'/');
                rmdir($dir.$file);
            }
            else
            {
                unlink($dir.$file);
            }
        }
    }
}
