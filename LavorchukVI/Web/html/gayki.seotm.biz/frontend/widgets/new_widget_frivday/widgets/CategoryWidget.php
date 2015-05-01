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
use backend\modules\category\models\Category;
use backend\modules\category\models\CategoryTranslate;
use yii\helpers\VarDumper;

class CategoryWidget extends Widget {
    public $name = 'category[]';
    public $model;
    public $attribute;
    public $id;
    private $_categories;
    private $_selected;

    public $no_id;
    public function init()
    {
        if(!$this->no_id)
        $this->no_id = Category::find()->roots()->all()[0]->id;

        if(empty($this->id))
        {
            $this->_categories = ArrayHelper::map(Category::find()
                ->with(['t'])
                ->where(['depth'=>1])
                ->orderBy('category.left ASC')
                ->all(), 'id', function($model) {
                return $model->t->name;
            });
        }
        else
        {
            $model = Category::findOne($this->id);
            $this->_selected = $model->parents()->andWhere('depth > 0')->all();
            $this->_selected[] = $model;
            $categories = Category::find()->indexBy('id')->all();
            foreach($categories as $key => &$category)
            {
                $category->parent = $category->parents(1)->one();
            }

            $res = [];
            $category = $categories[$this->id];
            $index = 0;
            while(true)
            {
                if($category->parent)
                {
                    $parentId = $category->parent->id;
                    $res[$index] = ArrayHelper::map(
                                array_filter($categories,
                                    function($val) use ($parentId) { return $val->parent->id == $parentId; } ),
                                'id', function($v) { return $v->t->name; } );
                    $category = $categories[$parentId];
                    $index++;
                }
                else break;
            }
            $res = array_reverse($res);
            $children = $model->children(1)->all();
            if(!empty($children))
                $res[] = ArrayHelper::map($children, 'id', function($v) { return $v->t->name; });
            $this->_categories = $res;
            unset($res);
        }
//        backend\assets\AppAsset::
    }

    public function run()
    {
        return $this->render('categoryWidget', [
            'categories'=>$this->_categories,
            'name'=>$this->name,
            'model'=>$this->model,
            'attribute'=>$this->attribute,
            'id'=>$this->id,
            'selected'=>$this->_selected,
            'no_id'=>$this->no_id
        ]);
    }
}