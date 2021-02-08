**[신규 아이디 추천](https://programmers.co.kr/learn/courses/30/lessons/72410)**
```
1. 총 7단계를 각각 함수로 나누어서 코드 작성 (어려운 점은 없으므로 생략)
```

**[메뉴 리뉴얼](https://programmers.co.kr/learn/courses/30/lessons/72411)**
```
1. brute force 방식으로 풀이
2. orders 배열을 돌며 각 문자열을 오름차순으로 정렬하여 가능한 조합을 만들어 map에 저장.
3. cnt배열을 만들어 길이가 i인 문자열의 개수를 설정(이후 course 배열 탐색시 2이상이 아니면 거르기 위해)
4. menu[i][j] 벡터를 만들어 길이가 i인 문자열이 j번 나온 문자열을 push_back
```
