
var MapOptions = {
    // 지도 옵션 설정하기
    center: new naver.maps.LatLng(37.5666805,126.9784147),
    zoom: 11,
    minZoom: 7,
    zoomControl: true,
    zoomControlOptions: {
        position: naver.maps.Position.TOP_RIGHT
    },
    mapTypeId: naver.maps.MapTypeId.NORMAL
};

var map = new naver.maps.Map('map', MapOptions);
var markers =[];

$('#btn_submit').click(function (){
    var bus_id = $('#bus_id').val();
    $('#btn_submit').css("display","none");
    getbusRouteId(bus_id).then(function (data){
        getBusLocation(data);
        setInterval(function (){
            getBusLocation(data);
        },5000);
    });
});

function getBusLocation(data){
    $.each(markers,function (index,value){
        value.setMap(null);
    });
    markers = [];
    $.get('/bus_pos?busRouteId='+data,function(result){
        if(result) {

            $(result).find("itemList").each(function () {
                var lat = $(this).find("gpsY").text();
                var lng = $(this).find("gpsX").text();

                var marker = new naver.maps.Marker({
                    position: new naver.maps.LatLng(lat,lng),
                    map: map
                });

                markers.push(marker);
            });

        }
    });
}

function getbusRouteId(bus_id){
    return new Promise(function (resolve,reject){
        $.get('/map?bus_id='+bus_id,function(response){
            var busRouteId = $(response).find("busRouteId").text();
            resolve(busRouteId);
        });
    })
}