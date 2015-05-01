/**
 * Created by Артём on 22.02.2015.
 */
$(document).ready(function(){
    $('#w0').submit(function(){
        var imgMeta = $('.img-meta-update[data-changed="1"], .img-meta');
        var _this = $(this);
        for(var i=0;i < imgMeta.length; i++) {
            var current = imgMeta.eq(i);
            var hidden = $('<input>')
                .attr('type', 'hidden')
                .attr('name', current.attr('name'))
                .val(current.val())
                .appendTo(_this);
        }
    });
    $('#w0').submit(function(){
        var imgMeta = $('.img-links-update[data-changed="1"], .img-links');
        var _this = $(this);
        for(var i=0;i < imgMeta.length; i++) {
            var current = imgMeta.eq(i);
            var hidden = $('<input>')
                .attr('type', 'hidden')
                .attr('name', current.attr('name'))
                .val(current.val())
                .appendTo(_this);
        }
    });
    $(document).on("keyup", ".img-meta-links", function(){
        var id = $(this).data('id');
        $('[data-id="'+id+'"]').attr('data-changed', '1');
    });
    $(document).on("keyup", ".img-meta-update", function(){
        var id = $(this).data('id');
        $('[data-id="'+id+'"]').attr('data-changed', '1');
    });
});
