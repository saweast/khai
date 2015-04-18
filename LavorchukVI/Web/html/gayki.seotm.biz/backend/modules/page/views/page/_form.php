<?php

use yii\helpers\Html;
use yii\widgets\ActiveForm;
use yii\helpers\ArrayHelper;
use backend\widgets\PageWidget;
use backend\modules\page\models\PageSearch;
/* @var $this yii\web\View */
/* @var $model backend\modules\page\models\Page */
/* @var $form yii\widgets\ActiveForm */
?>
<div class="page-form">

    <?php $form = ActiveForm::begin([
        'options' => ['enctype'=>'multipart/form-data']
    ]); ?>
    <?=PageWidget::widget(
        [
            'name'=>'Page[parent_id][]',
            'no_id'=>$model->id,
            'id'=>$parent_id
        ]
    );?>

    <?= $form->field($model, 'show')->checkbox()?>
    <?= $form->field($model, 'show_in_menu')->checkbox()?>
    <?= $form->field($model, 'main_page')->checkbox()?>
    <input type="hidden" id="page-img" name="Page[imgReal]" value="<?=$model->img?>">
    <?php
    if(!empty($model->img)){
        ?>
        <div class="img_page">
        <?= Html::img(Yii::getAlias('/uploads/'.\yii\helpers\StringHelper::basename(get_class($model)).'/'.$model->id.'/'.$model->img),
            [
                'width'=>'200px'
            ])?>
        <?= Html::button('Удалить фото',['class'=>'delete_page_photo','data-id'=>$model->id])?>
        </div>
<!--        <input type="file" id="page-img" name="Page[img]" value="">-->
        <?= $form->field($model, 'img')->fileInput()?>

        <?php
    } else { ?>
<!--        <input type="file" id="page-img" name="Page[img]" value="">-->
        <?= $form->field($model, 'img')->fileInput()?>
    <?php } ?>
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
    <?= $form->field($model, 'translit')->textInput() ?>
    <div class="form-group">
        <?= Html::submitButton($model->isNewRecord ? 'Create' : 'Update', ['class' => $model->isNewRecord ? 'btn btn-success' : 'btn btn-primary']) ?>
    </div>

    <?php ActiveForm::end(); ?>

</div>
