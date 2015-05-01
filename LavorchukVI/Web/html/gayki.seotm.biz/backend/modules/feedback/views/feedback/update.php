<?php

use yii\helpers\Html;
use backend\modules\attach\widgets\FileUploadWidget;
use backend\modules\attach\widgets\FileWidget;
/* @var $this yii\web\View */
/* @var $model backend\modules\feedback\models\Feedback */

$this->title = 'Update Feedback: ';
$this->params['breadcrumbs'][] = ['label' => 'Feedbacks', 'url' => ['index']];
$this->params['breadcrumbs'][] = 'Update';
?>
<div class="feedback-update">

    <h1><?= Html::encode($this->title) ?></h1>

    <?= $this->render('_form', [
        'model' => $model,
    ]) ?>

</div>
