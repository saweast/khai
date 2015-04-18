<?php

use yii\db\Schema;
use yii\db\Migration;

class m150210_092549_create_menu_table extends Migration
{
    public function up()
    {
        $this->createTable('{{%menu}}', [
            'id' => Schema::TYPE_PK,
            // 'tree' => Schema::TYPE_INTEGER,
            'lft' => Schema::TYPE_INTEGER . ' NOT NULL',
            'rgt' => Schema::TYPE_INTEGER . ' NOT NULL',
            'depth' => Schema::TYPE_INTEGER . ' NOT NULL',
            'name' => Schema::TYPE_STRING . ' NOT NULL',
        ]);
    }

    public function down()
    {
        echo "m150210_092549_create_menu_table cannot be reverted.\n";

        return false;
    }
}
