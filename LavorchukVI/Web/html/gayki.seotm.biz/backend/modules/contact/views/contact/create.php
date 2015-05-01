<?php

use yii\helpers\Html;
use backend\modules\attach\widgets\FileUploadWidget;

/* @var $this yii\web\View */
/* @var $model backend\modules\contact\models\Contact */
$this->title = 'Создать Контакт';
$this->params['breadcrumbs'][] = ['label' => 'Контакты', 'url' => ['index']];
$this->params['breadcrumbs'][] = $this->title;
?>
<div class="contact-create">

    <h1><?= Html::encode($this->title) ?></h1>

    <?= $this->render('_form', [
        'model' => $model,
    ]) ?>
</div>
