<?php

use yii\helpers\Html;
use backend\modules\newsattach\widgets\FileUploadWidget;
use backend\modules\newsattach\widgets\FileWidget;
/* @var $this yii\web\View */
/* @var $model backend\modules\news\models\News */

$this->title = 'Редактирование Новости: ';
$this->params['breadcrumbs'][] = ['label' => 'Новости', 'url' => ['index']];
$this->params['breadcrumbs'][] = 'Редактирование';
?>
<div class="news-update">

    <h1><?= Html::encode($this->title) ?></h1>

    <?= $this->render('_form', [
        'model' => $model,
    ]) ?>
    <h4><?=Yii::t('backend', 'Загруженные изображения')?></h4>
    <?=FileWidget::widget();?>
    <?php $filesToken = sha1(uniqid(mt_rand(),true));?>
    <h4>Загрузка изображений</h4>
    <?php
    $entity = 'News';
    $webroot = Yii::getAlias('@img_root');
    ?>
    <?=FileUploadWidget::widget(array(
        'entity'=>$entity,
        'entity_id'=>$model->id,
        'entity_relation_name'=>'id',
        'versions'=>array('small','thumbnail',''),
        'fileTypes'=>array('png', 'jpeg', 'jpg'),
        'formName'=>'message',
        'tempUrl'=>$webroot.'/uploads/tmp/'.$filesToken.DIRECTORY_SEPARATOR,
        'uploadUrl'=>$webroot.'/uploads/',
        'webTmp'=>'/uploads/tmp/'.$filesToken.DIRECTORY_SEPARATOR,
        'webUrl'=>'/uploads/',
        'filePath'=>$webroot.'/uploads/'.$entity.DIRECTORY_SEPARATOR.$model->id.DIRECTORY_SEPARATOR,
    ))?>
</div>
