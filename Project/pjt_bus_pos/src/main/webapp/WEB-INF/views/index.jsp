<%@ page language="java" contentType="text/html; charset=UTF-8"%>
<%
    response.setHeader("Pragma","no-cache");
    response.setDateHeader("Expires",0);
    response.setHeader("Cache-Control","no-cache");
%>
<!DOCTYPE html>
<html lang="en" dir="ltr">
<head>
    <meta charset="utf-8">
    <title>버스 노선 정보</title>
    <link rel="stylesheet" href="resources/css/index.css">
    <script type="text/javascript" src="https://openapi.map.naver.com/openapi/v3/maps.js?ncpClientId=weiw0ffqpm"></script>
</head>
<body>
<div class="form_wrap">
    <form id="form" class="" action="/map" method="get">
        <label for="bus_id">버스 번호 : </label>
        <input type="text" name="bus_id" id="bus_id" value="">
        <button type="button" id="btn_submit">확인</button>
    </form>
</div>
<div class="map_wrap">
    <div class="map" id="map">

    </div>
</div>
<script src="http://code.jquery.com/jquery-1.11.2.min.js"></script>
<script src="resources/js/index.js"></script>
</body>
</html>

