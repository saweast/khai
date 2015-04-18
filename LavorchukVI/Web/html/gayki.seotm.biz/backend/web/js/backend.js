/**
 * Created by max on 10.02.15.
 */
    $(document).ready(function(){
        var WindowHeight=$(window).height();

        $('#page_sortable tbody').sortable({
            start: function(event, ui) {

            },
            change: function(event, ui) {

            },
            update: function(event, ui) { //action if item droped
                var action = 'moveAfter';
                var id=ui.item.data('key');
                var id_item='';
                if(ui.item.index()==0){ //move as first
                    action='moveAsFirst';
                }else{
                    id_item=ui.item.prev().data('key');
                }
                $.ajax({
                    type: "POST",
                    url: "/backend/page/page/movetree",
                    data:{
                        id:id,
                        action:action,
                        id_item:id_item
                    },
                    success: function(msg){
                    }
                });
            }
        }).disableSelection();
        $(document).on('click','.delete_page_photo',function(){
            var _this = $(this);
            $.ajax({
                type: "POST",
                url: "/backend/page/page/deleteimage?page_id="+_this.data('id'),
                success: function(msg){
                    $('.img_page').html('');
                    $('.img_page').prev().val('');
                }
            });
        });
    });