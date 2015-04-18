<?php

use yii\helpers\Html;
use yii\widgets\ActiveForm;

/* @var $this yii\web\View */
/* @var $model backend\modules\multilanguage\models\DictionaryTranslate */
/* @var $form yii\widgets\ActiveForm */
?>


<div class="dictionary-translate-form span6">

    <?php $form = ActiveForm::begin(); ?>
<!--    --><?//= \yii\helpers\VarDumper::dump($model->getErrors(),6,1); ?>
    <?= $form->field($model, 'category', [
        'template' => "{label}\n{input}\n{hint}\n{error}"
    ])->dropDownList(\common\components\ZHtml::enumItem($model, 'category'))?>

    <?= $form->field($model, 'message')->textInput(); ?>

    <?php foreach (Yii::$app->params['languages'] as $lang=>$info): ?>
        <div>
<!--            --><?//= \yii\helpers\VarDumper::dump($model->translateModels[$lang]->getErrors(), 5,1)?>
            <?= $form->field($model->translateModels[$lang], 'translation', [
                'template'=>"{label} [$lang] \n{input}\n{hint}\n{error}"
            ])->textarea(['name'=>'DictionaryTranslate['.$lang.'][translation]', 'rows'=>5])?>
        </div>
    <?php endforeach; ?>

    <div class="form-group">
        <?= Html::submitButton($model->isNewRecord ? 'Create' : 'Update', ['class' => $model->isNewRecord ? 'btn btn-success' : 'btn btn-primary']) ?>
    </div>

    <?php ActiveForm::end(); ?>

</div>
