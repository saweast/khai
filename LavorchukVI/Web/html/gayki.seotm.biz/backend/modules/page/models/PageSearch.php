<?php

namespace backend\modules\page\models;

use Yii;
use yii\base\Model;
use yii\data\ActiveDataProvider;
use backend\modules\page\models\Page;
use yii\helpers\VarDumper;

/**
 * PageSearch represents the model behind the search form about `backend\modules\page\models\Page`.
 */
class PageSearch extends Page
{
    public $parent_id;
    public $name;
    /**
     * @inheritdoc
     */
    public function rules()
    {
        return [
            [['id'], 'integer'],
            [['show'], 'integer'],
            [['name'], 'string'],
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

        if(isset($params['parent_id'])){
            $this->parent_id=$params['parent_id'];
            $model = Page::findOne($this->parent_id);
            $query = $model->children(1);

        }else{
            $model = Page::findOne(['left'=>'1']);
            if($model)
                $query = $model->children(1);
            else{
                $query = Page::find();
            }

        }

        $dataProvider = new ActiveDataProvider([
            'query' => $query,
        ]);
        $this->load($params);
        $query->joinWith(['t'=>function($q){
            return $q->from('page_translate as translate');
        }]);
        $query->andFilterWhere(['like', 'translate.name', $this->name]);//search on all language

        $query->andFilterWhere([
            ''.Page::tableName().'.'.'id' => $this->id,
            ''.Page::tableName().'.'.'show' => $this->show,
        ]);

        return $dataProvider;
    }
}
