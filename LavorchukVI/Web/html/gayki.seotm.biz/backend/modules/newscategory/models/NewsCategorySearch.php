<?php

namespace backend\modules\newscategory\models;

use Yii;
use yii\base\Model;
use yii\data\ActiveDataProvider;
use yii\helpers\VarDumper;

/**
 * NewsCategorySearch represents the model behind the search form about `backend\modules\news\models\NewsCategory`.
 */
class NewsCategorySearch extends NewsCategory
{
//    public $parent_id;
    public $name;
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
                $query = NewsCategory::find();


        $dataProvider = new ActiveDataProvider([
            'query' => $query,
        ]);
        $this->load($params);

        $query->andFilterWhere([
            ''.NewsCategory::tableName().'.'.'id' => $this->id,
            ''.NewsCategory::tableName().'.'.'show' => $this->show,
        ]);
        $query->joinWith(['t'=>function($q){
            return $q->from('news_category_translate as translate');
        }]);
        $query->andFilterWhere(['like', 'translate.name', $this->name]);//search on all language
        return $dataProvider;
    }
}
