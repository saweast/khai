<?php

namespace backend\modules\news\models;

use Yii;
use yii\base\Model;
use yii\data\ActiveDataProvider;
use yii\helpers\VarDumper;

/**
 * NewsSearch represents the model behind the search form about `backend\modules\news\models\News`.
 */
class NewsSearch extends News
{
//    public $parent_id;
    public $title;
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
                $query = News::find();


        $dataProvider = new ActiveDataProvider([
            'query' => $query,
        ]);
        $this->load($params);

        $query->andFilterWhere([
            ''.News::tableName().'.'.'id' => $this->id,
            ''.News::tableName().'.'.'show' => $this->show,
        ]);
        $query->joinWith(['t'=>function($q){
            return $q->from('news_translate as translate');
        }]);
        $query->andFilterWhere(['like', 'translate.title', $this->title]);//search on all language
        $query->orderBy('date');
        return $dataProvider;
    }
}
