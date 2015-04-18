<?php

use yii\helpers\Html;
use yii\widgets\ActiveForm;
use yii\jui\DatePicker;
/* @var $this yii\web\View */
/* @var $model backend\modules\news\models\News */
/* @var $form yii\widgets\ActiveForm */
$news_cat = \backend\modules\newscategory\models\NewsCategory::find()->with('t')->where(['show'=>1])->asArray()->all();
?>

<div class="news-form">

    <?php $form = ActiveForm::begin(); ?>
    <?= $form->field($model, 'show')->checkbox()?>
    <?= $form->field($model, 'category_id')->dropDownList(\yii\helpers\ArrayHelper::map($news_cat, 'id', function($arr){
        return $arr['t']['name'];
    }));?>
    <?= $form->field($model, 'date')->widget(DatePicker::classname(), [
        'language' => 'ru',
        'options'=>[
            'class'=>'form-control'
        ],
        'dateFormat' => 'dd-MM-yyyy',
    ]) ?>
    <?php
    $items = [];
    foreach(Yii::$app->params['languages'] as $lang=>$info) {
        $tab = [
            'label' => $info['lang'],
            'content' => $this->context->renderPartial('_form_multilang', [
                'form'=>$form,
                'model'=>$model->translateModels[$lang],
                'language'=>$lang,
            ]),
            'active' => $lang == Yii::$app->language
        ];

        $items[] = $tab;
    }

    echo yii\bootstrap\Tabs::widget([
        'items' => $items,
    ]);
    ?>
    <div class="form-group">
        <?= Html::submitButton($model->isNewRecord ? 'Создать' : 'Сохранить', ['class' => $model->isNewRecord ? 'btn btn-success' : 'btn btn-primary']) ?>
    </div>

    <?php ActiveForm::end(); ?>

</div>
