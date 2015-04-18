<?php
/**
 * Created by PhpStorm.
 * User: chosen1
 * Date: 29.10.13
 * Time: 11:37
 */
namespace backend\modules\newsattach\widgets;
use yii\widgets\InputWidget;
use Yii;

class FileWidget extends InputWidget{

    public $formName = 'form';

    public function init()
    {

    }

    public function run()
    {
        return $this->render('fileWidget');
    }

}