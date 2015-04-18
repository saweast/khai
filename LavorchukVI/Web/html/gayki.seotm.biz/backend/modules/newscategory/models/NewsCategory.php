<?php

namespace backend\modules\newscategory\models;

use Yii;
//use creocoder\nestedsets\NestedSetsBehavior;
use common\components\MultilingualBehavior;
//use backend\modules\newsattach\components\AttachmentBehavior;
/**
 * This is the model class for table "news".
 *
 * @property integer $id
 * @property integer $is_main
 */
class NewsCategory extends \yii\db\ActiveRecord
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
        return 'news_category';
    }

    /**
     * @inheritdoc
     */
    public function rules()
    {
        return [
            [['show'], 'required'],
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
        return new NewsCategoryQuery(get_called_class());
    }

    /**
     * @return \yii\db\ActiveQuery
     */
    public function getTranslate()
    {
        return $this->hasMany(NewsCategoryTranslate::className(), ['id_item' => 'id'])->indexBy('language');
    }

    /**
     * @return \yii\db\ActiveQuery
     */
    public function getT()
    {
        return $this->hasOne(NewsCategoryTranslate::className(), ['id_item' => 'id'])->where(['language'=>Yii::$app->language]);
    }

    public function attachMultilangual()
    {
        $this->attachBehavior('ml', [
            'class' => MultilingualBehavior::className(),
            'relationClassName'=>NewsCategoryTranslate::className(),
            'langForeignKey' => 'id_item',
        ]);
    }

}
