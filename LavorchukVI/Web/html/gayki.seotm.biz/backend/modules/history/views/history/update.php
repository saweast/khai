<?php

use yii\helpers\Html;
use backend\modules\historyattach\widgets\FileUploadWidget;
use backend\modules\historyattach\widgets\FileWidget;
/* @var $this yii\web\View */
/* @var $model backend\modules\history\models\History */

$this->title = 'Редактирование Истории: ';
$this->params['breadcrumbs'][] = ['label' => 'Истории', 'url' => ['index']];
$this->params['breadcrumbs'][] = 'Редактирование';
?>
<div class="history-update">

    <h1><?= Html::encode($this->title) ?></h1>

    <?= $this->render('_form', [
        'model' => $model,
    ]) ?>

</div>
