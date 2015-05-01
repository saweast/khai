<?php

use yii\helpers\Html;
use backend\modules\attach\widgets\FileUploadWidget;
use backend\modules\attach\widgets\FileWidget;
/* @var $this yii\web\View */
/* @var $model backend\modules\contact\models\Contact */

$this->title = 'Редактирование Контакта: ';
$this->params['breadcrumbs'][] = ['label' => 'Contacts', 'url' => ['index']];
$this->params['breadcrumbs'][] = 'Редактирование';
?>
<div class="contact-update">

    <h1><?= Html::encode($this->title) ?></h1>

    <?= $this->render('_form', [
        'model' => $model,
    ]) ?>

</div>
