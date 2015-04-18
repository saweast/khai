<?php
use yii\helpers\Html;
use yii\bootstrap\Nav;
use yii\bootstrap\NavBar;
use yii\widgets\Breadcrumbs;
use frontend\assets\AppAsset;
use frontend\widgets\MenuWidget;
/* @var $this \yii\web\View */
/* @var $content string */

AppAsset::register($this);
?>
<?php $this->beginPage() ?>
<!DOCTYPE html>
<html lang="<?= Yii::$app->language ?>">
<head>
    <meta charset="<?=Yii::$app->charset ?>"/>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link href='http://fonts.googleapis.com/css?family=Open+Sans' rel='stylesheet' type='text/css'>
    <?= Html::csrfMetaTags() ?>
    <title><?= Html::encode($this->title) ?></title>
    <?php $this->head() ?>
</head>
<body>
    <?php $this->beginBody() ?>
    <div class="wrap">
        <div class="header_container">
            <div class="container header">
                    <?=Html::a('',Yii::$app->urlManager->createUrl('', ['language'=>Yii::$app->language]),['class'=>'header_logo'])?>
                <div class="header_menu">
                    <?=MenuWidget::widget();?>
                </div>
                <div class="header_languages">
                    <?php foreach(Yii::$app->params['languages'] as $key=>$lang){
                        if($key == Yii::$app->language){
                            ?>
                            <span><div class="one_lang"><?=$lang['lang']?></div></span>
                            <?php
                        }else{
                            ?>
                            <span><?=Html::a($lang['lang'],Yii::$app->urlManager->createUrl(Yii::$app->request->url, ['language'=>$key]))?></span>
                            <?php
                        }
                    }?>
                </div>
            </div>
        </div>
            <?= $content ?>

    </div>
    <footer class="footer_container">
        <div class="footer_menu">
            <div class="container">
                <?=MenuWidget::widget();?>
            </div>
        </div>
        <div class="container footer">
        <p class="pull-left">&copy; <?=Yii::t('frontend','seotm')?> <?=Html::a('Seotm.com','http://seotm.com/')?></p>
        <p class="pull-right">
            <?php foreach(Yii::$app->params['languages'] as $key=>$lang){
                if($key == Yii::$app->language){
                    ?>
                    <span><?=$lang['lang']?></span>
                <?php
                }else{
                    ?>
                    <?=Html::a($lang['lang'],Yii::$app->urlManager->createUrl(Yii::$app->request->url, ['language'=>$key]))?>
                <?php
                }
            }?></p>
        </div>
    </footer>

    <?php $this->endBody() ?>
</body>
</html>
<?php $this->endPage() ?>
