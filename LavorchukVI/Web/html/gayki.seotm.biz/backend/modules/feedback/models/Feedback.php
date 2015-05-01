<?php

namespace backend\modules\feedback\models;

use Yii;
/**
 * This is the model class for table "feedback".
 *
 * @property integer $id
 * @property integer $is_main
 */
class Feedback extends \yii\db\ActiveRecord
{
    public function behaviors()
    {
        return [

        ];
    }

    /**
     * @inheritdoc
     */
    public static function tableName()
    {
        return 'feedback';
    }

    /**
     * @inheritdoc
     */
    public function rules()
    {
        return [
            [['name','text','email'], 'required'],
        ];
    }

    /**
     * @inheritdoc
     */
    public function attributeLabels()
    {
        return [
            'id' => 'ID',
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
        return new FeedbackQuery(get_called_class());
    }

}
