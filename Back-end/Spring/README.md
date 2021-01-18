# 스프링 부트와 AWS로 혼자 구현하는 웹 서비스

## 이클립스에 비해 인텔리제이가 갖는 장점.

* 강력한 추천 기능(smart completion)
* 훨씬 더 다양한 리팩토링과 디버깅 기능
* 이클립스의 깃에 비해 훨씬 높은 자유도
* 프로젝트 시작할 때 인덱싱을 하여 파일을 비롯한 자원들에 대한 빠른 검색 속도
* html과 css,js,xml에 대한 강력한 기능 지원
* 자바, 스프링 부트 버전업에 맞춘 빠른 업데이트

## build.gradle 파일 수정

* 프로젝트의 플러그인 의존성 관리를 위한 설정.
* ext : build.gradle에서 사용하는 전역변수를 설정.
* 나머지 코드 설명은 build.gradle에 주석 처리
* 코드 작성 후 나타나는 알림을 통해 변경된 내용 반영

## 단위 테스트 코드 작성

* 개발단계 초기에 문제를 발견하게 도와준다.
* 코드를 리팩토링하거나 라이브러리 업그레이드 등에서 기존 기능이 올바르게 작동하는지 확인할 수 있게 해줌.
* 기능에 대한 불확실성 감소
* 시스템에 대한 실제 문서를 제공.
* 개발자가 만든 기능을 안전하게 보호해준다. 새로운 기능이 추가될 때, 기존 기능이 잘 작동되는 것을 보장

* main/java에 Applicaition java class 생성.
* @SpringBootApplication // 스프링 부트의 자동 설정,스프링 Bean 읽기와 생성을 모두 자동으로 설정.
* SpringApplication.run // 내장 WAS로 애플리케이션을 실행. // 서버에 톰캣을 설치할 필요가 없게 되고, 스프링 부트로 만들어진 Jar 파일로 실행.
// 언제 어디서나 같은 환경에서 스프링 부트를 배포할 수 있다는 장점.
* 기존 com.rok.project package 밑에 web package를 만들어 컨트롤러와 관련된 클래스 관리
* HelloController 생성
  * @RestController : JSON을 반환하는 컨트롤러.
  * @GetMapping : HTTP Method인 GET의 요청을 받을 수 있는 API

* test folder 밑에 main와 똑같이 생성. HelloControllerTest 만 바뀜.
  * @RunWith(SpringRunner.class)
    -테스트를 진행할 때, JUnit에 내장된 실행자 외에 다른 실행자를 실행.
    -스프링 부트 테스트와 JUnit 사이에 연결자 역할.
  * @WebMvcTest
    -Web(Spring MVC)에 집중할 수 있는 어노테이션
    -@Controller, @ControllerAdvice 등은 사용가능 하지만, @Service, @Component, @Repository 등은 사용 x
  * @AutoWired
    -스프링이 관리하는 빈을 주입 받음.
  * MockMvc mvc
    -웹 API를 테스트할 때 사용.
    -테스트의 시작점.
    -이 클래스를 통해 post,get 등에 대한 api 테스트 가능.
    -perform : 괄호 안의 주소로 get 요청
    -andExpect(status.isOk()) : perform의 결과를 검증, HTTP header의 Status를 검증, 200 Ok 인지 검증.
    -content().string(hello) : 본문의 내용을 검증
  * test시 오류가 발생되어서 gradle의 버젼을 낮추어줌.
  * gradlew wrapper --gradle-version 4.10.2
  * 테스트 코드 실행 후 수동으로 검증하는 과정을 따르자.

## 롬복

* getter,setter,기본생성자,toString 등을 어노테이션으로 자동 생성.
* setting > build > compiler > annotation process > enable annotation processing check
* @Getter
  -선언된 모든 필드의 get 메소드를 생성해줌.
* @RequiredArgsConstructor
  -선언된 모든 final 필드가 포함된 생성자를 생성
  -final이 없는 필드는 생성자에 포함되지 않음.
* HelloResponseDto 클래스를 새로 생성 후, @Getter와 @RequiredArgsConstructor를 추가.
* test에서 똑같이 만들고 assertThat을 이용하여 값이 같은지 검증.
* test의 HelloController에서 dto 부분을 테스트 하는 코드 추가.
  * @RequestParam annotaion으로 name과 amount 값을 가져오므로 perform 부분에 .param으로 값을 더해준다. (기본형이 String이므로 int는 String.valueOf 메소드를 통해 가져온다.)
  * Expect 부분에서 jsonPath 메소드를 통해 JSON응답값을 필드별로 검증한다.
  
## JPA

* 웹 애플리케이션 개발이 점점 데이터 베이스 모델링에만 집중되면서 JPA가 등장.
* 객체 지향 프로그래밍 언어와 관계형 데이터베이스의 중간에서 패러다임 일치를 시켜주기 위한 기술.
* 개발자는 더는 sql에 종속적인 개발을 하지 않아도 된다.
* Spring Data JPA 모듈을 이용하여 JPA를 다룸. (JPA <- Hibernate <- Spring Data JPA)
* Spring Data JPA
  * 구현성 교체의 용이성
  * 저장소 교체의 용이성 : 관계형 데이터베이스 외에 다른 저장소로 쉽게 교체하기 위함.
  
# 게시판 웹 애플리케이션 만들기 + AWS에 무중단 배포

## 프로젝트에 Spring Data JPA 적용

* buidl.gradle의 dependencies에 의존성 추가
* spring-boot-starter-data-jpa
  -스프링 부트용 Spring Data JPA 추상화 라이브러리
  -스프링 부트 버전에 맞춰 자동으로 jpa관련 라이브러리들의 버전을 관리
* h2
  -인메모리 관계형 데이터베이스
  -프로젝트 의존성만으로 관리 가능
  -메모리에서 실행되기 때문에 애플리케이션을 재시작할 때마다 초기화된다. 테스트 용도로 많이 사용.
* domain 패키지 생성
  -소프트웨어에 대한 요구사항 혹은 문제 영역
* 패키지 내에 posts 패키지와 Posts 클래스 생성
  -Post 클래스는 DB의 테이블과 매칭될 클래스(Entity 클래스)
  -DB 데이터에 작업할 경우 쿼리를 날리기보다는 Entity 클래스의 수정을 통해 작업.
* @Entity
  -테이블과 링크될 클래스임을 나타냄.
  -기본값으로 클래스의 카멜케이스 이름을 언더스코어 네이밍으로 테이블 이름을 매칭.
* @Id
  -해당 테이블의 pk필드
* @GeneratedValue
  -pk의 생성 규칙
  -스프링 부트 2.0에서는 GenerationType.IDENTITY 옵션을 추가해야 auto_increment가 된다.
* @Column
  -선언하지 않아도 해당 클래스의 필드는 자동으로 컬럼이 된다.
  -추가로 변경이 필요한 옵션이 있으면 사용
  -문자열의 경우 varchar(255)가 기본, length로 사이즈를 늘리거나, columnDefinition으로 타입 변경.
* @NoArgsConstructor
  -기본 생성자 자동 추가
* @Builder
  -해당 클래스의 빌더 패턴 클래스를 생성
  -생성자 상단에 선언 시 생성자에 포함된 필드만 빌더에 포함
* Entity 클래스는 Setter 메소드를 만들지 않는다.
  -차후 기능 변경 시 복잡해지기 때문.
* 기본적인 구조
  -생성자를 통해 최종값을 채운 후 DB에 삽입.
  -값 변경이 필요한 경우 해당 이벤트에 맞는 public 메소드 호출
* @Builder를 통해 어느 필드에 어떤 값을 채워야할지 명확하게 인지.
* Posts 클래스를 데이터베이스로 접근하게 해줄 JpaRepository 생성.
  -mybatis에서 Dao로 불리는 DB layer 접근자.
  -인터페이스로 생성. JpaRepository<Entity 클래스, PK 타입>을 상속하면 기본적인 CRUD 메소드가 자동 생성.
  -Entity클래스와 Repository는 함께 관리.(같은 패키지 내에 있어야 한다.)
  
## 테스트 코드로 검증

* @After
  -Junit에서 단위 테스트가 끝날 때마다 수행되는 메소드
  -배포 전 전체 테스트를 수행할 때 테스트간 데이터 침범을 막기 위해 사용.
* postsRepository.save
  -테이블 posts에 있는 insert/update 쿼리를 실행.
  -id값이 있다면 update, 없다면 insert가 실행.
* postsRepository.findAll
  -테이블 posts에 있는 모든 데이터를 조회.
* @SpringBootTest
  -H2 데이터베이스를 자동으로 실행.
* 실행된 쿼리를 로그로 확인
  -resources에 application 이름으로 resource bundle 파일 생성.
  -spring.jpa.show_sql=true
* H2는 MySQL의 쿼리를 수행해도 정상적으로 작동하기 떄문에 application.properties 설정 변경.
  -spring.jpa.properties.hibernate.dialect=org.hibernate.dialect.MySQL5InnoDBDialect
  
## 등록 API 만들기

* 3가지 클래스 필요
  -Request 데이터를 받을 dto
  -API 요청을 받을 Controller
  -트랜잭션, 도메인 기능 간의 순서를 보장하는 Service
  
* Spring 웹 계층
  * Web layer
    -컨트롤러와 뷰 템플릿 영역
    -외부 요청과 응답에 대한 전반적인 영역
  * Service layer
    -컨트롤러와 Dao의 중간 영역
    -@Service에 사용되는 서비스 영역, @Transactional이 사용되어야 하는 영역
    -트랜잭션, 도메인 간의 순서 보장 역할
  * Repository layer
    -데이터 저장소에 접근하는 영역
  * Dtos
    -계층 간에 데이터 교환을 위한 객체
  * Domain model
    -도메인이라 불리는 개발 대상을 모든 사람이 동일한 관점에서 이해할 수 있고 공유할 수 있도록 단순화 시킨 것.
    -비즈니스 처리를 담당하는 곳.
    
* web 패키지에 PostsApiController, service 패키지에 PostsService, dto 패키지에 postsRequestDto 클래스 추가.
* 컨트롤러와 서비스에서 Bean을 주입받을 때에는 생성자를 통해서 주입 받도록 함.
  -클래스의 의존성 관계가 바뀔 수 있으므로 롬복의 @RequiredArgsConstructor 어노테이션을 통해 생성자를 생성함.
* Entity 클래스와 Dto클래스는 유사하지만 Entity 클래스를 Request/Response 클래스로 사용해서는 안됨.
  - Entity 클래스는 여러 클래스에 영향을 끼치기 때문, Dto 클래스는 View를 위한 클래스라 자주 변경이 됨.

## 테스트 코드로 검증

* JPA 기능을 이용하기 때문에 @WebMvcTest 어노테이션은 사용하지 않고 @SpringBootTest와 TestRestTemplate 사용.
* 테스트시 랜덤 포트에 대한 검증도 함.

## 수정/조회 API 만들기

* Controller에 수정과 조회에 해당하는 @PutMapping과 @GetMapping 선언(id값을 Path로 받으므로 인자에 @PathVariable 선언)
* Service에 update와 findById를 처리해줄 메소드 각각 선언.
* update관련 PostUpdateRequestDto로 post.update() 기능 수행.
 -update 기능에서 데이터베이스에 쿼리를 날리는 부분이 없는데, 이는 JPA의 영속성 컨텍스트 때문임.
 -트랜잭션 안에서 데이터베이스에서 데이터를 가져오면 영속성 컨텍스트가 유지된 상태이므로 이 안에서 update 실행하면 반영됨.
* id 값으로 조회하는 PostResponseDto를 만들어서 repository.findById(id)를 통해 가져온 entity를 dto에 담아서 return

## 테스트 코드로 검증

* PostsApiControllerTest에 코드 작성. (update 기능 테스트)
* 조회 기능 테스트는 톰캣을 실행해서 테스트
* 데이터베이스로 H2를 이용하므로 직접 접근하기 위해 웹 콘솔을 사용.
 -application.properties에 spring.h2.console.enabled=true 설정
* Application에서 main 메소드 실행후 localhost:8080/h2-console에서  jdbc url -> jdbc:h2:mem:testdb 설정

## JPA Auditing으로 생성시간/수정시간 자동화

* Domain 패키지에 BaseTimeEntity 클래스 생성
* 모든 Entity의 상위 클래스가 되어 Entity들의 createdDate, modifiedDate를 자동으로 관리
* @MappedSuperclass
 -JPA Entity 클래스들이 BaseTimeEntity을 상속할 경우 필드들도 칼럼으로 인식하도록 한다.
* @EntityListeners(AuditingEntityListener.class)
 -Auditing 기능을 포함
* @CreatedDate
 -Entity가 생성되어 저장될 때 시간이 자동으로 저장
* @LastModifiedDate
 -조회한 Entity의 값을 변경할 때 시간이 자동 저장.
* Post 클래스가 BaseTimeEntity 클래스를 상속받도록 설정.
* JPA Auditing 어노테이션들을 모두 활성화 하기 위해 Application 클래서 @EnableJpaAuditing 어노테이션 추가.

## JPA Auditing 테스트 코드 작성

* PostsRepositoryTest에 @Test 추가.
* LocalDateTime 변수를 생성하고 repository.save로 데이터베이스에 넣는다.
* getCreate, getModified 함수를 통해 값이 같은지 확인한다.

## 머스테치

* 템플릿 엔진 : 지정된 템플릿 양식과 데이터가 합쳐져 html 문서를 출력하는 소프트웨어
* jsp를 view의 역할만 하도록 구성하면 서버 템플릿 엔진처럼 동작.(서버에서 java 코드로 문자열을 만들어 html로 변환하여 브라우저로 전달)
* javascript는 브라우저 위에서 작동

* 머스테치 : 수많은 언어를 지원하는 가장 심플한 템플릿 엔진.
 -문법이 다른 템플릿 엔진보다 심플.
 -로직 코드를 사용할 수 없어 view의 역할과 서버의 역할을 명확하게 분리
 -하나의 문법으로 클라이언트/서버 템플릿 모두 사용 가능.
 
 * build.gradle에 compile('org.springframework.boot:spring-boot-starter-mustach')로 의존성 추가
 * 기본 페이지를 만들기 위해 resources/templates/index.mustache 파일을 만듬.
 * Controller에 맵핑을 해주고 실행.

## 게시글 등록 화면 만들기

* 프론트엔드 라이브러리를 사용할 수 있는 방법 2가지 중(외부 CDN, 직접 라이브러리 받기) 외부 CDN을 사용함.(실제 서비스에서는 이 방법 활용 x)
* HTML/JSP/Mustache에 코드 추가.
* 레이아웃 방식으로 통해 추가(공통 영역을 별도의 파일로 분리하여 필요한 곳에서 가져다 쓰는 방식)
* index.mustach에 글 등록 버튼을 생성(<a>태그)
* 버튼 클릭시 이동할 페이지의 주소를 컨트롤러에 @GetMapping으로 설정
* posts-save.mustache 추가(게시글을 등록하는 폼 생성)
* /posts/save 에서 등록 버튼에 기능을 주기 위해 static/js/app/index.js 생성

## 전체 조회 화면 만들기

* index.mustache 파일에 목록 출력 영역 추가.
* {{#posts}}
 -posts라는 List를 순회
* {{변수명}}
 -List에서 뽑아낸 객체의 필드
* 전체 조회 쿼리는 SpringDataJpa에서 제공하지 않으므로 PostsRepository에 @Query 추가.
* Service에서 @Transactional(readOnly = true)를 주어 트랜잭션 범위는 유지하되, 조회 기능만 남겨두어 조회 속도를 개선.
* Repository 결과로 넘어온 Posts의 stream을 map을 통해 PostsListRequestDto로 변환 -> List로 반환.
* 컨트롤러에서 model에 담아 index.mustache로 넘겨줌.

## 게시글 수정, 삭제 화면 만들기

* 게시글 수정 화면(posts-update.mustache)생성, index.mustache에 타이틀을 클릭시 게시글 수정 화면으로 이동하도록 설정.
* 게시글 수정 화면에 삭제 버튼도 생성하고 클릭 시 Controller->Service에서 처리하도록 한다.
* 처리 시 존재하는 posts인지 확인을 위해 존재 후 삭제한다.
 
# 로그인

* spring security와 OAuth 2.0을 구현한 구글 로그인을 연동하여 로그인 기능.
* 직접 구현 하게 되면 아래와 같은 기능을 모두 구현해야함
 1) 로그인 시 보안
 2) 비밀번호 찾기
 3) 회원가입 시 이메일 혹은 전화번호 인증
 4) 비밀번호 변경
 5) 회원정보 변경
 
* spring boot 1.5 vs 2.0
 -spring-security-oauth2-autoconfigure 라이브러리를 사용하면 1.5의 설정을 그대로 사용할 수 있음.
 -1.5보다 설정이 간편(client 인증 정보만 입력하면 됨.)

## 구글 서비스 등록

* 구글 서비스에 신규 서비스를 생성
* 발급된 은증 정보를 통해 로그인 기능과 소셜 서비스 기능을 사용.
* 구글 클라우드 플랫폼에서 OAuth 동의 화면에 Google API 범위 추가
* application-oauth 등록
* application-oauth.properties 내에 클라이언트 id와 보안 비밀 정보 입력, scope=email,profile 만 입력
 - profile=xxx 식으로 호출하면 해당 properties의 설정들을 가져올 수 있음.

## 배포 스크립트 만들기

* 배포할 때마다 개발자가 하나하나 명령어를 실행하는 것은 불편함이 많으므로 쉘 스크립트를 작성
* 
