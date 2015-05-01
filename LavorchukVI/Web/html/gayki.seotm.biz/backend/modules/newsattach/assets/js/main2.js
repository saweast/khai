/*
 * jQuery File Upload Plugin JS Example 8.9.0
 * https://github.com/blueimp/jQuery-File-Upload
 *
 * Copyright 2010, Sebastian Tschan
 * https://blueimp.net
 *
 * Licensed under the MIT license:
 * http://www.opensource.org/licenses/MIT
 */

/*jslint nomen: true, regexp: true */
/*global $, window, blueimp */

$(function () {
    'use strict';

    // Initialize the jQuery File Upload widget:
    $('#fileshow').fileupload({
        // Uncomment the following to send cross-domain cookies:
        //xhrFields: {withCredentials: true},
        url: '/backend/newsattach/default/show'
    });

    // Enable iframe cross-domain access via redirect option:
    $('#fileshow').fileupload(
        'option',
        'redirect',
        window.location.href.replace(
            /\/[^\/]*$/,
            '/cors/result.html?%s'
        )
    );

        // Load existing files:

        // loading png
        $('#fileshow').addClass('fileupload-processing');

        $.ajax({
            // Uncomment the following to send cross-domain cookies:
            //xhrFields: {withCredentials: true},

            url: $('#fileshow').fileupload('option', 'url'),
            dataType: 'json',
            context: $('#fileshow')[0]
        }).always(function () {
            $(this).removeClass('fileupload-processing');
        }).done(function (result) {
            $(this).fileupload('option', 'done')
                .call(this, $.Event('done'), {result: result});
        });

    $(function() {
        $( "#sortable" ).sortable({
            items: "tr"
    });
    $( "#sortable" ).disableSelection();

    $( "#sortable" ).on( "sortupdate", function( event, ui ) {
        $.ajax({
            type:"POST",
            url:"/backend/newsattach/default/sort",
            beforeSend:function(){
                $("#loader").html('<img src="/img/loader.gif" />');
            },
            data:{
                current:ui.item.data("position"),
                previous:ui.item.prev().data("position"),
                id:ui.item.data("id")
            },
            complete:function(){
                $("#loader").html('');
            }
        });
    } );
    });
});
