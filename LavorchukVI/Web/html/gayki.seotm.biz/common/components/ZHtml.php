<?php
/**
 * Created by PhpStorm.
 * User: Kate
 * Date: 11.02.15
 * Time: 9:23
 */
namespace common\components;

use Yii;
use yii\helpers\VarDumper;

class ZHtml extends \yii\helpers\Html
{
    public static function activeTextInput($model, $attribute, $options = [])
    {
        if(empty($options['language']))
            $options['language'] = Yii::$app->language;
        $options['name'] = self::pullClassName(get_class($model)) . '[' . $options['language'] . '][' . $attribute . ']';
        return parent::activeTextInput($model, $attribute, $options);
    }

    public static function enumDropDownList($model, $attribute, $htmlOptions = [])
    {
        return self::activeDropDownList( $model, $attribute, self::enumItem($model,  $attribute), $htmlOptions);
    }

    public static function enumItem($model,$attribute) {
        $attr=$attribute;
        preg_match('/\((.*)\)/',$model->tableSchema->columns[$attr]->dbType, $matches);
        foreach(explode(',', $matches[1]) as $value) {
            $value=str_replace("'",null,$value);
            $values[$value] = \Yii::t('app', $value);
        }
        return $values;
    }

    public static function pullClassName($name)
    {
        return @end(explode('\\', $name));
    }
}