# 블로그 만들기

## 목차

* [개발 환경](#개발-환경)
* [개념 정리](#개념-정리)
  * [Maven](#1-Maven)
  * [JDBC](#2-JDBC)
  * [Scope](#3-Scope)
  * [EL](#4-EL-&-JSTL)
  * [Spring](#5-Spring)
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

* 


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
