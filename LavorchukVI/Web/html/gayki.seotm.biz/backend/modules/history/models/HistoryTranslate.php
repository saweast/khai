<?php

namespace backend\modules\history\models;

use Yii;

/**
 * This is the model class for table "history_translate".
 *
 * @property integer $id
 * @property integer $id_item
 * @property string $language
 * @property string $name
 */
class HistoryTranslate extends \yii\db\ActiveRecord
{

    /**
     * @inheritdoc
     */
    public static function tableName()
    {
        return 'history_translate';
    }

    /**
     * @inheritdoc
     */
    public function rules()
    {
        return [
            [['text'], 'required'],
            [['id_item'], 'required', 'on'=>'ownerUpdate'], // cause of on Owner create on beforeValidate we dont know id_item, dont push it to required on insert
            [['id', 'id_item'], 'integer'],
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
            'text' => 'Описание',
        ];
    }
}
