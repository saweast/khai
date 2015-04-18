google.load('visualization', '1', {packages:['gauge']});
google.setOnLoadCallback(drawChart);
function drawChart() {
    var chartBtn, maxSize, currentLoad, load;
    chartBtn = document.getElementById('chart-btn');
    maxSize = $(chartBtn).data('maxsize');
    currentLoad = $(chartBtn).data('current');
    load = Math.round((currentLoad/maxSize)*100);

    var data = google.visualization.arrayToDataTable([
        ['Label', 'Value'],
        ['assets tmp', load]
    ]);

    var options = {
        width: 400, height: 180,
        greenFrom: 0, greenTo : 60,
        yellowFrom:60, yellowTo: 80,
        redFrom: 80, redTo: 100,
        minorTicks: 5
    };

    var chart = new google.visualization.Gauge(document.getElementById('chart_div'));
    chart.draw(data, options);
}/**
 * Created by chosen1 on 13.11.13.
 */
$(document).on("click",'#chart-btn',function(e){
    e.preventDefault();
    $.ajax({
        type:"POST",
        url:$(this).attr("href"),
        data:{
            'tmp':$(this).data("tmp")
        },
        success:function(){
            location.reload();
        }
    });
});