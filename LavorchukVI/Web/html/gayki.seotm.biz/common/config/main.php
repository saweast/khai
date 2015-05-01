<?php
return [
//    'bootstrap' => ['gii'],
    'modules' => [
        // ...
    ],
    'vendorPath' => dirname(dirname(__DIR__)) . '/vendor',
    'components' => [
        'i18n' => [
            'translations' => [
                'backend' => [
                    'class' => 'yii\i18n\DbMessageSource',
                    'sourceMessageTable' => 'dictionary',
                    'messageTable' => 'dictionary_translate',
                    'forceTranslation'=>true,
                ],
                'frontend' => [
                    'class' => 'yii\i18n\DbMessageSource',
                    'sourceMessageTable' => 'dictionary',
                    'messageTable' => 'dictionary_translate',
                    'forceTranslation'=>true,
                ]
            ],
        ],
        'cache' => [
            'class' => 'yii\caching\FileCache',
        ],
        'authManager' => [
            'class' => 'yii\rbac\PhpManager',
            'defaultRoles' => ['user','moder','admin'], //здесь прописываем роли
            //зададим куда будут сохраняться наши файлы конфигураций RBAC
            'itemFile' => '@common/components/rbac/items.php',
            'assignmentFile' => '@common/components/rbac/assignments.php',
            'ruleFile' => '@common/components/rbac/rules.php'
        ],
    ],

];
