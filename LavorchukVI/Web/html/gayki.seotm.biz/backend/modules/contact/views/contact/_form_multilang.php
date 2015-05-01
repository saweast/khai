<?php
/**
 * Created by PhpStorm.
 * User: Kate
 * Date: 10.02.15
 * Time: 15:05
 * @var $model backend\modules\contact\models\ContactTranslate
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
        'name' => 'ContactTranslate['.$language.'][name]',
        'id' => 'ContactTranslate_'.$language.'_name' //must be unique because client validation failed
    )); ?>
    <?= $form->field($model, 'email', [
        'template' => "{label}\n{input}\n{hint}\n{error}"
    ])->textInput(array(
            'name' => 'ContactTranslate['.$language.'][email]',
            'id' => 'ContactTranslate_'.$language.'_email' //must be unique because client validation failed
        )); ?>
    <?= $form->field($model, 'phone', [
        'template' => "{label}\n{input}\n{hint}\n{error}"
    ])->textInput(array(
        'name' => 'ContactTranslate['.$language.'][phone]',
        'id' => 'ContactTranslate_'.$language.'_phone' //must be unique because client validation failed
    )); ?>
    <?= $form->field($model, 'address', [
        'template' => "{label}\n{input}\n{hint}\n{error}"
    ])->textInput(array(
        'name' => 'ContactTranslate['.$language.'][address]',
        'id' => 'ContactTranslate_'.$language.'_address' //must be unique because client validation failed
    )); ?>
    <?= $form->field($model, 'map', [
        'template' => "{label}\n{input}\n{hint}\n{error}"
    ])->textarea(array(
        'name' => 'ContactTranslate['.$language.'][map]',
        'id' => 'ContactTranslate_'.$language.'_map' //must be unique because client validation failed
    )); ?>
</div>