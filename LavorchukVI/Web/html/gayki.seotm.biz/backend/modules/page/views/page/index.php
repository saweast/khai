<?php

use yii\helpers\Html;
use yii\grid\GridView;
use yii\helpers\ArrayHelper;
use backend\modules\region\models\RegionSearch;

/* @var $this yii\web\View */
/* @var $searchModel backend\modules\page\models\PageSearch */
/* @var $model backend\modules\page\models\Page */
/* @var $dataProvider yii\data\ActiveDataProvider */

$this->title = 'Pages';
$this->params['breadcrumbs'][] = ['label' => $this->title, 'url' => ['index']];
if(isset($parent_id) && $parent_id)
{
    $parent = $model->findOne($parent_id);
        $parents = $parent->parents()->all();
        $parents[]=$parent;
        foreach($parents as $parent){
            if($parent->left!='1')
            $this->params['breadcrumbs'][]=['label' => $parent->t->name, 'url' => ['index', 'parent_id' => $parent->id]];
        }
}
?>
<div class="page-index">

    <h1><?= Html::encode($this->title) ?></h1>
    <p>
        <?= Html::a('Create Page', ['create','parent_id'=>$parent_id], ['class' => 'btn btn-success']) ?>
    </p>
    <?php
    ?>
    <?= GridView::widget([
        'dataProvider' => $dataProvider,
        'filterModel' => $searchModel,
        'tableOptions'=>[
            'class'=>'table table-striped table-bordered table-tr-td_position_relative',
            'id'=>'page_sortable'
        ],
        'columns' => [
            ['class' => 'yii\grid\SerialColumn'],
            'id',
            [
                'attribute'=>'translate.name',
                'value'=>function($data){
                    return Html::a($data->t->name,['update','id'=>$data->id]);
                },
                'filter'=>Html::activeTextInput($searchModel,'name',['class'=>'form-control']),
                'format'=>'raw'
            ],
            [
                'attribute'=>'show',
                'value'=>function($data) use ($model){
                    return $data->show?'Отображать':'Не отображать';
                },
                'filter'=>Html::activeDropDownList($searchModel,'show',['1'=>'Отображать','0'=>'Не отображать'],['prompt'=>'Выберите','class'=>'form-control'])
            ],
            [
                'header'=>'Childrens',
                'value'=>function($data) use ($model) {
                $parent = $model->findOne($data->id);
                    $leaves=$parent->leaves()->all();
                    $count_levels=0;
                    if(isset($leaves[0])){
                        $count_levels = $leaves[0]->depth - $data->depth;
                    }
                $count = $parent->children(1)->count();
                return Html::a('Childrens ('.$count.')',['index','parent_id'=>$data->id]).'<br/>'.$count_levels.' Levels';
                },
                'format'=>'raw'
            ],
            [
                'class' => 'yii\grid\ActionColumn',
                'template'=>'{update}{delete}',
                'buttons'=>[
                'delete'=>function($url, $model, $key){
                    return Html::a('<span class="glyphicon glyphicon-trash"></span>', $url,
                [   'title'=>'Удалить',
                    'data-confirm'=>'Вы уверены, что хотите удалить этот элемент? У него могут быть дети(а так же жена, внуки и больная мать!) Подумайте!',
                    'data-method'=>'post',
                    'data-pjax'=>'0'
                ]);
                }
                ]
            ],
        ],
    ]); ?>

</div>