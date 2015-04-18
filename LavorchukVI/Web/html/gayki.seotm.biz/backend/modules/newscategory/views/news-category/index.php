<?php

use yii\helpers\Html;
use yii\grid\GridView;

/* @var $this yii\web\View */
/* @var $searchModel backend\modules\news\models\NewsCategorySearch */
/* @var $model backend\modules\news\models\NewsCategory */
/* @var $dataProvider yii\data\ActiveDataProvider */

$this->title = 'Категории Новостей';
$this->params['breadcrumbs'][] = ['label' => $this->title, 'url' => ['index']];
?>
<div class="news-index">

    <h1><?= Html::encode($this->title) ?></h1>
    <p>
        <?= Html::a('Создание Категории Новости', ['create',
            ],
            ['class' => 'btn btn-success']) ?>
    </p>

    <?= GridView::widget([
        'dataProvider' => $dataProvider,
        'filterModel' => $searchModel,
        'tableOptions'=>[
            'class'=>'table table-striped table-bordered',
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
            ['class' => 'yii\grid\ActionColumn',
            'template'=>'{update}{delete}'],
        ],
    ]); ?>

</div>