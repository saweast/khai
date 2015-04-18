<?php

use yii\helpers\Html;
use backend\modules\attach\widgets\FileUploadWidget;

/* @var $this yii\web\View */
/* @var $model backend\modules\news\models\NewsCategory */
$this->title = 'Создание Категории Новости';
$this->params['breadcrumbs'][] = ['label' => 'Категории Новостей', 'url' => ['index']];
$this->params['breadcrumbs'][] = $this->title;
?>
<div class="news-create">

    <h1><?= Html::encode($this->title) ?></h1>

    <?= $this->render('_form', [
        'model' => $model,
    ]) ?>
</div>
