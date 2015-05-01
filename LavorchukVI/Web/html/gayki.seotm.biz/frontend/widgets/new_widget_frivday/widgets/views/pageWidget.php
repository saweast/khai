<?php
/**
 * Created by PhpStorm.
 * User: Kate
 * Date: 19.02.15
 * Time: 12:11
 * @var $this backend\widgets\PageWidget
 * @var $name string
 * @var $categories array
 */
use yii\helpers\Html;
use yii\helpers\VarDumper;
//use backend\widgets\assets\CatSelAsset;
//CatSelAsset::register($this);
$this->registerJsFile('/backend/js/pageSelect.js');
?>
<div class="row">
    <?php if($model !== null):?>
        <?= Html::activeHiddenInput($model, $attribute, [
            'id'=>'pageSelect'
        ])?>
    <?php endif; ?>
    <div class="page-select-widget col-sm-3">
        <?=Html::dropDownList($name, null, $categories, [
                'class'=>'form-control page-select',
                'data-no_id'=>$no_id,
                'prompt'=>'Выберите категорию']
        );?>
    </div>
</div>