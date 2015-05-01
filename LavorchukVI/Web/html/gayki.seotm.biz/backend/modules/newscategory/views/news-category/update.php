<?php

use yii\helpers\Html;
use backend\modules\attach\widgets\FileUploadWidget;
use backend\modules\attach\widgets\FileWidget;
/* @var $this yii\web\View */
/* @var $model backend\modules\news\models\NewsCategory */

$this->title = 'Редактирование Категории Новостей: ';
$this->params['breadcrumbs'][] = ['label' => 'Категория Новостей', 'url' => ['index']];
$this->params['breadcrumbs'][] = 'Редактирование';
?>
<div class="news-update">

    <h1><?= Html::encode($this->name) ?></h1>

    <?= $this->render('_form', [
        'model' => $model,
    ]) ?>

</div>
