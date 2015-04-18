<?php

use yii\helpers\Html;
use yii\grid\GridView;

/* @var $this yii\web\View */
/* @var $searchModel backend\modules\news\models\NewsSearch */
/* @var $model backend\modules\news\models\News */
/* @var $dataProvider yii\data\ActiveDataProvider */

$this->title = 'Новости';
$this->params['breadcrumbs'][] = ['label' => $this->title, 'url' => ['index']];
$news_cat = \backend\modules\newscategory\models\NewsCategory::find()->with('t')->where(['show'=>1])->asArray()->indexBy('id')->all();
?>
<div class="news-index">

    <h1><?= Html::encode($this->title) ?></h1>
    <p>
        <?= Html::a('Создание Новости', ['create',
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
                'attribute'=>'translate.title',
                'value'=>function($data){
                    return Html::a($data->t->title,['update','id'=>$data->id]);
                },
                'filter'=>Html::activeTextInput($searchModel,'title',['class'=>'form-control']),
                'format'=>'raw'
            ],
            [
                'attribute'=>'category_id',
                'value'=>function($data) use ($news_cat){
                    return $news_cat[$data->category_id]['t']['name'];
                },
                'filter'=>Html::activeDropDownList($searchModel,'category_id',\yii\helpers\ArrayHelper::map($news_cat,'id',function($arr){
                    return $arr['t']['name'];
                }),[
                    'class'=>'form-control',
                    'prompt'=>'Выберите'
                ]),
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