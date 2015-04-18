<?php

namespace backend\modules\news\models;

use Yii;

/**
 * This is the model class for table "news_translate".
 *
 * @property integer $id
 * @property integer $id_item
 * @property string $language
 * @property string $name
 */
class NewsTranslate extends \yii\db\ActiveRecord
{

    /**
     * @inheritdoc
     */
    public static function tableName()
    {
        return 'news_translate';
    }

    /**
     * @inheritdoc
     */
    public function rules()
    {
        return [
            [['title'], 'required'],
            [['id_item'], 'required', 'on'=>'ownerUpdate'], // cause of on Owner create on beforeValidate we dont know id_item, dont push it to required on insert
            [['id', 'id_item'], 'integer'],
            [['title'], 'string', 'max' => 255],
            [['text'], 'string'],
        ];
    }

    /**
     * @inheritdoc
     */
    public function attributeLabels()
    {
        return [
            'id' => 'Ид',
            'id_item' => 'Id Item',
            'language' => 'Language',
            'title' => 'Заголовок',
            'text' => 'Текст',
        ];
    }
}
