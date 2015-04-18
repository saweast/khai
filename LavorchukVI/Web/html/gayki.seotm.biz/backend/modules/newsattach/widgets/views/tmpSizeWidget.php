<div class="well span2" style="text-align: center">
    <div id='chart_div'></div>
    <?php echo CHtml::link(Yii::t('backend','Очистить'),$clearAction,array(
        'class'=>'btn',
        'id'=>'chart-btn',
        'data-maxsize'=>$maxSize,
        'data-current'=>$size,
        'data-tmp'=>$tmp,
    ))?>
    <h5 class="page-header"><?=Yii::t('backend',$title).$size.' Mb'?></h5>
</div>


