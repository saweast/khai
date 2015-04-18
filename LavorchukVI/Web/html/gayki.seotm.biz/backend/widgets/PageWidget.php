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
    public $id;
    private $_pages;
    private $_selected;

    public $no_id;
    public function init()
    {
        if(!$this->no_id)
            $this->no_id = Page::find()->roots()->all()[0]->id;

        if(empty($this->id))
        {
            $this->_pages = ArrayHelper::map(Page::find()
                ->with(['t'])
                ->where(['depth'=>1])
                ->orderBy('page.left ASC')
                ->all(), 'id', function($model) {
                return $model->t->name;
            });
        }
        else
        {
            $model = Page::findOne($this->id);
            $this->_selected = $model->parents()->andWhere('depth > 0')->all();
            $this->_selected[] = $model;
            $pages = Page::find()->indexBy('id')->all();
            foreach($pages as $key => &$page)
            {
                $page->parent = $page->parents(1)->one();
            }

            $res = [];
            $page = $pages[$this->id];
            $index = 0;
            while(true)
            {
                if($page->parent)
                {
                    $parentId = $page->parent->id;
                    $res[$index] = ArrayHelper::map(
                        array_filter($pages,
                            function($val) use ($parentId) { return $val->parent->id == $parentId; } ),
                        'id', function($v) { return $v->t->name; } );
                    $page = $pages[$parentId];
                    $index++;
                }
                else break;
            }
            $res = array_reverse($res);
            $children = $model->children(1)->all();
            if(!empty($children))
                $res[] = ArrayHelper::map($children, 'id', function($v) { return $v->t->name; });
            $this->_pages = $res;
            unset($res);
        }
//        backend\assets\AppAsset::
    }

    public function run()
    {
        return $this->render('pageWidget', [
            'pages'=>$this->_pages,
            'name'=>$this->name,
            'model'=>$this->model,
            'attribute'=>$this->attribute,
            'id'=>$this->id,
            'selected'=>$this->_selected,
            'no_id'=>$this->no_id
        ]);
    }
}