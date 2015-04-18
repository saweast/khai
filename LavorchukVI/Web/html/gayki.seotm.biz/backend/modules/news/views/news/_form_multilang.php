<?php
/**
 * Created by PhpStorm.
 * User: Kate
 * Date: 10.02.15
 * Time: 15:05
 * @var $model backend\modules\news\models\NewsTranslate
 * @var $form yii\widgets\ActiveForm
 * @var $language string
 */
use yii\helpers\Html;
use dosamigos\tinymce\TinyMce;
?>

<div>
    <?= $form->field($model, 'title', [
        'template' => "{label}\n{input}\n{hint}\n{error}"
    ])->textInput(array(
        'name' => 'NewsTranslate['.$language.'][title]',
        'id' => 'NewsTranslate_'.$language.'_title' //must be unique because client validation failed
    )); ?>
    <?= $form->field($model, 'text', [
        'template' => "{label}\n{input}\n{hint}\n{error}"
    ])->textarea(array(
        'name' => 'NewsTranslate['.$language.'][text]',
        'id' => 'NewsTranslate_'.$language.'_text' //must be unique because client validation failed
    )); ?>
</div>