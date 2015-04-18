/**
 * Created by Kate on 19.02.15.
 */
$(document).ready(function(){
    $(document).on('change', '.category-select', function(e){
        var _this = $(this);
        var no_id = _this.data('no_id');
        $('#categorySelect').val(_this.val());
        $.ajax({
            url: '/backend/category/category/get-children',
            type: 'post',
            data: {
                id: _this.val(),
                name: _this.attr('name'),
                no_id: no_id
            },
            success: function(response) {
                _this.nextAll().remove();
                $(response).insertAfter(_this);
            }
        });
    });
});