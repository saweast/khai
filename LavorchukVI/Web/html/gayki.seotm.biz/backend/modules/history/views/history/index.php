<?php

use yii\helpers\Html;
use yii\grid\GridView;

/* @var $this yii\web\View */
/* @var $searchModel backend\modules\history\models\HistorySearch */
/* @var $model backend\modules\history\models\History */
/* @var $dataProvider yii\data\ActiveDataProvider */

$this->title = 'Истории';
$this->params['breadcrumbs'][] = ['label' => $this->title, 'url' => ['index']];
?>
<div class="history-index">

    <h1><?= Html::encode($this->title) ?></h1>
    <p>
        <?= Html::a('Создание Истории', ['create',
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
                'attribute'=>'translate.text',
                'value'=>function($data){
                    return Html::a($data->t->text,['update','id'=>$data->id]);
                },
                'filter'=>Html::activeTextInput($searchModel,'text',['class'=>'form-control']),
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