<?php

namespace backend\modules\page\models;

use backend\modules\attach\models\Attachment;
use Yii;
use creocoder\nestedsets\NestedSetsBehavior;
use common\components\MultilingualBehavior;
use yii\helpers\VarDumper;
use yii\base\Security;

use backend\modules\attach\components\AttachmentBehavior;
/**
 * This is the model class for table "page".
 *
 * @property integer $id
 * @property integer $left
 * @property integer $right
 * @property integer $depth
 * @property integer $show
 * @property integer $show_in_menu
 * @property integer $main_page
 * @property string $translit
 * @property string $img
 */
class Page extends \yii\db\ActiveRecord
{
    public $parent;
    public $children;
    public function behaviors()
    {
        return [
                'nestedSetBehavior' => [
                    'class' => NestedSetsBehavior::className(),
                     'leftAttribute'  => 'left',
                     'rightAttribute' => 'right',
                     'depthAttribute' => 'depth',
                ],
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
        return 'page';
    }

    /**
     * @inheritdoc
     */
    public function rules()
    {
        return [
            [['show','show_in_menu','main_page'], 'required'],
            [['show','show_in_menu','main_page'], 'number'],
            [['translit','img'],'string'],
        ];
    }

    /**
     * @inheritdoc
     */
    public function attributeLabels()
    {
        return [
            'id' => 'ID',
            'show' => 'Show',
            'show_in_menu' => 'ShowInMenu',
            'main_page' => 'MainPage',
            'translit' => 'Translit',
            'img' => 'Image',
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
        return new PageQuery(get_called_class());
    }

    /**
     * @return \yii\db\ActiveQuery
     */
    public function getTranslate()
    {
        return $this->hasMany(PageTranslate::className(), ['id_item' => 'id'])->indexBy('language');
    }

    /**
     * @return \yii\db\ActiveQuery
     */
    public function getT()
    {
        return $this->hasOne(PageTranslate::className(), ['id_item' => 'id'])->where(['language'=>Yii::$app->language]);
    }

    public function getAttach(){
        return $this->hasMany(Attachment::className(), ['entity_id' => 'id'])->where(['attachment_entity'=>'Page'])->orderBy('position');
    }

    public function attachMultilangual()
    {
        $this->attachBehavior('ml', [
            'class' => MultilingualBehavior::className(),
            'relationClassName'=>PageTranslate::className(),
            'langForeignKey' => 'id_item',
        ]);
    }
}
