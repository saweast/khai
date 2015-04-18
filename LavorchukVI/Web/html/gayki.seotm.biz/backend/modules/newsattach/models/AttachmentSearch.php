<?php

namespace backend\modules\newsattach\models;

use Yii;
use yii\base\Model;
use yii\data\ActiveDataProvider;
use backend\modules\newsattach\models\Attachment;
use yii\helpers\VarDumper;

/**
 * CurrencySearch represents the model behind the search form about `backend\modules\contact\models\Currency`.
 */
class AttachmentSearch extends Attachment
{
    /**
     * @inheritdoc
     */
    public function rules()
    {
        return [
            [['attachment_id'], 'integer'],
            [['entity_id'], 'integer'],
            [['attachment_entity'], 'string'],
        ];
    }

    /**
     * @inheritdoc
     */
    public function scenarios()
    {
        // bypass scenarios() implementation in the parent class
        return Model::scenarios();
    }

    /**
     * Creates data provider instance with search query applied
     *
     * @param array $params
     *
     * @return ActiveDataProvider
     */
    public function search($params)
    {
                $query = Attachment::find();


        $dataProvider = new ActiveDataProvider([
            'query' => $query,
        ]);
        $this->load($params);

        $query->andFilterWhere(['like', 'attachment_entity', $this->attachment_entity]);
        $query->andFilterWhere([
            'attachment_id' => $this->attachment_id,
            'entity_id' => $this->entity_id,
        ]);


        return $dataProvider;
    }
}
