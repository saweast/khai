<?php
/**
 * Created by PhpStorm.
 * User: Kate
 * Date: 10.02.15
 * Time: 15:05
 * @var $model backend\modules\page\models\PageTranslate
 * @var $form yii\widgets\ActiveForm
 * @var $language string
 */
use yii\helpers\Html;
use dosamigos\tinymce\TinyMce;
?>

<div>
    <?= $form->field($model, 'name', [
        'template' => "{label}\n{input}\n{hint}\n{error}"
    ])->textInput(array(
            'name' => 'PageTranslate['.$language.'][name]',
            'id' => 'PageTranslate_'.$language.'_name' //must be unique because client validation failed
        )); ?>
    <?= $form->field($model, 'title', [
        'template' => "{label}\n{input}\n{hint}\n{error}"
    ])->textInput(array(
        'name' => 'PageTranslate['.$language.'][title]',
        'id' => 'PageTranslate_'.$language.'_title' //must be unique because client validation failed
    )); ?>

    <?= $form->field($model, 'text')->widget(TinyMce::className(), [
        'options' => [
            'rows' => 6,
            'name'=>'PageTranslate['.$language.'][text]',
            'id'=>'page-translate-text-'.$language,
        ],
        'language' => 'ru',
        'clientOptions' => [
            'height'=>'300',
            'plugins' => [
                "advlist autolink lists link charmap print preview anchor",
                "searchreplace visualblocks code fullscreen",
                "insertdatetime media table contextmenu paste "
            ],
            'toolbar' => "undo redo | styleselect | fontselect fontsizeselect bold italic | alignleft aligncenter alignright alignjustify | bullist numlist outdent indent | link image"
        ]
    ]);?>
    <?= $form->field($model, 'seo_title', [
        'template' => "{label}\n{input}\n{hint}\n{error}"
    ])->textInput(array(
        'name' => 'PageTranslate['.$language.'][seo_title]',
        'id' => 'PageTranslate_'.$language.'_seo_title' //must be unique because client validation failed
    )); ?>
    <?= $form->field($model, 'seo_descr', [
        'template' => "{label}\n{input}\n{hint}\n{error}"
    ])->textInput(array(
        'name' => 'PageTranslate['.$language.'][seo_descr]',
        'id' => 'PageTranslate_'.$language.'_seo_descr' //must be unique because client validation failed
    )); ?>
    <?= $form->field($model, 'seo_keywords', [
        'template' => "{label}\n{input}\n{hint}\n{error}"
    ])->textInput(array(
        'name' => 'PageTranslate['.$language.'][seo_keywords]',
        'id' => 'PageTranslate_'.$language.'_seo_keywords' //must be unique because client validation failed
    )); ?>
    <?= $form->field($model, 'video', [
        'template' => "{label}\n{input}\n{hint}\n{error}"
    ])->textInput(array(
        'name' => 'PageTranslate['.$language.'][video]',
        'id' => 'PageTranslate_'.$language.'_video' //must be unique because client validation failed
    )); ?>

</div>