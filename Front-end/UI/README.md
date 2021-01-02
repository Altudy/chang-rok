[웹 UI 개발](https://www.boostcourse.org/web344)

# 1. reset_css
```
* 어떤 브라우저에서든 사용자들이 동일한 경험을 할 수 있도록 크로스브라우징 원칙을 지켜서 코딩해야한다.
* 모든 브라우저에서 동일한 뷰를 보여주기 위해 기본값을 초기화한다.
```
※ [에릭 마이어의 reset css](https://meyerweb.com/eric/tools/css/reset/)
```
* 상황에 따라 수정해서 써야 한다는 것에 주의.
```

# 2. IR기법(Image Replacement)
```
* 웹 접근성 중 '적절한 대체 텍스트 제공'에 관해 대체 텍스트를 마크업으로 제공.
* <img> 태그의 alt 속성 값으로 표현하기에 대체 텍스트가 너무 길거나, CSS background 속성을 사용하여 처리한 의미 있는 이미지일 경우, 마크업으로 대체 텍스트를 제공.
```

## 2-1. 요소 숨김 처리
```
* CSS로 대체 텍스트를 화면에서 숨기는 방법.

* BAD) 스크린 리더가 인식하지 못하기 때문에, 다음 중 어느 속성이라도 사용하면 안된다.
* visibility:hidden;
* display:none;
* width:0; height:0; font-size:0; line-height:0; // 요소의 사이즈를 0으로 만들면 스크린 리더가 인식을 안한다.

* SO SO) 스크린 리더가 인식하지만 레이아웃이나 성능 등에 이슈가 발생할 수 있기 떄문에, 상황에 맞게 사용.
* opacity:0; // 투명해진 것 뿐, 위치를 그래도 잡고 있음.
* text-indent:-9999px; // 전체 레이어의 크기가 지나치게 크게 잡힘, 성능 이슈
* z-index:-1; // position 속성을 추가해햐함, 성능 이슈

* BEST) 스크린 리더가 인식하면서 레이아웃이나 성능 등에 영향을 미치지 않는 방법, HTML 전체적으로 많이 쓰이기 때문에 클래스로 처리.
* position:absolute; // 레이아웃에 영향을 끼치지 않도록 함.
* width:1px; height:1px; // 스크린 리더가 읽을 수 있도록 함.
* clip:rect(0 0 0 0); margin:-1px; overflow:hidden; // 눈에 보이는 부분을 제거
```

## 2-2. 프로모션 페이지 제작
```
* 일정 기간 노출되고 사라지는 프로모션 페이지를 직접 제작
* 프로모션 페이지는 전체 화면을 이미지로 처리한 경우가 많기 때문에 시멘틱한 마크업이 중요함. 이를 실습.

* 모든 요소를 감싸고 있는 <div class="wrap">을 추가하여 전체 컨텐츠 영역에 이미지를 적용(background 속성)
* div 내의 텍스트를 숨기기 위해 blind 클래스를 추가. 하지만, 이미지 내에 <a>링크가 있기 때문에 부모 요소에 blind 클래스를 적용하진 않음.
* <a>에는 이미지 상의 버튼과 동일한 영역과 위치를 잡도록 link_point, link_join 클래스를 각각 추가.
* 텍스트도 숨기기 위해 <span>으로 감싸고 blind 클래스 추가.
* 위치를 잡기 위해 <div class="wrap">에 position: relative를 추가하고 각각의 <a>에 position:absolute를 추가하여 bottom, left 속성으로 위치를 잡음.
* reset css를 통해 기본 스타일을 초기화하여 불필요한 여백이나 스타일이 노출되지 않도록 함.

* promotion_page.html,  promotion_page.css, promotion_img.png
```

# 3. float 해제
```
* 
```
