**[10912. 외로운 문자](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AXVJuEvqLAADFASe&categoryId=AXVJuEvqLAADFASe&categoryType=CODE)**
```
1. map에 문자열의 각 char을 카운트 하여 넣는다.
2. map에서 value의 값을 2로 나눈 나머지 값을 다시 넣는다.(둘씩 짝지어야 하기 때문)
3. value가 0이 아닌 값들을 ans에 
```

**[10804. 문자열의 거울상](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AXTC0x16D8EDFASe&categoryId=AXTC0x16D8EDFASe&categoryType=CODE)**
```
1. 단순구현
```

**[10761. 신뢰](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AXSVc1TqEAYDFAQT)**
```
1. blue,orange의 각 pos와 time , 전체 time을 변수로 잡는다.
2. N만큼의 루프를 돌면서 'B' or 'O' 일때, 새로 이동할 위치(pos)와 현재위치(b_pos,o_pos)와의 차이가 전체 time과 각 time(b_time,o_time)의 차이보다 크다면
time = abs(pos-b_pos,o_pos)+1(버튼누름)+b_time,o_time(현재위치의 시간)
2-1. 그렇지 않다면 버튼만 누르면 되므로 time+=1
```

**[10726. 이진수 표현](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AXRSXf_a9qsDFAXS&categoryId=AXRSXf_a9qsDFAXS&categoryType=CODE&&&)**
```
1. N만큼 M을 2로 나누면서 나머지가 1이 나오면 조건 만족.
```

**[10570. 제곱 팰린드롬 수](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AXO72aaqPrcDFAXS&categoryId=AXO72aaqPrcDFAXS&categoryType=CODE)**
```
1. dp 배열을 만들어서 i*i<=B까지 루프를 돌면서 제곱 팰린드롬수이면 dp[i*i]=true
```

**[10580. 전봇대](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AXO8QBw6Qu4DFAXS&categoryId=AXO8QBw6Qu4DFAXS&categoryType=CODE)**
```
1. 입력받은 a,b 를 a가 작은 순으로 오름차순 정렬.
2. i를 증가시키면서 j=i-1로 잡고 j--하면서 v[i].second보다 큰값이 나오면 ans++;
```

**[10505. 소득 불균형](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AXNP4CvauaMDFAXS&categoryId=AXNP4CvauaMDFAXS&categoryType=CODE)**
```
1. 입력을 받으면서 vector에 저장하면서 전체 숫자의 합 tot을 구함.
2. tot을 통해 평균을 구하고 vector을 돌면서 평균이하의 것들 ans++
```

**[10200. 구독자 전쟁](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AXMCXV_qVgkDFAWv&categoryId=AXMCXV_qVgkDFAWv&categoryType=CODE)**
```
1. A와 B중 최소값이 최댓값
2. A+B>N이면 A+B-N 값이 교차점이 
```

**[10059. 유효기간](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AXK6YRNaKq0DFAU3&categoryId=AXK6YRNaKq0DFAU3&categoryType=CODE)**
```
1. 주어진 입력을 2자리씩 나누어서 판별.
```

**[10805. 야바위](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AXTC3GH6D-EDFASe)**
```
1. 공의 위치 pos=1로 잡고 속임수를 써서 가능한 후보 candidate 배열을 시작과 동시에 q의 루프를 돌때마다 갱신시켜준다.
2. pos가 n보다 작으면 pos+1로 순간이동 가능, pos가 1보다 크면 pos-1로 순간이동 가능
```

**[10571. 잔디 깎기](https://swexpertacademy.com/main/code/problem/problemSolverCodeDetail.do)**
```
1. row,col 배열을 각각 100씩 초기화
2. 2중루프를 돌면섯 100-land[i][j] 최소값을 각각의 위치에 저장. ( land의 가장 높은 위치 알 수 있음)
3. 2중루프를 돌면서 각 위치에서 row와 col의 최솟값중 100에서 뺀 값이 land[i][j]와 같은지 확인.
```

**[9942. 순열2](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AXHx5_FK0UUDFAXR&categoryId=AXHx5_FK0UUDFAXR&categoryType=CODE)**
```
1. 길이가 N인 한 수열의 배치는 N!
2. 다른 수열은 내림차순으로 시작하여 dfs 탐색하면됨.
3. score>=k인 시점에서 방문하지 않은 개수(m) 탐색후 factorial을 구해서 누적(m!가지의 배치 경우의수)
```

**[9708. 가장 긴 수열](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AXDNGXlKagUDFAVX)**
```
1. dp[num[i]]=1로 초기화, num[i]를 계속 더하면서 num[N-1]보다 같거나 작을때까지 반복하면서 dp배열 갱신.
```

**[5293. 이진 문자열 복원](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWUiwoe6o00DFAVT)**
```
1. 문자열이 0,1로 시작하는 2가지 경우로 나누어서 dfs 시작.
2. 01,10 같은 경우에는 010 ,101 처럼 0과 1이 번갈아 나와야만 하므로 01의 개수 b와 10의 개수 c는 서로 같거나 차이가 1이여야한다.
```

**[4371. 항구에 들어오는 배](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWMedCxalW8DFAXd)**
```
1. N만큼 입력을 받으면서 해당 날에는 check[num]=true로 초기화, num-1을 vector에 push
2. vector 루프를 돌면서 1에서 v[i]만큼 계속 증가시키면서 check[num]이 true라면 총개수 n(N-1,1을 제회한 즐거운날)에서 1씩 뺀다, check[num]=true로 바꿈.
3. 2과정을 통해 true로 바꾼 날이 존재하면 bool up=true로 바꾸고 ans++
```

**[5642. [Professional] 합](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWXQm2SqdxkDFAUo)**
```
1. num을 더해가면서 sum이 음수가 나오면 0으로 초기화.(음수인 상태로 더해도 max값이 나오지 않기 때문)
2. 주어진 num이 모두 음수일 경우를 고려.
```

**[1231. [S/W 문제해결 기본] 9일차 - 중위순회](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV140YnqAIECFAYD)**
```
1. Tree[100][3]에 각 값을 입력 받아 넣는다. 0 -> data, 1-> left, 2->right
2. 1부터 함수를 재귀적으로 호출하면서 left가 없을때까지 호출 -> ans배열에 char 저장
3. right 없을 때까지 호출 -> ans배열에 char 저장.
```

**[1494. 사랑의 카운슬러](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV2b_WPaAEIBBASw)**
```
1. N/2까지 dfs 함수를 재귀호출하면서 선택한 num은 chk 배열에 true로 저장.
2. dfs 탐색을 통해 min값을 구하여 
```

**[1808. 지희의 고장난 계산기](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV4yC3pqCegDFAUx)**
```
1. 숫자로 조합할 수 있는 모든 숫자를 입력받은 N보다 작다면 num에 계속 push_back
2. N을 num의 숫자로 나눠보면서 dynamic programming 기법으로 해결.
```

**[1824. 혁진이의 프로그램 검증](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV4yLUiKDUoDFAUx)**
```
// 코드상 잘 돌아가는데 제출하면 런타임 에러라고 뜸.
1. dfs로 탐색을 하는데 visit했다면 return false
2. 탐색 시간을 감소시키기 위해 fail 배열을 만듦.
```

**[1861. 정사각형 방](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5LtJYKDzsDFAXc)**
```
1. 배열 m를 [1001][1001][2]로 지정해서 0-> 주어진 방의 값, 1-> 탐색으로 찾아진 이동할 수 있는 방의 수
2. 이중 루프를 돌면서 ans_cnt와 ans_start를 구함.
```

**[1865. 동철이의 일 분배](https://swexpertacademy.com/main/solvingProblem/solvingProblem.do)**
```
1. 그냥 dfs로 풀면 제한시간 초과 발생.
2. dfs로 탐색하면서 유망성 검사.
3. 현재 확률 p에서 다음 확률을 곱한 값이 ans보다 크면 유망. (최댓값을 한번 계산한 시점부터 적용)
```

**[1868. 파핑파핑 지뢰찾기](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5LwsHaD1MDFAXc&categoryId=AV5LwsHaD1MDFAXc&categoryType=CODE)**
```
1. 8방향으로 지뢰가 없는 지점 찾고 bfs탐색 시작
2. 탐색하면서 방문했던 곳은 visit[i][j]=true로 하고 find_zero()를 통해 8방향이 모두 지뢰가 없으면 q에 push
```

**[2819. 격자판의 숫자 이어 붙이기](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV7I5fgqEogDFAXB&categoryId=AV7I5fgqEogDFAXB&categoryType=CODE)**
```
1. dfs로 탐색을 하면서 길이가 7이면 set에 
```

**[3000. 중간값 구하기](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV-fO0s6ARoDFAXT)**
```
1. multiset을 이용하여 입력받은 a,b를 insert하면서 a,b의 값과 mid와의 관계에 따라 iterator를 조정해서 ans에 더해나감.
```

**[3064. Binary Indexed Tree](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV_Wo_Sa6UEDFAXw)**
```
1. segment tree algorithm을 이용하여 해결.
2. 특정 원소를 수정하는 update와 구간 합을 구하는 sum 함수로 구성.
```

**[3074. 입국심사](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV_XEokaAEcDFAX7)**
```
1. 이분탐색으로 해결
2. 사람 수 = 주어진 시간 / 창구마다 걸리는 
```

**[3124. 최소 스패닝 트리](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV_mSnmKUckDFAWb)**
```
1. kruscal algorithm을 이용하여 해결.
2. swea 제출시에 따로 class 선언한 부분에 연산자 오버로딩이 있으면 채점이 안된다.
```

**[3143. 가장 빠른 문자열 타이핑](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV_65wkqsb4DFAWS&categoryId=AV_65wkqsb4DFAWS&categoryType=CODE)**
```
1. find함수를 통해 string::pos가 아니면 문자열 A에 B가 있으므로 그 부분만큼 ans에서 빼주는 방식으로 해결.
```

**[3234. 준환이의 양팔저울](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWAe7XSKfUUDFAUw)**
```
1. 입력을 받을 때 half값을 미리 계산하여 dfs로 풀때 left가 half보다 크면 그 이후에 넣는 것들은 left,right 상관 없으므로 2^N * N!을 ans에 더한다.
2. visit 배열을 선언해서 이미 넣는지 안넣었는지 확인.
3. 2^N*N! 계산을 위해 미리 factorial계산을 테스트 케이스 실행전에 한번 실행.
```

**[3289. 서로소 집합](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWBJKA6qr2oDFAWr&categoryId=AWBJKA6qr2oDFAWr&categoryType=CODE)**
```
1. kruscal's algorithm을 이용하여 해결.
2. parent 배열을 각 index의 자신으로 초기화(ex. parent[1]=1)
3. c==0이면 a와b를 getParent 함수를 통해 parent 배열에 저장된 값을 불러오고 그 중 작은 값으로 원소를 포함시킨다.
4. c==1이면 a와b를 getParent 함수를 통해 parent 배열에 저장된 값을 불러와서 같은지 다른지 확인.
```

**[3316. 동아리실 관리하기](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWBnFuhqxE8DFAWr&)**
```
1. A,B,C,D를 각각 2^0,2^1,2^2,2^3으로 지정. (B가 관리자라면 1 << ('B'-A') ==> 2)
2. 관리자 배열 s의 길이만큼 루프를 돌면서 dp배열에 값을 누적시켜 나가는 방식으로 풀이
3. 1일차와 그 외로 나눠서 조건을 줘야함.
3-1. 1일차일때, A에게 열쇠를 무조건 주므로, (A가 포함되어 있고 && A가 관리자인 경우) dp=1
3-2. 그 외의 경우, 이전날의 dp배열이 0이 아닌 경우에 진행, (관리자가 있고 && 전날의 배치와 현재의 배치가 같을때) 현재dp+= 이전dp
4. 각 연산 진행시  1000000007로 나눈 나머지 값을 저장하도록 연산 진행.
```
