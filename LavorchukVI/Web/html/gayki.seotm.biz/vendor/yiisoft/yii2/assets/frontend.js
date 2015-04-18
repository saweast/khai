/**
 * Created by Артём on 20.02.2015.
 */
$(document).ready(function(){
  $('.header_menu menu li.with_children').each(function(){
        var width = $(this).children('span').outerWidth();
        var width_menu = $(this).children('menu').outerWidth();
      $(this).children('menu').css('left',-((width_menu-width)/2));
  });
    $('.footer_menu menu li.with_children').each(function(){
        var width = $(this).children('span').outerWidth();
        var width_menu = $(this).children('menu').outerWidth();
        $(this).children('menu').css('left',-((width_menu-width)/2));
    });
    $(document).on('click','.map_hide_container',function(){
        $('.contact_map[data-id='+$(this).data('id')+']').toggleClass('active');
        $(this).toggleClass('active');
    });
    $('#feedback_form').submit(function(e){
        e.preventDefault();
        var name = $('#feedback_name');
        var email = $('#feedback_email');
        var text = $('#feedback_text');
        var check = true;
        var _this = $(this);
        email.next().next().css('display','none');
        email.next().css('display','block');
        if(!name.val()){
            name.next().css('visibility','visible');
            check=false;
        }else{
            name.next().css('visibility','hidden');
        }
        if(!email.val()){
            email.next().css('visibility','visible');
            check=false;
        }else{
            email.next().css('visibility','hidden');
            if(!/[a-z0-9!#$%&'*+/=?^_`{|}~-]+(?:\.[a-z0-9!#$%&'*+/=?^_`{|}~-]+)*@(?:[a-z0-9](?:[a-z0-9-]*[a-z0-9])?\.)+[a-z0-9](?:[a-z0-9-]*[a-z0-9])?/.exec(email.val())){
                email.next().next().css('display','block');
                email.next().next().css('visibility','visible');
                email.next().css('display','none');
                check=false;
            }
        }
        if(!text.val()){
            text.next().css('visibility','visible');
            check=false;
        }else{
            text.next().css('visibility','hidden');
        }
        if(!check){
            return false;
        }
        $.ajax({
            type: "POST",
            url: "/feedback/save/",
            data:$(this).serialize(),
            success: function(msg){
                if(msg=='success')
                    $('.result_success').show();
                else
                    $('.result_fail').show();
                name.val('');
                email.val('');
                text.val('');
                setTimeout(function(){
                    $('.result_success').hide();
                    $('.result_fail').hide();
                },5000);
            }
        });
       return false;
    });
    $('.header_menu menu li').hover(function(){
        $('.header_menu menu li.active').removeClass('active');
    },function(){
        $('.header_menu menu li.real_active').addClass('active');
    });
    $(document).on('click','.map_disabled',function(){
        $(this).remove();
    });
});
