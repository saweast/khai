<?php

use yii\helpers\Html;
use yii\grid\GridView;

/* @var $this yii\web\View */
/* @var $searchModel backend\modules\contact\models\ContactSearch */
/* @var $model backend\modules\contact\models\Contact */
/* @var $dataProvider yii\data\ActiveDataProvider */

$this->title = 'Контакты';
$this->params['breadcrumbs'][] = ['label' => $this->title, 'url' => ['index']];
?>
<div class="contact-index">

    <h1><?= Html::encode($this->title) ?></h1>
    <p>
        <?= Html::a('Создать Контакт', ['create',
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
            [
                'attribute'=>'is_main',
                'value'=>function($data) use ($model){
                    return $data->is_main?'Отображать на главной':'Не отображать на главной';
                },
                'filter'=>Html::activeDropDownList($searchModel,'is_main',['1'=>'Отображать на главной','0'=>'Не отображать на главной'],['prompt'=>'Выберите','class'=>'form-control'])
            ],
            ['class' => 'yii\grid\ActionColumn',
            'template'=>'{update}{delete}'],
        ],
    ]); ?>

</div>