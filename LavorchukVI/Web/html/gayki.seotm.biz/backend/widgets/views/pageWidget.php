<?php
/**
 * Created by PhpStorm.
 * User: Kate
 * Date: 19.02.15
 * Time: 12:11
 * @var $this backend\widgets\PageWidget
 * @var $name string
 * @var $pages array
 */
use yii\helpers\Html;
use yii\helpers\VarDumper;
//use backend\widgets\assets\CatSelAsset;
//CatSelAsset::register($this);
$this->registerJsFile('/backend/js/pageSelect.js');
?>
<div class="row">
    <?php if(!empty($id)): ?>
        <?php if(!empty($model)):?>
            <?= Html::activeHiddenInput($model, $attribute, [
                'id'=>'pageSelect',
                'value'=>$id,
            ])?>
        <?php endif; ?>
        <div class="page-select-widget col-sm-3">
            <?php foreach($pages as $k=>$val): ?>
                <?=Html::dropDownList($name, $selected[$k]->id, $val, [
                        'class'=>'form-control page-select',
                        'data-no_id'=>$no_id,
                        'prompt'=>'Выберите категорию']
                );?>
            <?php endforeach; ?>
        </div>
    <?php else: ?>
        <?php if($model !== null):?>
            <?= Html::activeHiddenInput($model, $attribute, [
                'id'=>'pageSelect'
            ])?>
        <?php endif; ?>
        <div class="page-select-widget col-sm-3">
            <?=Html::dropDownList($name, null, $pages, [
                    'class'=>'form-control page-select',
                    'data-no_id'=>$no_id,
                    'prompt'=>'Выберите категорию']
            );?>
        </div>
    <?php endif; ?>
</div>