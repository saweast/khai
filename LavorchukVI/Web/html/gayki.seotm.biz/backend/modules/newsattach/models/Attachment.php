<?php
namespace backend\modules\newsattach\models;
/**
 * This is the model class for table "Attachments".
 *
 * The followings are the available columns in table 'Attachments':
 * @property integer $attachment_id
 * @property string $attachment_entity
 * @property integer $entity_id
 * @property string $type
 * @property string $path
 * @property integer $position
 * @property string $description
 *
 */

use Yii;

class Attachment extends \yii\db\ActiveRecord
{
	/**
	 * @return string the associated database table name
	 */
    public static function tableName()
    {
        return 'Attachments';
    }

	/**
	 * @return array validation rules for model attributes.
	 */
	public function rules()
	{
		// NOTE: you should only define rules for those attributes that
		// will receive user inputs.
		return array(
			array('attachment_entity, entity_id, type, path', 'required'),
			array('entity_id', 'numerical', 'integerOnly'=>true),
			array('attachment_entity', 'length', 'max'=>8),
			array('type', 'length', 'max'=>5),
			array('path', 'length', 'max'=>255),
            array('options','safe'),
			// The following rule is used by search().
			// @todo Please remove those attributes that should not be searched.
			array('attachment_id, attachment_entity, entity_id, type, path', 'safe', 'on'=>'search'),
		);
	}

	/**
	 * @return array customized attribute labels (name=>label)
	 */
	public function attributeLabels()
	{
		return array(
		);
	}

    public function transactions()
    {
        return [
            self::SCENARIO_DEFAULT => self::OP_ALL,
        ];
    }

    public static function find()
    {
        return new AttachmentQuery(get_called_class());
    }
}
