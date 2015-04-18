<?php

namespace backend\modules\history\models;

use Yii;
//use creocoder\nestedsets\NestedSetsBehavior;
use common\components\MultilingualBehavior;
/**
 * This is the model class for table "history".
 *
 * @property integer $id
 * @property integer $is_main
 */
class History extends \yii\db\ActiveRecord
{
    public function behaviors()
    {
        return [
        ];
    }

    /**
     * @inheritdoc
     */
    public static function tableName()
    {
        return 'history';
    }

    /**
     * @inheritdoc
     */
    public function rules()
    {
        return [
            [['show','date'], 'required'],
        ];
    }

    /**
     * @inheritdoc
     */
    public function attributeLabels()
    {
        return [
            'id' => 'Ид',
            'show' => 'Отображать',
            'date' => 'Дата',
        ];
    }

    public function transactions()
    {
        return [
            self::SCENARIO_DEFAULT => self::OP_ALL,
        ];
    }

    public static function find()
    {
        return new HistoryQuery(get_called_class());
    }

    /**
     * @return \yii\db\ActiveQuery
     */
    public function getTranslate()
    {
        return $this->hasMany(HistoryTranslate::className(), ['id_item' => 'id'])->indexBy('language');
    }

    /**
     * @return \yii\db\ActiveQuery
     */
    public function getT()
    {
        return $this->hasOne(HistoryTranslate::className(), ['id_item' => 'id'])->where(['language'=>Yii::$app->language]);
    }

    public function attachMultilangual()
    {
        $this->attachBehavior('ml', [
            'class' => MultilingualBehavior::className(),
            'relationClassName'=>HistoryTranslate::className(),
            'langForeignKey' => 'id_item',
        ]);
    }

}
