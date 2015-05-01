<?php
/**
 * Created by PhpStorm.
 * User: chosen1
 * Date: 29.10.13
 * Time: 11:37
 */
use yii\widgets\InputWidget;
use Yii;
class TmpSizeWidget extends InputWidget
{

    public $maxSize = null;
    public $path;
    public $clearAction;
    public $title = null;

    public function init()
    {

    }

    public function run()
    {
        $loaded = $this->getTempLoad($this->path);
        return $this->render('tmpSizeWidget',array(
            'maxSize'=>$this->maxSize,
            'size'=>$loaded,
            'clearAction'=>$this->clearAction,
            'tmp'=>$this->path,
            'title'=>$this->title,
        ));
    }


    private function getTempLoad($path)
    {
        return round($this->foldersize($path)/(1024*1024));
    }

    protected function foldersize($path) {
        $total_size = 0;
        $files = scandir($path);
        $cleanPath = rtrim($path, '/'). '/';
        foreach($files as $t) {
            if ($t<>"." && $t<>"..") {
                $currentFile = $cleanPath . $t;
                if (is_dir($currentFile)) {
                    $size = $this->foldersize($currentFile);
                    $total_size += $size;
                }
                else {
                    $size = filesize($currentFile);
                    $total_size += $size;
                }
            }
        }

        return $total_size;
    }

} 