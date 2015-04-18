<?php
/**
 * Created by PhpStorm.
 * User: Kate
 * Date: 10.02.15
 * Time: 16:12
 */
namespace common\components;

use Yii;
use yii\base\Behavior;
use yii\base\Exception;
use yii\base\InvalidConfigException;
use yii\db\ActiveQuery;
use yii\db\ActiveRecord;
use yii\helpers\VarDumper;
use yii\validators\Validator;

class MultilingualBehavior extends Behavior
{
    public $languages;
    public $relationClassName;
    public $langForeignKey;
    public $languageField = 'language';
    public $ownerPK;
    public $translatePK;
    public $scenarios = [ 'insert', 'update' ];

    public $translateModels = array();
    private $_noChecking;

    /**
     * @inheritdoc
     */

    // newsattach this behavior aftee model initialize
    // to get fully formed Owner (with scenarios etc)
    public function attach($owner)
    {
        parent::attach($owner);
        $this->configure();
        $this->initializeTranslateModels();
    }

    public function configure()
    {
        $className = $this->owner->className();
        $translateClassName = $this->relationClassName;

        $this->ownerPK = current($className::primaryKey());
        $this->translatePK = current($translateClassName::primaryKey());

        $this->_noChecking = [
            $this->languageField,
            $this->langForeignKey,
            $this->translatePK,
        ];
    }

    public function initializeTranslateModels()
    {
        if ($this->owner->isNewRecord) {
            $className = $this->relationClassName;
            foreach(Yii::$app->params['languages'] as $lang=>$info)
            {
                $this->translateModels[$lang] = new $className();
            }
        } else {
            $this->translateModels = array_merge($this->translateModels, $this->owner->translate);
        }
    }

    public function events()
    {
        return [
//            ActiveRecord::EVENT_AFTER_FIND => 'afterFind',
//            ActiveRecord::EVENT_INIT => 'afterInit',
            ActiveRecord::EVENT_AFTER_UPDATE => 'afterUpdate',
            ActiveRecord::EVENT_AFTER_INSERT => 'afterInsert',
            ActiveRecord::EVENT_AFTER_DELETE => 'afterDelete',
            ActiveRecord::EVENT_BEFORE_VALIDATE => 'beforeValidate',
        ];
    }

//    public function afterFind()
//    {
//            if (!$this->owner->isNewRecord) {
//                $this->translateModels = array_merge($this->translateModels, $this->owner->translate);
//            }
//    }

//    public function afterInit()
//    {
//        if ($this->owner->isNewRecord) {
//            $className = $this->relationClassName;
//            foreach(Yii::$app->params['languages'] as $lang=>$info)
//            {
//                $this->translateModels[$lang] = new $className();
//            }
//        }
//    }

    public function beforeValidate()
    {
//        if(in_array($this->owner->scenario, $this->scenarios))
        {
            $isValid = true;
            $isFilled = false;

            $className = $this->prepareClassName($this->relationClassName);

            foreach(Yii::$app->params['languages'] as $lang=>$info)
            {
                // fill data
                $this->translateModels[$lang]->load([$className => $_POST[$className][$lang]]); // lets put array like $_POST have to be - [ PostTranslate => [ ru => [ name => "name1" ] ] ]
                $this->translateModels[$lang]->{$this->languageField} = $lang;

                $count = 0;
                foreach($this->translateModels[$lang]->attributes as $key=>$value)
                {
                    if(in_array($key, $this->_noChecking))
                    {
                        continue;
                    }
                    if(!empty($value))
                    {
                        $count++;
                    }
                }
                if($count === 0)
                {
                    $isFilled |= false;
                }
                else
                {
                    $res = $this->translateModels[$lang]->validate();
                    $isValid &= $res;
                    $isFilled = true; // if there is at least one filled translation
                }
            }

            if(!$isFilled)
            {
                $this->owner->addError('translateModels','Заполните хотя бы одно мультиязычное поле');
            }
            if(!$isValid)
            {
                $this->owner->addError('translateModels', 'Исправьте ошибки в мультиязычных полях');
            }
        }

        return true;
    }

    public function afterInsert()
    {
//        if(in_array($this->owner->scenario, $this->scenarios))
            $this->_saveTranslations();
    }

    public function afterUpdate()
    {
//        if(in_array($this->owner->scenario, $this->scenarios))
            $this->_saveTranslations();
    }

    public function afterDelete()
    {
        foreach($this->translateModels as $model)
            $model->delete();
    }

    private function _saveTranslations()
    {
        foreach($this->translateModels as &$model)
        {
            $model->{$this->langForeignKey} = $this->owner->{$this->ownerPK};
            $model->save(false);
        }
        return true;
    }

    private function prepareClassName($name)
    {
        return @end(explode('\\', $name));
    }
}