<?php

use yii\helpers\Html;
use yii\widgets\ActiveForm;

/* @var $this yii\web\View */
/* @var $model backend\modules\news\models\NewsCategory */
/* @var $form yii\widgets\ActiveForm */
?>

<div class="news-form">

    <?php $form = ActiveForm::begin(); ?>
    <?= $form->field($model, 'show')->checkbox()?>
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
