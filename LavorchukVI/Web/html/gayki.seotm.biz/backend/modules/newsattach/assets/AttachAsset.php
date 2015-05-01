<?php
/**
 * Created by PhpStorm.
 * User: max
 * Date: 16.02.15
 * Time: 15:47
 */
namespace backend\modules\newsattach\assets;

use yii\web\AssetBundle;

/**
 * Single upload asset bundle.
 */
class AttachAsset extends AssetBundle
{
    /**
     * @inheritdoc
     */
    public $sourcePath = '@img_root/backend/modules/newsattach/assets';

    /**
     * @inheritdoc
     */
    public $css = [
        'css/blueimp-gallery.min.css',
        'css/jquery.fileupload.css',
        'css/jquery.fileupload-ui.css',
    ];

    /**
     * @inheritdoc
     */
    public $js = [
        'js/vendor/jquery.ui.widget.js',
        'js/tmpl.min.js',
        'js/load-image.min.js',
        'js/canvas-to-blob.min.js',
        'js/bootstrap.min.js',
        'js/jquery.blueimp-gallery.min.js',
        'js/jquery.iframe-transport.js',
        'js/jquery.fileupload.js',
        'js/jquery.fileupload-process.js',
        'js/jquery.fileupload-image.js',
        'js/jquery.fileupload-audio.js',
        'js/jquery.fileupload-video.js',
        'js/jquery.fileupload-validate.js',
        'js/jquery.fileupload-ui.js',
        'js/main.js',
        'js/main2.js',
        'js/cors/jquery.xdr-transport.js',
    ];
    
    /**
     * @inheritdoc
     */
    public $depends = [
    ];
}
