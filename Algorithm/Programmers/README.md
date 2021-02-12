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

**[순위 검색](https://programmers.co.kr/learn/courses/30/lessons/72412)**
```
1. 2중 루프를 통해 풀 수 있지만 최대 50000 * 100000 만큼 걸리므로 비효율적이다.
2. info 배열을 돌며 가능한 쿼리를 모두 만들어 map에 score와 함께 저장 후, query 배열을 돌며 개수를 카운팅
2-1. map에 저장하는 과정에서 istringstream 을 이용하여 빈칸에 맞추어 쉽게 문자열 처리를 함.
3. 개수를 카운팅 하는 과정에서 점수를 이분탐색을 통해 시간을 단축하여 구함. (algorithm 라이브러리의 lower_bound 이용)
```

**[합승 택시 요금](https://programmers.co.kr/learn/courses/30/lessons/72413)**
```
1. 각 노드에서 모든 정점까지의 최소거리를 구해야 하므로 플로이드-와샬 알고리즘 이용.
2. 1의 알고리즘을 이용하여 dist 배열을 갱신 후, 1부터 n까지 노드를 탐색하면서 dist[s][i]+dist[i][a]+disy[i][b] 의 최소값을 찾는다.
```

**[광고 삽입](https://programmers.co.kr/learn/courses/30/lessons/72414)**
```
1. 주어진 영상의 길이 문자열을 초로 만들어 ad배열로 만듬. ( 60*60*100)
2. log 벡터를 돌면서 문자열을 초로 변환하여 구간만큼 ad[i]++
3. 광고의 길이가 고정이므로 투포인터 알고리즘을 이용하여 복잡도 O(n)으로 해결.
3-1. 주의할점은 영상의 누적시간을 구할 때 양 끝점이 모두 포함되지 않는다는 것.
```
