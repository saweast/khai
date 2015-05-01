<?php

use yii\helpers\Html;
use yii\grid\GridView;

/* @var $this yii\web\View */
/* @var $dataProvider yii\data\ActiveDataProvider */

$this->title = 'Dictionary Translates';
$this->params['breadcrumbs'][] = $this->title;
?>
<div class="dictionary-translate-index">

    <h1><?= Html::encode($this->title) ?></h1>

    <p>
        <?= Html::a('Create Dictionary Translate', ['create'], ['class' => 'btn btn-success']) ?>
    </p>

    <?= GridView::widget([
        'dataProvider' => $dataProvider,
        'filterModel' => $searchModel,
        'columns' => [
            ['class' => 'yii\grid\SerialColumn'],

            [
                'attribute'=>'category',
                'filter'=>Html::activeDropDownList($searchModel, 'category', \common\components\ZHtml::enumItem($searchModel, 'category'),['class'=>'form-control'])
            ],
            'message',
            [
                'value'=>function($data){
                        return $data->t->translation;
                    },
            ],
            [
                'class' => 'yii\grid\ActionColumn',
                'template'=>'{update}{delete}',
            ],
        ],
    ]); ?>

</div>
