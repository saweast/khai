<?php
/**
 * Created by PhpStorm.
 * User: Kate
 * Date: 10.02.15
 * Time: 15:05
 * @var $model backend\modules\news\models\NewsCategoryTranslate
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
        'name' => 'NewsCategoryTranslate['.$language.'][name]',
        'id' => 'NewsCategoryTranslate_'.$language.'_name' //must be unique because client validation failed
    )); ?>
</div>