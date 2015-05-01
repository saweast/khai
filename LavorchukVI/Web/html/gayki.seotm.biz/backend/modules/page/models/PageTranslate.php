<?php

namespace backend\modules\page\models;

use Yii;

/**
 * This is the model class for table "pageTranslate".
 *
 * @property integer $id
 * @property integer $id_item
 * @property string $name
 * * @property string $seo_title
 * * @property string $seo_descr
 * * @property string $seo_keywords
 * @property string $title
 * @property string $text
 * @property string $img
 * @property string $video
 */
class PageTranslate extends \yii\db\ActiveRecord
{
    /**
     * @inheritdoc
     */
    public static function tableName()
    {
        return 'page_translate';
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
            [['name','seo_title','seo_descr','seo_keywords'], 'string', 'max' => 255],
            [['text','title','video'], 'string']
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
            'name' => 'Name',
            'seo_descr'=>'Description_SEO',
            'seo_title'=>'Title_SEO',
            'seo_keywords'=>'Keywords_SEO',
            'title' => 'Title',
            'text' => 'Text',
        ];
    }
}
