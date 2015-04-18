<?php
namespace backend\modules\newsattach;

class Attachment extends \yii\base\Module
{

    public $controllerNamespace = 'backend\modules\newsattach\controllers';

    public function init()
    {
        parent::init();

        // custom initialization code goes here
    }

//	public function init()
//	{
//		// this method is called when the module is being created
//		// you may place code here to customize the module or the application
//
//		// import the module-level models and components
//		$this->setImport(array(
//			'newsattach.models.*',
//			'newsattach.components.*',
//		));
//	}
//
//	public function beforeControllerAction($controller, $action)
//	{
//		if(parent::beforeControllerAction($controller, $action))
//		{
//			// this method is called before any module controller action is performed
//			// you may place customized code here
//			return true;
//		}
//		else
//			return false;
//	}

}
