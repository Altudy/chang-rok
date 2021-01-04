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
* 부모요소 height 부여
* 자식 요소가 고정된 높이 값을 가지며 부모 역시 고정된 높이 값을 가진 경우에만 사용 가능.

* 부모의 요소의 float 속성
* 자식 요소의 float을 해제하기 위해서 부모 요소에 의미 없는 float을 부여하는 방법은 좋지 않음.

* overflow(visible 제외)를 이용한 해제
* 부모 요소 안에 부모의 영역을 벗어나는 자식 콘텐츠가 있다면 그 내용의 일부가 보이지 않음.
* 부모의 내용을 넘쳐나서 노출되는 콘텐츠는 없는지 확인.

* 인접 형제요소의 clear 속성을 이용한 해제
* clear 속성을 사용하기 위해서는 display:block이어야 함.
* 아무런 의미가 없는 빈 태그를 이용해야 하기 때문에 시맨틱적인 요소에선 불필요한 요소가 생긴다는 단점.

* 가상요소를 이용한 clear 속성을 이용한 해제(가장 많이 쓰임)
* 부모 요소에 :after를 이용하여 자식 요소들 중 가장 마지막에 위치, 그 후에 블록 요소를 만들고 clear 해제.
* 가상 요소는 content 요소가 필수임이 중요.
```

# 4. 레이아웃
```
* 레이아웃 제작은 모든 웹 사이트를 만드는 과정에서 가장 먼저 선행되어야 하는 작업.
* 레이아웃 종류
* 1단 레이아웃, 다단 레이아웃(2단,3단,...)
* 고정(상, 하단 고정) 레이아웃
```

## 4-1. 1단 레이아웃 제작
```
* 웹에서 가장 기본이 되는 레이아웃이며 상단(header), 중단(contents), 하단(footer)의 구성.

* html5를 이용하여 header,section,footer로 구성.
* 레이아웃 관련 아이템들을 감싸기 위해 <div class="wrap">를 만들어 레이아웃 컨테이너의 역할을 하게함.
* min-width, max-width 속성을 이용해 가로 길이가 800px~1200px 로 유동적인 사이트 구성.
* margin: 0 auto; 를 이용하여 블록 요소 가운데 정렬.

* layout_1.html,  layout_1.css
```

## 4-2-1. 다단 레이아웃 제작(float)
```
* 다단 레이아웃의 짜임새가 테이블과 비슷해서 <table> 태그를 이용하여 레이아웃을 만들었지만 웹 표준이 발표되면서 <table> 태그로 구성된 레이아웃을 제작하는 사이트는 찾기 힘듬.

* 1단 레이아웃에 <div class="aside">를 추가하여 float:left 속성을 이용해 content와 aside 배치.
* footer의 float을 해제하기 위해 content와 aside를 감싸는 <div class="container">에 가상요소를 이용한 clear 속성을 이용하여 해제.
* content와 aside 사이의 구분선을 만들기 위해 aside에 가상요소를 이용해 position:absolute 와 top,right 속성을 이용해 구분선 배치.
* header와 footer가 위아래 고정이면서 content와 aside 중 한군데만 길어질 때 구분선이 한쪽 영역에 종속되지 않도록 하기 위함.

* 브라우저의 화면에 header, container, footer가 모두 나오게 하고 100%의 길이를 갖게 하기 위해 container에 min-height:100% 부여
* container의 부모요소인 wrap,body,html에 height:100%를 줘야함.
* 위의 상태라면 하단의 footer가 짤리므로 container의 위 아래에 padding: 100px 0; margin: -100px 0; box-sizing:border-box;를 주어
하단의 footer까지 보이게 한다.

* layout_2.html, layout_2.css
```

## 4-2-2. 다단 레이아웃 제작(table)
```

* container를 display:table, content와 aside를 display:table-cell 속성을 부여하여 테이블과 동일한 효과를 줌.
* container의 가로길이를 부여한 상태에서 content의 가로길이를 부여하면 aside는 가로길이를 따로 지정 안해줘도됨.
* content의 우측에 border 5px를 추가하고 그 만큼 width의 길이에서 뺌.

* layout_2_table.html,  layout_2_table.css
```

## 4-3-1. 고정 레이아웃(상단 고정)
```
* 1단 또는 2단 레이아웃의 형태에서 상단과 하단 또는 두 영역이 모두 컨텐츠의 높이나 내용에 상관없이 항상 노출이 되도록 하는 레이아웃.

* header에 position:fixed 부여하고 top:0,left:0,right:0도 같이 부여.
* footer를 끌어올리기 위해 container에 margin-top:-100px을 줌.
* content가 보이게 하기 위해 padding-top: 200px를 줌.
* 또 다른 방법으로 container에 padding-top: 200px; 를 주고 padding을 무시하기 위해 box-sizing: border-box 부여.

* layout_fixed.html,  layout_fixed.css
```

## 4-3-2. 고정 레이아웃(하단 고정)
```
* header와 footer에 position:fixed를 부여.
* container의 최소 높이값 설정(min-height:100%)
* container 영역은 header와 footer 영역에 의해 각각 100px씩 보이고 있지 않으므로 padding: 100px 0;을 부여.
* 그 후, box-sizing:border-box; 속성을 부여하여 높이값 100%에서 추가된 padding값을 포함할 수 있도록 해줌.

* layout_fixed2.html, layout_fixed2.css
```

## 5. 메뉴
```
* 메뉴는 웹페이지 이동을 도와주는 내비게이션의 역할을 한다.
* 1단 메뉴, 2단 메뉴
```

## 5-1. 1단 메뉴
```
* 메뉴 제작 시 메뉴 간 영역을 균등하게 하는 방법과 전체 메뉴의 최소/최대 값을 갖는 방법 살펴봄.

* 메뉴는 여러 개의 메뉴 아이템을 갖고 있으므로 <ul>태그를 이용하여 만듬.
* 메뉴 클릭 시 페이지 이동이 되어야 하므로 <li>안에 메뉴명을 감싸는 <a>태그 추가.
* 메뉴의 너비를 균등하게 하기 위해 display:table; table-layout:fixed 속성을 이용하고 각 메뉴 아이템은 display:table-cell; 속성을 부여.
* 외곽선 겹침 현상을 해결하기 위해 형제 선택자를 이용하여 margin-left: -1px; 속성을 부여
* active 클래스가 있는 메뉴 아이템은 위의 margin-left에 의해 우측의 border가 나타나지 않음.
* 이러한 현상을 해결하기 위해 position:relative; 속성을 주어 z-index 값을 새로 주어 가장 상단에 위치하도록 함.
```

## 5-2. 2단 메뉴
```
* 2단 메뉴는 메인 메뉴와 서브 메뉴로 구성되어 있음.
* 메인 메뉴 활성화 여부에 따라 서브 메뉴가 노출될 수 있도록 함.

* 메인 메뉴는 1단 메뉴와 동일하고 각 메뉴에 서브 메뉴 구성.
* 서브 메뉴 구성시 position: absolute; 속성을 주어 최상위 부모를 기준으로 위치를 잡게 함.
* 서브 메뉴 하단 라인은 텍스트를 span으로 감싸 가상선택자 속성을 사용하여 텍스트의 길이만큼 border가 하단에 생기도록 함.
* 각 메인 메뉴마다 서브 메뉴가 있으므로 겹치지 않게 기본 display:none;로 설정하고 hover나 active시에만 보이도록 display:block; 속성을 줌.
```

## 6. 탭
```
* 메뉴와의 차이 : 메뉴는 다른 페이지로 이동하지만 탭은 선택한 메뉴의 연관된 콘텐츠가 페이지 이동 없이 내용을 바로 살펴볼 수 있음.

* 탭 목록은 외부 페이지로 이동이 아닌 같은 페이지 내 콘텐츠로 이동이 되기 때문에 <button> 태그 사용.
* 탭 패널 콘텐츠는 순서형 리스트 이므로 <ol>태그로 작성, 그 안의 리스트 텍스트는 다른 페이지로 이동을 위해 <a> 태그로 감싸줌.
* 텍스트 말줄임을 하기 위해 overflow: hidden; white-space: nowrap; text-overflow: ellipsis; 속성을 준다.
* 패널 박스의 내용이 줄어도 최소 높이를 유지하기 위해 min-height 속성을 주고 padding과 border를 포함하여 높이를 유지하기 위헤
box-sizing: border-box; 속성을 줌.
```
