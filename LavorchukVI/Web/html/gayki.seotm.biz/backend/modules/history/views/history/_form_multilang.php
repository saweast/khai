<?php
/**
 * Created by PhpStorm.
 * User: Kate
 * Date: 10.02.15
 * Time: 15:05
 * @var $model backend\modules\history\models\HistoryTranslate
 * @var $form yii\widgets\ActiveForm
 * @var $language string
 */
use yii\helpers\Html;
use dosamigos\tinymce\TinyMce;
?>

<div>
    <?= $form->field($model, 'text', [
        'template' => "{label}\n{input}\n{hint}\n{error}"
    ])->textInput(array(
        'name' => 'HistoryTranslate['.$language.'][text]',
        'id' => 'HistoryTranslate_'.$language.'_text' //must be unique because client validation failed
    )); ?>

</div>