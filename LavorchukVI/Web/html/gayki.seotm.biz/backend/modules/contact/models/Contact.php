<?php

namespace backend\modules\contact\models;

use Yii;
//use creocoder\nestedsets\NestedSetsBehavior;
use common\components\MultilingualBehavior;
//use backend\modules\newsattach\components\AttachmentBehavior;
/**
 * This is the model class for table "contact".
 *
 * @property integer $id
 * @property integer $is_main
 */
class Contact extends \yii\db\ActiveRecord
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
        return 'contact';
    }

    /**
     * @inheritdoc
     */
    public function rules()
    {
        return [
            [['is_main','show'], 'required'],
        ];
    }

    /**
     * @inheritdoc
     */
    public function attributeLabels()
    {
        return [
            'id' => 'ID',
            'is_main' => 'Главные контакты',
            'show'=>'Отображать'
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
        return new ContactQuery(get_called_class());
    }

    /**
     * @return \yii\db\ActiveQuery
     */
    public function getTranslate()
    {
        return $this->hasMany(ContactTranslate::className(), ['id_item' => 'id'])->indexBy('language');
    }

    /**
     * @return \yii\db\ActiveQuery
     */
    public function getT()
    {
        return $this->hasOne(ContactTranslate::className(), ['id_item' => 'id'])->where(['language'=>Yii::$app->language]);
    }

    public function attachMultilangual()
    {
        $this->attachBehavior('ml', [
            'class' => MultilingualBehavior::className(),
            'relationClassName'=>ContactTranslate::className(),
            'langForeignKey' => 'id_item',
        ]);
    }

}
