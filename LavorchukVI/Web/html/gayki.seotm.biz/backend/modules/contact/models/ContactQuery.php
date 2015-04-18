<?php
/**
 * Created by PhpStorm.
 * User: max
 * Date: 10.02.15
 * Time: 11:31
 */
namespace backend\modules\contact\models;
//use creocoder\nestedsets\NestedSetsQueryBehavior;

class ContactQuery extends \yii\db\ActiveQuery
{
    public function behaviors() {
        return [
//            NestedSetsQueryBehavior::className(),
        ];
    }
}