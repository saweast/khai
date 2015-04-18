<?php
/**
 * Created by PhpStorm.
 * User: Kate
 * Date: 19.02.15
 * Time: 12:09
 */
namespace backend\widgets;

use yii\base\Widget;
use yii\helpers\Html;
use yii\helpers\ArrayHelper;
use backend\modules\page\models\Page;
use backend\modules\page\models\PageTranslate;
use yii\helpers\VarDumper;

class PageWidget extends Widget {
    public $name = 'page[]';
    public $model;
    public $attribute;
    private $_categories;

    public $no_id;
    public function init()
    {
        if(!$this->no_id)
        $this->no_id = Page::find()->roots()->all()[0]->id;
        $this->_categories = ArrayHelper::map(Page::find()
            ->with(['t'])
            ->andWhere(['depth'=>1])
            ->andWhere('id!='.$this->no_id)
            ->orderBy('page.left ASC')
            ->all(), 'id', function($model){
                return $model->t->name;
            });
    }

    public function run()
    {
        return $this->render('pageWidget', [
            'categories'=>$this->_categories,
            'name'=>$this->name,
            'model'=>$this->model,
            'attribute'=>$this->attribute,
            'no_id'=>$this->no_id
        ]);
    }
}