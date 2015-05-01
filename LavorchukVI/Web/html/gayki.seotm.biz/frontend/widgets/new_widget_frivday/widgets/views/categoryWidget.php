<?php
/**
 * Created by PhpStorm.
 * User: Kate
 * Date: 19.02.15
 * Time: 12:11
 * @var $this backend\widgets\CategoryWidget
 * @var $name string
 * @var $categories array
 */
use yii\helpers\Html;
use yii\helpers\VarDumper;
//use backend\widgets\assets\CatSelAsset;
//CatSelAsset::register($this);
$this->registerJsFile('/backend/js/categorySelect.js');
?>
<div class="row">
    <?php if(!empty($id)): ?>
        <?php if(!empty($model)):?>
            <?= Html::activeHiddenInput($model, $attribute, [
                'id'=>'categorySelect',
                'value'=>$id,
            ])?>
            <?php endif; ?>
    <div class="category-select-widget col-sm-3">
        <?php foreach($categories as $k=>$val): ?>
            <?=Html::dropDownList($name, $selected[$k]->id, $val, [
                    'class'=>'form-control category-select',
                    'data-no_id'=>$no_id,
                    'prompt'=>'-Выберите категорию-']
            );?>
        <?php endforeach; ?>
    </div>
    <?php else: ?>
        <?php if($model !== null):?>
            <?= Html::activeHiddenInput($model, $attribute, [
                'id'=>'categorySelect'
            ])?>
        <?php endif; ?>
        <div class="category-select-widget col-sm-3">
            <?=Html::dropDownList($name, null, $categories, [
                    'class'=>'form-control category-select',
                    'data-no_id'=>$no_id,
                    'prompt'=>'-Выберите категорию-']
            );?>
        </div>
    <?php endif; ?>

</div>