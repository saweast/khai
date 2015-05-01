<?php
use backend\assets\AppAsset;
use yii\helpers\Html;
use yii\bootstrap\Nav;
use yii\bootstrap\NavBar;
use yii\widgets\Breadcrumbs;

/* @var $this \yii\web\View */
/* @var $content string */

AppAsset::register($this);
$module = Yii::$app->controller->module->id;
$controller = Yii::$app->controller->id;
$action = Yii::$app->controller->action->id;
?>
<?php $this->beginPage() ?>
<!DOCTYPE html>
<html lang="<?= Yii::$app->language ?>">
<head>
    <meta charset="<?= Yii::$app->charset ?>"/>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <?= Html::csrfMetaTags() ?>
    <title><?= Html::encode($this->title) ?></title>
    <?php $this->head() ?>
</head>
<body>
    <?php $this->beginBody() ?>
    <div id="wrapper">
        <nav class="navbar navbar-inverse navbar-fixed-top" role="navigation">
            <div class="navbar-header">
                <button type="button" class="navbar-toggle" data-toggle="collapse" data-target=".navbar-ex1-collapse">
                    <span class="sr-only">Toggle navigation</span>
                    <span class="icon-bar"></span>
                    <span class="icon-bar"></span>
                    <span class="icon-bar"></span>
                </button>
                <a class="navbar-brand" href="<?=Yii::$app->urlManager->createUrl('/')?>">Gayki Admin</a>
            </div>
            <div class="collapse navbar-collapse navbar-ex1-collapse">
                <ul class="nav navbar-nav side-nav">
                    <?php $nav = [
//                        'Динамические страницы' => Yii::$app->urlManager->createUrl('page/page/index'),
                        'Новости' => Yii::$app->urlManager->createUrl('news/news/index'),
                        'Категории Новостей' => Yii::$app->urlManager->createUrl('newscategory/news-category/index'),
                        'Наши Истории' => Yii::$app->urlManager->createUrl('history/history/index'),
                        'Контакты' => Yii::$app->urlManager->createUrl('contact/contact/index'),
                        'Управление Переводами' => Yii::$app->urlManager->createUrl('multilanguage/dictionary/index'),
                    ];?>
                    <?php foreach($nav as $k=>$v):
                        $elems = explode('/', str_replace('/backend/', '', $v));
                        $class = '';
                        switch (count($elems))
                        {
                            case 1:
                                if($elems[0] == $module)
                                    $class = 'active';
                                break;
                            case 2:
                                if($elems[0] == $module && $elems[1] == $controller)
                                    $class = 'active';
                                break;
                            case 3:
                                if($elems[0] == $module && $elems[1] == $controller)
                                    $class = 'active';
                                break;
                            default:
                                break;
                        }
                        ?>
                        <li class="<?=$class?>">
                            <a href="<?=$v?>"><?=$k?></a>
                        </li>
                    <?php endforeach; ?>
                </ul>
            </div>
        </nav>

        <div id="page-wrapper">
            <div class="container-fluid">
                <div class="row">
                    <?= Breadcrumbs::widget([
                        'links' => isset($this->params['breadcrumbs']) ? $this->params['breadcrumbs'] : [],
                    ]) ?>
                    <?= $content ?>
                </div>

            </div>
        </div>
    </div>

        <p class="pull-right"><?= Yii::powered() ?></p>

    <?php $this->endBody() ?>
</body>
</html>
<?php $this->endPage() ?>
