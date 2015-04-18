<?php

namespace backend\modules\history\models;

use Yii;
use yii\base\Model;
use yii\data\ActiveDataProvider;
use yii\helpers\VarDumper;

/**
 * HistorySearch represents the model behind the search form about `backend\modules\history\models\History`.
 */
class HistorySearch extends History
{
    public $text;
    /**
     * @inheritdoc
     */
    public function rules()
    {
        return [
            [['id','show'], 'integer'],
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
                $query = History::find();


        $dataProvider = new ActiveDataProvider([
            'query' => $query,
        ]);
        $this->load($params);

        $query->andFilterWhere([
            ''.History::tableName().'.'.'id' => $this->id,
            ''.History::tableName().'.'.'show' => $this->show,
        ]);
        $query->joinWith(['t'=>function($q){
            return $q->from('history_translate as translate');
        }]);
        $query->andFilterWhere(['like', 'translate.text', $this->text]);//search on all language
        return $dataProvider;
    }
}
