<?php
/**
 * Created by PhpStorm.
 * User: max
 * Date: 20.02.15
 * Time: 14:59
 */
/* @var $this yii\web\View */
/* @var $model backend\modules\page\models\Page */
/* @var $contacts backend\modules\contact\models\Contact */
/* @var $main_page backend\modules\page\models\Page */
use yii\helpers\Html;
use yii\helpers\BaseJson;
use yii\helpers\VarDumper;
$this->title=$model->t->seo_title?$model->t->seo_title:$model->t->name;
$this->registerMetaTag(['content'=>$model->t->seo_descr,'name'=>'description']);
$this->registerMetaTag(['content'=>$model->t->seo_keywords,'name'=>'keywords']);
?>
<div class="container">
    <div class="breadcrumbs">
        <?=\yii\helpers\Html::a($main_page->t->name,
            Yii::$app->urlManager->createUrl($main_page->translit,
                [
                    'language'=>Yii::$app->language
                ]))?> > <span><?=$model->t->name?></span>
    </div>
</div>
<div class="page_title">
    <div class="container">
        <span><?=$model->t->title?$model->t->title:$model->t->name?></span>
    </div>
</div>
<div class="page_content_bg">
    <?php if($contacts){
        foreach($contacts as $key=>$contact){
        ?>
        <div class="container">
            <div class="one_contact_container">
            <div class="pull-left contact_div">
                <div class="contact_address">
                    <span><?=$contact->t->country?></span>
                    <span><?=$contact->t->state?></span>
                    <span><?=$contact->t->city?></span>
                    <span><?=$contact->t->address?></span>
                </div>
            </div>
            <div class="pull-left contact_div">
                <div class="contact_phone">
                    <?php
                    $phones = explode(';',$contact->t->phone);
                    foreach($phones as $phone){
                        ?>
                    <span><?=$phone;?></span>
                    <?php
                    }
                    ?>
                </div>
                <div class="contact_email">
                    <?php
                    $emails = explode(';',$contact->t->email);
                    foreach($emails as $email){
                        ?>
                        <span><?=$email;?></span>
                    <?php
                    }
                    ?>
                </div>
            </div>
            </div>
        </div>
            <?php if($contact->t->map){?>
            <div class="contact_map_container">
                <div class="map_hide">
                    <div class="container">
                        <div class="map_hide_container active" data-id="<?=$key?>">
                            <span><?=Yii::t('frontend','hide_map_directions')?></span>
                            <span><?=Yii::t('frontend','show_map_directions')?></span>
                            <div class="map_hide_button"></div>
                        </div>
                    </div>
                </div>
                <div class="contact_map active" data-id="<?=$key?>">
                    <div class="map_disabled"></div>
                    <?=$contact->t->map?>
                </div>
            </div>
            <?php }?>
        <?php
        }?>
        <div class="page_title">
            <div class="container">
                <span><?=Yii::t('frontend','feedback')?></span>
            </div>
        </div>
            <div class="container">
                <div class="feedback">
                <div class="feedback_form">
                    <form action="/feedback/save/" method="post" id="feedback_form">
                        <div class="feedback_fields">
                            <div class="feedback_div">
                                <input name="name" type="text" placeholder="<?=Yii::t('frontend','feedback_name')?>" id="feedback_name"/>
                                <span><?=Yii::t('frontend','validation_empty')?></span>
                                <input name="email" type="text" placeholder="E-<?=Yii::t('frontend','feedback_email')?>" id="feedback_email"/>
                                <span><?=Yii::t('frontend','validation_empty')?></span>
                                <span style="display:none;"><?=Yii::t('frontend','validation_email')?></span>
                            </div>
                            <div class="feedback_div">
                                <textarea name="text" placeholder="<?=Yii::t('frontend','feedback_text')?>" id="feedback_text"></textarea>
                                <span><?=Yii::t('frontend','validation_empty')?></span>
                            </div>
                        </div>
                        <div class="feedback_submit">
                            <div class="result_submit">
                                <span class="result_success"><?=Yii::t('frontend','feedback_success')?></span>
                                <span class="result_fail"><?=Yii::t('frontend','feedback_fail')?></span>
                            </div>
                            <input type="submit" value="<?=Yii::t('frontend','feedback_send')?>">
                        </div>
                    </form>
                </div>
                </div>
            </div>
        <?php
    }else{
        ?>
        <div class="container page_content">
            <?php if($model->img){?>
                <div class="page_img">
                    <?=Html::img(Yii::getAlias('/uploads/'.\yii\helpers\StringHelper::basename(get_class($model)).'/'.$model->id.'/'.$model->img))?>
                </div>
            <?php }?>
            <?php if($model->t->text){
                ?>
                <div class="text_content">
                    <?=$model->t->text?>
                </div>
            <?php
            }?>
            <?php if($model->attach){
                ?>
                <div class="page_attach">
                    <?php
                    foreach($model->attach as $attach){
                        $link=$attach->links?BaseJson::decode($attach->links)[Yii::$app->language]:'';
                        $description=$attach->description?BaseJson::decode($attach->description)[Yii::$app->language]:'';
                        ?>
                        <div class="one_attach">
                            <div class="one_attach_img">
                                <div>
                                    <?php if($link){ ?>
                                        <?=Html::a(Html::img(Yii::getAlias('/uploads/'.\yii\helpers\StringHelper::basename(get_class($model)).'/'.$model->id.'/small/'.$attach->path)),$link,['target'=>'_blank']);?>
                                    <?php } else{ ?>
                                        <?=Html::img(Yii::getAlias('/uploads/'.\yii\helpers\StringHelper::basename(get_class($model)).'/'.$model->id.'/small/'.$attach->path));?>
                                    <?php } ?>
                                </div>
                            </div>
                            <div class="one_attach_text">
                                <span><?=$description?></span>
                            </div>
                        </div>
                    <?php
                    }?>
                </div>
            <?php
            }?>
        </div>
    <?php
    }?>

</div>