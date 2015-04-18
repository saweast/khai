<?php

use yii\helpers\Html;

/* @var $this yii\web\View */
/* @var $model backend\modules\multilanguage\models\DictionaryTranslate */

$this->title = 'Update Dictionary Translate: ' . ' ' . $model->id;
$this->params['breadcrumbs'][] = ['label' => 'Dictionary Translates', 'url' => ['index']];
$this->params['breadcrumbs'][] = ['label' => $model->id, 'url' => ['view', 'id' => $model->id]];
$this->params['breadcrumbs'][] = 'Update';
?>
<div class="dictionary-translate-update">

    <h1><?= Html::encode($this->title) ?></h1>

    <?= $this->render('_form', [
        'model' => $model,
    ]) ?>

</div>
