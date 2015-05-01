<?php

namespace backend\modules\news\models;

use Yii;
//use creocoder\nestedsets\NestedSetsBehavior;
use common\components\MultilingualBehavior;
use backend\modules\newsattach\components\AttachmentBehavior;
/**
 * This is the model class for table "news".
 *
 * @property integer $id
 * @property integer $is_main
 */
class News extends \yii\db\ActiveRecord
{
    public function behaviors()
    {
        return [
            'AttachmentBehavior'=>[
                'class' => AttachmentBehavior::className(),
                'entity_id'=>$this->id,
                'upload_path'=>Yii::getAlias('@img_root').'/uploads/',
            ],
        ];
    }

    /**
     * @inheritdoc
     */
    public static function tableName()
    {
        return 'news';
    }

    /**
     * @inheritdoc
     */
    public function rules()
    {
        return [
            [['show','category_id','date'], 'required'],
            ['date', 'date', 'format' => 'dd-MM-yyyy'],
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
            'category_id' => 'Категория',
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
        return new NewsQuery(get_called_class());
    }

    /**
     * @return \yii\db\ActiveQuery
     */
    public function getTranslate()
    {
        return $this->hasMany(NewsTranslate::className(), ['id_item' => 'id'])->indexBy('language');
    }

    /**
     * @return \yii\db\ActiveQuery
     */
    public function getT()
    {
        return $this->hasOne(NewsTranslate::className(), ['id_item' => 'id'])->where(['language'=>Yii::$app->language]);
    }

    public function attachMultilangual()
    {
        $this->attachBehavior('ml', [
            'class' => MultilingualBehavior::className(),
            'relationClassName'=>NewsTranslate::className(),
            'langForeignKey' => 'id_item',
        ]);
    }

}
