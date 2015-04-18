<?php
/**
 * Created by PhpStorm.
 * User: max
 * Date: 20.02.15
 * Time: 14:45
 */
/* @var $this yii\web\View */
/* @var $model backend\modules\page\models\Page */
/* @var $page_service backend\modules\page\models\Page */
/* @var $page_service_children backend\modules\page\models\Page */
use yii\helpers\VarDumper;
use yii\helpers\Html;
$this->title=$model->t->seo_title?$model->t->seo_title:$model->t->name;
$this->registerMetaTag(['content'=>$model->t->seo_descr,'name'=>'description']);
$this->registerMetaTag(['content'=>$model->t->seo_keywords,'name'=>'keywords']);
?>
<div class="main_page_content">
    <?php if($model->img){?>
    <div class="main_img">
        <?=Html::img(Yii::getAlias('/uploads/'.\yii\helpers\StringHelper::basename(get_class($model)).'/'.$model->id.'/'.$model->img))?>
    </div>
    <?php }?>
    <div class="page_title">
        <div class="container">
            <span><?=$page_service->t->title?></span>
        </div>
    </div>
    <div class="container">
        <div class="main_page_services container">
            <?php
            foreach($page_service_children as $service){
                ?>
                <div class="one_service_main">
                    <?=Html::a('<span>'.$service->t->name.'</span>',Yii::$app->urlManager->createUrl($service->translit, ['language'=>Yii::$app->language]),['class'=>'one_service_main_container']);?>
                </div>
                <?php
            }
            ?>
        </div>
    </div>
    <div class="page_title">
        <div class="container">
            <span><?=$model->t->title?></span>
        </div>
    </div>
    <div class="container">
        <div class="text_content_main">
            <?=$model->t->text;?>
        </div>
    </div>
    <div class="title_advantages">
            <div class="container">
                <span><?=Yii::t('frontend','advantages')?></span>
            </div>
    </div>
    <div class="main_page_advantages">
        <div class="container">
            <div class="first_cube cubs">
                <div class="cube_label label_cube_first">
                    <?=Yii::t('frontend','speed')?>
                </div>
                <div id="first_cube">
                    <div id="first_part">

                    </div>
                    <div id="second_part">

                    </div>
                    <div id="third_part">

                    </div>
                </div>
                <div class="first_shadow">

                </div>
            </div>
            <div class="second_cube cubs">
                <div class="cube_label label_cube_second">
                    <?=Yii::t('frontend','quality')?>
                </div>
                <div id="second_cube">
                    <div id="first_part">

                    </div>
                    <div id="second_part">

                    </div>
                </div>
                <div class="second_shadow">

                </div>
            </div>
            <div class="third_cube cubs">
                <div class="cube_label label_cube_third">
                    <?=Yii::t('frontend','safety')?>
                </div>
                <div id="third_cube">
                    <div id="first_part">

                    </div>
                    <div id="second_part">

                    </div>
                    <div id="third_part">

                    </div>
                </div>
                <div class="third_shadow">

                </div>
            </div>
        </div>
        <div class="main_page_advantages_1">
        </div>
        <div class="main_page_advantages_2">
        </div>
    </div>
    <div class="main_page_video">
        <div class="container">
            <div class="main_video">
                <?=$model->t->video;?>
            </div>
        </div>
    </div>
<!--    <div class="title_contact">-->
<!--        <div class="container">-->
<!--            <span>--><?//=Yii::t('frontend','how_to_find_us')?><!--</span>-->
<!--        </div>-->
<!--    </div>-->
<!--    --><?php //if($map){
//        ?>
<!--        <div class="main_page_map">-->
<!--            <div class="map_disabled"></div>-->
<!--            --><?//=$map->t->map?>
<!--        </div>-->
<!--    --><?php
//    }?>
</div>