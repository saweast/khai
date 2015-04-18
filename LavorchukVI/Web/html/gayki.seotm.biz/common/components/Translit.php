<?php
/**
 * Created by PhpStorm.
 * User: max
 * Date: 17.02.15
 * Time: 12:45
 */
namespace common\components;
class Translit{

    public static function cyrillicToLatin($text, $toLowCase = TRUE, $maxlength = 100)
    {
        $matrix=array(
            "й"=>"i","ц"=>"c","у"=>"u","к"=>"k","е"=>"e","н"=>"n",
            "г"=>"g","ш"=>"sh","щ"=>"shch","з"=>"z","х"=>"h","ъ"=>"",
            "ф"=>"f","ы"=>"y","в"=>"v","а"=>"a","п"=>"p","р"=>"r",
            "о"=>"o","л"=>"l","д"=>"d","ж"=>"zh","э"=>"e","ё"=>"e",
            "я"=>"ya","ч"=>"ch","с"=>"s","м"=>"m","и"=>"i","т"=>"t",
            "ь"=>"","б"=>"b","ю"=>"yu",
            "Й"=>"I","Ц"=>"C","У"=>"U","К"=>"K","Е"=>"E","Н"=>"N",
            "Г"=>"G","Ш"=>"SH","Щ"=>"SHCH","З"=>"Z","Х"=>"X","Ъ"=>"",
            "Ф"=>"F","Ы"=>"Y","В"=>"V","А"=>"A","П"=>"P","Р"=>"R",
            "О"=>"O","Л"=>"L","Д"=>"D","Ж"=>"ZH","Э"=>"E","Ё"=>"E",
            "Я"=>"YA","Ч"=>"CH","С"=>"S","М"=>"M","И"=>"I","Т"=>"T",
            "Ь"=>"","Б"=>"B","Ю"=>"YU",
            "«"=>"","»"=>""," "=>"-",

//                        "\""=>"", "\."=>"", "–"=>"-", "\,"=>"", "\("=>"", "\)"=>"",
//                        "\?"=>"", "\!"=>"", "\:"=>"",

            '\"'=>'', '\.'=>'_', '–'=>'-', '\,'=>'', '\('=>'', '\)'=>'',
            '\?'=>'', '\!'=>'', '\:'=>'',

            '#' => '', '№' => '',' - '=>'-', '/'=>'-', '  '=>'-',
        );

        // Enforce the maximum component length
        $text = implode(array_slice(explode('<br>',wordwrap(trim(strip_tags(html_entity_decode($text))),$maxlength,'<br>',false)),0,1));
        //$text = substr(, 0, $maxlength);

        foreach($matrix as $from=>$to)
            $text=mb_eregi_replace($from,$to,$text);

        // Optionally convert to lower case.
        if ($toLowCase)
        {
            $text = strtolower($text);
        }
        return preg_replace('/[^\w\d-]/u', '-', $text);
    }
}