<?php

use yii\helpers\Html;
use backend\modules\attach\widgets\FileUploadWidget;

/* @var $this yii\web\View */
/* @var $model backend\modules\page\models\Page */
$this->title = 'Create Page';
$this->params['breadcrumbs'][] = ['label' => 'Pages', 'url' => ['index']];

if(isset($parent_id) && $parent_id)
{
    $parent = $model->findOne($parent_id);
    $parents = $parent->parents()->all();
    $parents[]=$parent;
    foreach($parents as $parent){
        if($parent->left!='1')
        $this->params['breadcrumbs'][]=['label' => $parent->t->name, 'url' => ['index', 'parent_id' => $parent->id]];
    }
}
$this->params['breadcrumbs'][] = $this->title;
?>
<div class="page-create">

    <h1><?= Html::encode($this->title) ?></h1>

    <?= $this->render('_form', [
        'model' => $model,
        'parent_id' => $parent_id
    ]) ?>
    <?php $filesToken = sha1(uniqid(mt_rand(),true));?>
    <h4>Загрузка изображений</h4>
    <?php
    $entity = 'Page';
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
