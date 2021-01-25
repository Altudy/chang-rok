# 블로그 만들기

## 목차

* [개발 환경](#개발-환경)
* [개념 정리](#개념-정리)
  * [Maven](#1-Maven)
  * [JDBC](#2-JDBC)
  * [Scope](#3-Scope)
  * [EL](#4-EL-&-JSTL)
  * [Spring](#5-Spring)
  * [Test](#6-Test)
  * [Spring JDBC](#7-Spring-JDBC)
* [진행과정](#진행과정)
  * [환경 구성](#1-환경-구성)

## 개발 환경

* Spring framework
* mysql

# 개념 정리

## 1. Maven

* 애플리케이션을 개발하기 위해 반복적으로 진행해왔던 작업들(관련 라이브러리를 다운로드하여 복사하여 설치)을 지원하기 위한 도구
* Coc(프로그램의 소스파일은 어떤 위치에 있어야 하고, 소스가 컴파일된 파일들은 어떤 위치에 있어야 하는지 등의 관습)

* 편리한 의존성 라이브러리 관리(pom.xml에 dependency 추가)

## 2. JDBC

* java database connectivity
* 자바를 이용한 데이터베이스 접속과 sql 문장의 실행, 실행 결과로 얻어진 데이터의 핸들링을 제공하는 방법과 절차에 관한 규약

* JDBC 클래스의 생성 관계
* DriverManager -> Connection -> Statement -> ResultSet

## 3. Scope

* Application : 웹 애플리케이션이 시작되고 종료될 때까지 변수가 유지되는 경우
  -ServletContext 인터페이스를 구현한 객체를 사용
  -JSP에서는 application 내장 객체를 이용
  -모든 클라이언트가 공통으로 사용해야 할 값들이 있을 때 사용
* Session : 웹 브라우저 별로 변수가 관리되는 경우
  -웹 브라우저의 탭 간에는 세션정보가 공유
  -HttpSession 인터페이스를 구현한 객체를 사용
  -JSP에서는 session 내장 변수를 사용
  
* Request : http요청을 WAS가 받아서 웹 브라우저에게 응답할 때까지 변수가 유지되는 경우
  -HttpServletRequest 객체를 사용
  -JSP에서는 request 내장 변수를 사용
  -값 저장시 setAttribute(), 값 얻을 때 getAttribute()
  -forward시 값을 유지
  
* Page : 페이지 내에서 지역변수처럼 사용
  -PageContext 추상 클래스를 사용
  -JSP 페이지 내에서 pageContext라는 내장 객체로 사용 가능
  -forward가 될 경우 해당 Page scope에 지정된 변수는 사용 x
  
## 4. EL & JSTL

* 값을 표현하는데 사용되는 스크립트 언어로서 JSP의 기본 문법을 보완

* JSP 안에 자바코드와 HTML코드가 섞여 있다면 수정시 어려움을 겪으므로 JSTL 등장.
* 태그 형식으로 조건문 반복문 사용 

## 5. Spring

* 원하는 부분만 가져다 사용할 수 있도록 모듈화가 잘 되어 있다.
* IoC 컨테이너
 -컨테이너는 인스턴스의 생명주기를 관리하며 생성된 인스턴스에게 추가적인 기능을 제공
 -컨테이너가 오브젝트의 제어권을 갖는것.
* DI
 -클래스 사이의 의존 관계를 빈 설정 정보를 바탕으로 컨테이너가 자동으로 연결
* 선언적으로 트랜잭션을 관리

* Bean class
 -기본생성자를 가지고 있음
 -필드는 private하게 선언
 -getter,setter 메소드를 가짐

* Java Config를 이용한 설정
 -오타 발견이 쉽고,자동완성 등을 지원하기 때문에 편리
* @Configuration
 -스프링 설정 클래스를 선언하는 어노테이션
* @Bean
 -bean을 정의하는 어노테이션
* @ComponentScan
 -@Controller,@Service,@Repository,@Component 어노테이션이 붙은 클래스를 찾아 컨테이너에 등록
* @Component
 -유틸, 기타 지원 클래스에 붙이는 어노테이션
* @Autowired
 -주입 대상이 되는 bean을 컨테이너에 찾아 주입하는 어노테이션
 
## 6. Test

* TDD(test-driven development)
 -매우 짧은 개발 사이클을 반복하는 소프트웨어 개발 프로세스 중 하나
 -개발을 하는데 있어서 테스트가 주가 되어 개발한다는 의미
* 테스트 코드를 먼저 작성한다면 좀 더 명확한 기능과 구조를 설계 가능
 -각각의 기능에 대해 철저히 구조화 시켜 코드를 작성할 수 있음.
* 설계의 구조적 문제를 바로 찾아냄.
* TDD 개발로 각각의 단위 테스트를 진행하게 된다면 영역을 분할하여 쉽게 찾아낼 수 있음

* JUnit
* @Before
 -테스트 메소드가 실행되기 전에 실행
* @After
 -테스트 메소드가 실행된 후에 실행
* Assert클래스로 검증

* 스프링 테스트 어노테이션 사용
* @RunWith(SpringJUnit4classRunner.class)
 -JUnit이 테스트 코드를 실행할 때 스프링 빈 컨테이너가 내부적으로 생성되도록 함.
* @ContextConfiguration(classes = {ApplicationConfig.class})
 - 내부적으로 생성된 스프링 빈 컨테이너가 사용할 설정파일 지정
* 스프링 빈 컨테이너를 사용할 때는 개발자가 직접 인스턴스를 생성하면 안됨.

* 통합 테스트
 -하나의 빈을 테스트할 때 관련된 빈들이 모두 잘 동작하는지 테스트하는 것
* 단위 테스트
 -관계된 다른 클래스와는 상관 없이 특정 빈이 가지고 있는 기능만 잘 동작하는지 확인하는 것
 -관계된 다른 클래스를 사용하는 대신 가짜 객체를 생성해서 사용(Mock객체)
* @RunWith(MockitoJUnitRunner.class)
 -mockito가 제공하는 JUnit 확장 클래스를 이용해 테스트 클래스 실행
* @Mock
 -객체를 생성하지 않아도 자동으로 객체가 생성되고 해당 필드가 초기화 되는 것
* @InjectMocks
 -Mock 객체를 사용하는 객체를 생성하여 초기화하라는 의미
* given()
 -가짜 객체가 동작하는 방법을 규정
 -given(가짜 객체의 동작).willReturn('A') , 동작의 결과가 'A'를 반환하도록 하라는 의미
* verify()
 -verify(가짜 객체).동작(), 가짜 객체의 동작을 호출된 적이 있는지 검증
 
## 7.  
 
# 진행과정 

## 1. 환경 구성

* org.apache.maven.archetypes,  maven-archetype-webapp 으로 시작
* groupId와 artifactId 설정
* properties -> java ee integration -> enable project specific settings check
* pom.xml에 compiler-plugin을 1.8로 설정, 필요한 라이브러리 의존성 추가
* el표기가 안되므로 , web.xml 파일 수정
* .settings/org.eclipse.wst.common.project.facet.core.xml에서 수정
* jst.web 2.3 -> 3.1로 변경.
* 오류 발생시 프로젝트 우클릭 - maven - update project 실행.
* server에 tomcat 8.5 설정
* 추후 database를 이용해야 하므로 계정과 데이터베이스 생성
* create database blog, create user 'username'@'%' identified by 'password', grant all privileges on *.* to 'username'@'%'
