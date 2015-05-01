<?php

use yii\helpers\Html;


/* @var $this yii\web\View */
/* @var $model backend\modules\multilanguage\models\DictionaryTranslate */

$this->title = 'Create Dictionary Translate';
$this->params['breadcrumbs'][] = ['label' => 'Dictionary Translates', 'url' => ['index']];
$this->params['breadcrumbs'][] = $this->title;
?>
<div class="dictionary-translate-create">

    <h1><?= Html::encode($this->title) ?></h1>

    <?= $this->render('_form', [
        'model' => $model,
    ]) ?>

</div>
