<?php

namespace backend\modules\multilanguage\models;

use Yii;

/**
 * This is the model class for table "dictionary_translate".
 *
 * @property integer $id
 * @property string $language
 * @property string $translation
 *
 * @property Dictionary $id0
 */
class DictionaryTranslate extends \yii\db\ActiveRecord
{
    /**
     * @inheritdoc
     */
    public static function tableName()
    {
        return 'dictionary_translate';
    }

    /**
     * @inheritdoc
     */
    public function rules()
    {
        return [
            [['language'], 'required'],
            [['id'], 'required', 'on'=>'update'],
            [['id'], 'integer'],
            [['translation'], 'string'],
            [['language'], 'string', 'max' => 16]
        ];
    }

    /**
     * @inheritdoc
     */
    public function attributeLabels()
    {
        return [
            'id' => 'ID',
            'language' => 'Language',
            'translation' => 'Translation',
        ];
    }

    /**
     * @return \yii\db\ActiveQuery
     */
    public function getId0()
    {
        return $this->hasOne(Dictionary::className(), ['id' => 'id']);
    }
}
