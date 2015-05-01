<?php

namespace backend\modules\contact\models;

use Yii;
use yii\base\Model;
use yii\data\ActiveDataProvider;
use yii\helpers\VarDumper;

/**
 * ContactSearch represents the model behind the search form about `backend\modules\contact\models\Contact`.
 */
class ContactSearch extends Contact
{
//    public $parent_id;
    public $name;
    /**
     * @inheritdoc
     */
    public function rules()
    {
        return [
            [['id','show','is_main'], 'integer'],
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
                $query = Contact::find();


        $dataProvider = new ActiveDataProvider([
            'query' => $query,
        ]);
        $this->load($params);
        $query->joinWith(['t'=>function($q){
            return $q->from('contact_translate as translate');
        }]);
        $query->andFilterWhere(['like', 'translate.name', $this->name]);//search on all language
        $query->andFilterWhere([
            ''.Contact::tableName().'.'.'id' => $this->id,
            ''.Contact::tableName().'.'.'show' => $this->show,
            ''.Contact::tableName().'.'.'is_main' => $this->is_main,
        ]);

        return $dataProvider;
    }
}
