<?php
/**
 * @var $this frontend\widgets\MenuWidget
 * @var $items backend\modules\page\models\Page;
 */
use yii\helpers\Html;
use yii\helpers\VarDumper;
if($items){
?>
    <menu>
        <?php
        foreach($items as $item){
            $children = $item->children(1)->all();
            $active = false;
            if(Yii::$app->urlManager->createUrl($item->translit)==Yii::$app->request->url){
                $active=true;
            }
            if(Yii::$app->urlManager->createUrl($item->translit).'/'==Yii::$app->request->url){
                $active=true;
            }
            if($children){
                foreach($children as $item_children){
                    if(Yii::$app->urlManager->createUrl($item_children->translit)==Yii::$app->request->url){
                        $active=true;
                    }
                    if(Yii::$app->urlManager->createUrl($item_children->translit).'/'==Yii::$app->request->url){
                        $active=true;
                    }
                }
            }
            ?>
            <li class="<?php
            if($active)
            {?>
            active real_active
            <?php }?>
            <?php if($children){
                ?>
                with_children
                <?php
            }?>">
                <?php if($children){
                    ?>
                    <span><?=$item->t->name?></span>
                    <menu>
                        <?php
                        foreach($children as $item_children){
                            ?>
                        <li>
                            <?=Html::a($item_children->t->name,Yii::$app->urlManager->createUrl($item_children->translit,['language'=>Yii::$app->language]))?>
                            <div class="menu_border_help"></div>
                        </li>
                        <?php
                        }
                        ?>
                    </menu>
                    <?php
                }else{
                    ?>
                    <?=Html::a($item->t->name,Yii::$app->urlManager->createUrl($item->translit,['language'=>Yii::$app->language]))?>
                <?php
                }?>
            </li>
            <?php
        }
        ?>
    </menu>
<?php
}
