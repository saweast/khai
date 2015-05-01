<?php

use yii\helpers\Html;
use backend\modules\historyattach\widgets\FileUploadWidget;

/* @var $this yii\web\View */
/* @var $model backend\modules\history\models\History */
$this->title = 'Создание Истории';
$this->params['breadcrumbs'][] = ['label' => 'Истории', 'url' => ['index']];
$this->params['breadcrumbs'][] = $this->title;
?>
<div class="history-create">

    <h1><?= Html::encode($this->title) ?></h1>

    <?= $this->render('_form', [
        'model' => $model,
    ]) ?>

</div>
