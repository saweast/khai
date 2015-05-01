$(document).ready(function(){
    $('#sortable').sortable();
    $('#categoryproperty-type').change( function(e){
        if($(this).val() == 'list')
        {
            $('.values').show();
        }
        else
        {
            $('.values').hide();
        }
    });

    $(document).on('click', '.add-input', function(e){
        $('#sortable').sortable("destroy");
        e.preventDefault();
        var lang = $(this).data('lang');
        var container = $(this).closest('.values').find('table tbody');
        var html = '<tr>';
        var index = $('#sortable tr').length;
        for(var i=0;i < languages.length; i++)
        {
            html += '<td class="span6"><input type="text" name="values[' + index + '][' + languages[i] + ']" data-lang="'+languages[i]+'"/></td>';
        }
        html += '<td class="span1"><a class="remove-input">x</a></td>';
        html += '<td class="span1"><span class="move-input"></span></td>';
        html += '</tr>';
        $(html).appendTo(container);

        setTimeout(function(){
            $('#sortable').sortable({
                distance: 0,
            });
        }, 500);

    });
    $(document).on('click', '.remove-input', function(e){
        e.preventDefault();
        $(this).closest('tr').hide('fast', function(){$(this).remove()});
    });

    $(document).on('click', '.duplicate-prop-values', function(e){
        e.preventDefault();
        if(confirm('Если на других языковых вкладках заполнены значения, эта функция их перезапишет. Вы уверены?'))
        {
            var _this = $(this);
            var lang = _this.data('lang');
            var rows = $('.values tbody tr');
            $.each(rows, function(k, v){
                var from = $(v).find('input[data-lang='+lang+']').eq(0);

                var to = $(v).find('input[data-lang]');

                $.each(to, function(k, elem){
                    $(elem).val(from.val());
                });
            });
        }
    });

    $(document).on('change', '#region_id', function(e){
        var _this = $(this);
        if(_this.val() != "")
            $.ajax({
                type: 'post',
                url: '/backend/city/city/get-cities-by-region',
                data: { id: _this.val(), name: 'CategoryProperty[city_id]' },
                success: function(response) {
                    $('#citiesContainer').parent().show();
                    $('#citiesContainer').html(response);
                }
            });
        else
        {
            $('#citiesContainer').parent().hide();
            $('#citiesContainer').html('');
        }
    });
});