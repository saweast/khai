<?php

namespace backend\modules\newscategory\models;

use Yii;

/**
 * This is the model class for table "news_translate".
 *
 * @property integer $id
 * @property integer $id_item
 * @property string $language
 * @property string $name
 */
class NewsCategoryTranslate extends \yii\db\ActiveRecord
{

    /**
     * @inheritdoc
     */
    public static function tableName()
    {
        return 'news_category_translate';
    }

    /**
     * @inheritdoc
     */
    public function rules()
    {
        return [
            [[], 'required'],
            [['id_item'], 'required', 'on'=>'ownerUpdate'], // cause of on Owner create on beforeValidate we dont know id_item, dont push it to required on insert
            [['id', 'id_item'], 'integer'],
            [['name'], 'string', 'max' => 255],
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
            'name' => 'Имя',
        ];
    }
}
