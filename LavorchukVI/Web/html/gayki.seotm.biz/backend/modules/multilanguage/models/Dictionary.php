<?php

namespace backend\modules\multilanguage\models;

use Yii;
use common\components\MultilingualBehavior;

/**
 * This is the model class for table "dictionary".
 *
 * @property integer $id
 * @property string $category
 * @property string $message
 *
 * @property DictionaryTranslate[] $dictionaryTranslates
 */
class Dictionary extends \yii\db\ActiveRecord
{
    /**
     * @inheritdoc
     */
    public static function tableName()
    {
        return 'dictionary';
    }

    /**
     * @inheritdoc
     */
    public function rules()
    {
        return [
            [['category', 'message'], 'string']
        ];
    }

    /**
     * @inheritdoc
     */
    public function attributeLabels()
    {
        return [
            'id' => 'ID',
            'category' => 'Category',
            'message' => 'Message',
        ];
    }

    /**
     * @return \yii\db\ActiveQuery
     */
    public function getTranslate()
    {
        return $this->hasMany(DictionaryTranslate::className(), ['id' => 'id'])->indexBy('language');
    }

    public function getT()
    {
        return $this->hasOne(DictionaryTranslate::className(), ['id' => 'id'])->where(['language'=>Yii::$app->language]);
    }

    public function attachMultilangual()
    {
        $this->attachBehavior('ml', [
            'class' => MultilingualBehavior::className(),
            'relationClassName'=>DictionaryTranslate::className(),
            'langForeignKey' => 'id',
        ]);
    }
}
