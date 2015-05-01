<?php

namespace backend\modules\contact\models;

use Yii;

/**
 * This is the model class for table "contact_translate".
 *
 * @property integer $id
 * @property integer $id_item
 * @property string $language
 * @property string $name
 */
class ContactTranslate extends \yii\db\ActiveRecord
{

    /**
     * @inheritdoc
     */
    public static function tableName()
    {
        return 'contact_translate';
    }

    /**
     * @inheritdoc
     */
    public function rules()
    {
        return [
            [['name'], 'required'],
            [['id_item'], 'required', 'on'=>'ownerUpdate'], // cause of on Owner create on beforeValidate we dont know id_item, dont push it to required on insert
            [['id', 'id_item'], 'integer'],
            [['email','name','phone','address','language'], 'string', 'max' => 255],
            ['email','email'],
            [['map'], 'string']
        ];
    }

    /**
     * @inheritdoc
     */
    public function attributeLabels()
    {
        return [
            'id' => 'ID',
            'id_item' => 'Id Item',
            'language' => 'Language',
            'email' => 'Email',
            'phone' => 'Телефон',
            'address' => 'Адрес',
            'map' => 'Карта',
            'name'=>'Имя'
        ];
    }
}
