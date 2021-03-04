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

**[3349. 최솟값으로 이동하기](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWDTN0cKr1oDFAWD)**
```
1. 대각선을 이용할 수 있는지 없는지 경우를 나누어서 풀이
2. 새로 이동할 좌표: nx,ny 기존 좌표: x,y 라고 한다면 (nx>x && ny<y) || (nx<x && ny>y) 인 경우 대각선을 이용하지 않음.
3. 대각선을 이용하는 경우, 이용한 만큼 더해주고 각 좌표 차이(nx-x,ny-y)의 차이의 절댓값을 더해준다.
```

**[3459. 승자 예측하기](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWFPoj1qANoDFAV0&categoryId=AWFPoj1qANoDFAV0&categoryType=CODE)**
```
1. N=100일 때 Alice가 이기기 위해선 최소 51을 부르면 됨.(N/2+1)
2. Bob은 Aclie가 51을 못부르게 하기 위해 24를 부르면 됨.(Bob으로서 가장 최선의 방법)(N/2-1)
3. 위와 같은 방식으로 51 24 13 5 3 0..
4. N==1이 되면 Bob의 승리, 그렇지 않다면 Alice의 승리.
```

**[3752. 가능한 시험 점수](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWHPkqBqAEsDFAUn)**
```
1. 입력을 받을 때 max값을 미리 계산 후, score[] 배열의 루프를 돌때 max에서 0까지 돌면서 check가 true면 그 값에 score값을 더한 것도 true로 바꿈.
2. 그후 max값까지 check배열의 루프를 돌면서 true면 count센다.
```

**[3812. 호중이의 큐브색칠](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWH0GF0aBNADFAVB)**
```
1. x,y,z 방향 각각 |x-A| , |y-B|, |z-C| 를 계산하여 배열에 저장.
2. xy방향 계산. ans[(i+j)%n][0] += arr[x][i]*arr[y][j]
3. xy방향 계산 한 것과 z 방향 배열을 2와 같은 방식으로 계산.
```

**[4050. 재관이의 대량 할인](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWIseXoKEUcDFAWN&categoryId=AWIseXoKEUcDFAWN&categoryType=CODE)**
```
1. 3개씩 묶어서 가장 낮은 가격이 공짜이므로 내림차순 정렬을 한다.
1-1. 그 후, 3개씩 묶으면 내림차순 정렬이므로 큰 값을 공짜로 할 수 있다.
```

**[4111. 무선 단속 카메라](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWJHjcFqdyoDFAUH)**
```
1. 카메라의 좌표 차이를 구하기 위해 입력을 오름차순으로 정렬.
2. 카메라의 각 좌표 차이를 오름차순으로 정렬.
3. 수신기가 K대 일때, K-1 개의 구간을 뺄 수 있다. 따라서, 0부터 N-K 까지의 2의 좌표 차이 값들을 더한다.
```

**[4259. 제곱수의 합 계산하기](https://swexpertacademy.com/main/code/problem/problemSolverCodeDetail.do)**
```
1. long long으로 입력을 받아서 두 수를 곱하기엔 999^9가 범위를 벗어나므로 string으로 입력을 받아 각 자리를 계산할때 int형으로 변환하여 계산하는 식으로 진행.
```

**[4261. 빠른 휴대전화 키패드](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWLL7kaaAPsDFAUW&categoryId=AWLL7kaaAPsDFAUW&categoryType=CODE)**
```
1. 사전을 입력 받을 때, S의 길이와 같지 않으면 1차적으로 거름.
2. 미리 키패드의 문자열을 배열로 저장해 놓은 word 배열을 통해 if(word[해당숫자].find(사전의 문자) == string::npos) 면 return false.
* 3중 포문이여서 시간 초과 뜰줄 알았는데, 이게 통과가 되네
```

**[4301. 콩 많이 심기](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWLv-yZah48DFAVV&categoryId=AWLv-yZah48DFAVV&categoryType=CODE)**
```
1. 2차원 배열 m을 true로 초기화한 후, 2중 루프를 돌면서 true인 m[i][j]에 거리가2인 위치들 false로 바꿔줌.
```

**[4366. 정식이의 은행업무](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWMeRLz6kC0DFAXd&categoryId=AWMeRLz6kC0DFAXd&categoryType=CODE)**
```
1. 2진수로 만들 수 있는 모든 경우의 수를 만든후 vector에 저장.
2. 3진수의 자릿수를 바꾸어 가면서 vector에 있는 수와 같은지 비교.
```

**[4408. 자기 방으로 돌아가기](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWNcJ2sapZMDFAV8&categoryId=AWNcJ2sapZMDFAV8&categoryType=CODE)**
```
1. bfs 탐색으로 문제 해결.
2. room,visited,dist 배열 각각 선언.
3. i가 0 또는 2일떄 room 번호를 설정 하고 1일때는 복도이므로 방번호 0으로 초기화
4. 출발지점과 도착지점을 입력으로 받으면 init() 함수를 통해 위치 계산 후, 방향 결정.
5. bfs 탐색을 하면서 반대 방향으로 가거나 다른 방으로 가거나 범위를 벗어나면 continue, 도착지점에 도착하면 return, 복도에 따라 걷는 경우 dist++
```

**[4530. 극한의 청소 작업](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWO6cgzKOIEDFAWw&categoryId=AWO6cgzKOIEDFAWw&categoryType=CODE&&&&&&)**
```
1. 두 입력 A,B가 음수인지 양수인지에 따라 경우를 나뉘어서 계산한다.
2. A<0,B<0일 경우 fn(-A)-fn(-B)
3. A<0,B>0일 경우 fn(-A)+fn(B)-1(0층은 없으므로)
4. A>0,B>0일 경우 fn(B)-fn(A)
5. fn 함수는 숫자를 매개변수로 받아 각 숫자를 10으로 나눈 나머지가 4보다 큰지 작은지에 따라 res에 값을 누적시키는 함수이다.
```

**[4613. 러시아 국기 같은 깃발](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWQl9TIK8qoDFAXj&categoryId=AWQl9TIK8qoDFAXj&categoryType=CODE)**
```
1. 입력을 받은 후, 첫번째 열과 마지막 열을 검사해서 흰색, 빨간색이 아니면 바꿔주고 ans++
2. 2번쨰 줄부터 N-1번째 줄까지 dfs 탐색을 실행.
3. check 배열의 값을 바꿔주면서 dfs 탐색을 실행하는데 이전의 값보다 크거나 같음을 유지해야 한다.
4. 또한, dfs 탐색이 끝난 후엔 N-1배열부터 빨간색이 되므로 3으로 바꿔준다.
```

**[4672. 수진이의 팰린드롬](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWRKNev6fqYDFAV8&categoryId=AWRKNev6fqYDFAV8&categoryType=CODE)**
```
1. 같은 문자가 서로 붙게 만들어서 문자열을 구성하면 팰린드롬의 수가 최대가 된다.
2. 연속으로 붙어있는 문자열의 수 가 n이면 그 개수는 n*(n+1)/2 이다.
```

**[4699. 콩순이의 가장 싼 팰린드롬](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWRurBkKkKADFAXt)**
```
1. 각 문자를 삽입할 때와 제거할때 값중 작은 값을 배열에 저장
2. 문자열이 주어질 때, 처음과 끝이 같지 않을 때까지 길이를 줄여나감.
3. 같지 않은 지점이 왔을 때, 1) 처음 부분을 삽입 or 삭제 2) 끝 부분을 삽입 or 삭제 하면서 길이를 줄여나간다.
```

**[4796. 의석이의 우뚝 선 산](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWS2h6AKBCoDFAVT&categoryId=AWS2h6AKBCoDFAVT&categoryType=CODE)**
```
1. m배열의 루프를 돌면서 숫자가 이전에 비해 증가하면 up++
2. 감소하는 시점에서 up!=0 이면 down++, 그렇지 않다면 pass
3. 해당 index에서 down++했는데 그 다음요소보다 작다면 ans 계산.
```

**[5213. 진수의 홀수 약수](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWT-hF8KdBADFAVT)**
```
1. 2부터 10000000까지 dp배열에 값을 누적시켜 저장
2. 1부터 현재 숫자(i)의 sqrt까지 i에서 나누면서 나누어 떨어지고 홀수 인 것만 R에 누적시킨다.
3. 그 후, i를 j로 나눈 값 또한 R에 누적 시킨다.
```

**[5432. 쇠막대기 자르기](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWVl47b6DGMDFAXm&categoryId=AWVl47b6DGMDFAXm&categoryType=CODE)**
```
1. stack을 이용하여 문제 해결
2. '('일 경우 push하고 ')'일 경우 조건에 따라서 ans에 값을 누적해 나감.
3. ')'일 경우 바로 앞이 '('면 레이저 이므로 stack의 사이즈 만큼 ans에 값을 누적시킨다.
4. 바로 앞이 '('가 아니면 쇠막대기가 닫힌것이므로 1을 더한다.
```

**[5550. 나는 개구리로소이다](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWWxqfhKAWgDFAW4)**
```
1. 첫 문자 c가 들어오면 croak 벡터에 넣어 이후의 문자가 차례로 들어오는지 확인.
2. 1의 과정에서 c이외의 문자가 들어왔을때 check=true로 바꾸어 이외의 문자는 무시.
3. check=false일 경우(첫문자 c가 들어오고 그 다음 문자인 r이 아직 안들어온 경우) 다른 c가 들어온다면 croak배열에 넣음.
```

**[6109. 추억의 2048게임](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWbrg9uabZsDFAWQ&categoryId=AWbrg9uabZsDFAWQ&categoryType=CODE)**
```
1. 입력받은 배열m 을 방향에 따라 계산하여 정답인 ans 배열에 옮김.
2. ans 배열에 값을 넣을 때 cnt를 세서 0이 중간에 들어오지 않게함.
```

**[6719. 성수의 프로그래밍 강좌 시청](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWd7sgDatsMDFAUh&categoryId=AWd7sgDatsMDFAUh&categoryType=CODE)**
```
1. N개의 숫자를 오름차순으로 정렬한 뒤, 뒤에서 K번째부터 ans를 계산하여 누적해 간다.
```

**[6731. 홍익이의 오델로 게임](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWefzFeq5P8DFAUh&categoryId=AWefzFeq5P8DFAUh&categoryType=CODE)**
```
1. 각 위치에서 row,col에 있는 'B'의 개수가 홀수이면 뒤집은 지점이므로 이중 루프를 통해 'B'가 홀수인 지점을 세면 된다.
2. 입력을 받을 때, row,col 배열을 각각 만들어서 'B'의 개수를 카운트 해줌.(이렇게 해주지 않으면 탐색시 제한시간 초과 발생)

```

**[6855. 신도시 전기 연결하기](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWhUBBUqQO0DFAW_&categoryId=AWhUBBUqQO0DFAW_&categoryType=CODE)**
```
1. 도시 사이의 간격을 구해서 최소인 것만 더하면 된다.
2. 발전소의 개수 K개가 정해져 있으므로 K-1개의 도시 사이의 간격을 뺄 수 있다. 따라서 뺄 수 있는 부분을 최대로 하면 된다.
3. 도시 사이의 간격을 vector에 담아서 오름차순으로 정렬후 index 0부터 N-K까지 더하면 된다.
```

**[6959. 이상한 나라의 덧셈게임](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWjlH0k63joDFAVT&categoryId=AWjlH0k63joDFAVT&categoryType=CODE)**
```
1. 숫자가 주어지면 어떤 방법을 쓰든 결과는 이미 정해져있다.
2. 입력을 문자열로 받아서 stack에 쪼개서 넣은뒤, stack의 크기가 1이될 때까지 두 수의 덧셈을 진행한다.
3. 2의 과정시 덧셈을 진행하는 cnt를 세서 짝수면 B의 승리, 홀수면 A의 승리다.
```

**[7088. 은기의 송아지 세기](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWkIeU76A9cDFAXC)**
```
1. segment Tree algorithm으로 해결
2. struct Tree를 선언하여 1-3번 품종(q1,q2,q3)을 변수로 선언하고 struct끼리 덧셈을 진행하기 위해 연산자 오버로딩 선언
3. 배열 m에 입력을 받고 init() 메소드를 통해서 segment Tree 구성.
4. Q만큼 left,right가 입력으로 주어졌을 때, sum() 메소드를 통해서 1-3번 품종의 개수 return.
```

**[7103. 준홍이의 네 개의 제곱수](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWkImrCqBeoDFAXC)**
```
1. 제곱수가 최대 4개까지의 합으로 N이 이루어질 수 있으므로 3중 루프를 통해서 n1,n2,n3 값을 구하고 n3의 제곱근 값이 정수이면 ans++
```

**[7194. 화섭이의 미생물 배양](https://swexpertacademy.com/main/code/problem/problemSolverCodeDetail.do)**
```
1. b가 1일때와 아닐때의 경우를 나누어서 풀이
2. b가 1일때는 T-S가 a로 나누어떨어지는지의 여부에 따라 결정됨.
3. b가 1일 아닐 때는 T가 S보다 클때 루프를 반복하면서 b로 나뉘어 떨어지면 나누고 아니면 a를 빼는 방식으로 진행.
```

**[7338. 현규의 연봉계산법](https://swexpertacademy.com/main/code/problem/problemDetail.do?problemLevel=4&contestProbId=AWmYcWyqAcQDFAV3&categoryId=AWmYcWyqAcQDFAV3&categoryType=CODE&problemTitle=&orderBy=FIRST_REG_DATETIME&selectCodeLang=ALL&select-1=4&pageSize=10&pageIndex=5)**
```
1. 입력받은 Y,M에 대해 그 차이가 총 몇개월 인지 구한다.
2. 13으로 나눈 몫만큼 2016년에서 더하고 13으로 나눈 나머지만큼 1에서 더한다.
```

**[1767. [SW Test 샘플문제] 프로세서 연결하기](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV4suNtaXFEDFAUf)**
```
1. 가장자리가 아닌 core를 vector에 push
2. dfs로 완전탐색을 하면서 4방향을 검사하여 전선을 이을 수 있다면 그 길이를 2로 설정
3. 4방향이 안된다면 index 증가시킨 후 다시 dfs 
```

**[7333. 한솔이의 택배 아르바이트](https://swexpertacademy.com/main/code/problem/problemDetail.do?problemLevel=4&contestProbId=AWmYaDf6AWQDFAV3&categoryId=AWmYaDf6AWQDFAV3&categoryType=CODE&problemTitle=&orderBy=FIRST_REG_DATETIME&selectCodeLang=ALL&select-1=4&pageSize=10&pageIndex=5)**
```
1. 입력을 오름차순으로 정렬후, left와 right 2개의 index를 잡아 비교하면서 풀이
2. right의 값이 50이상이면 ans++, right--
3. 그렇지 않다면 left의 값을 더하면서 cnt*right의값이 50이상될때까지 left++
4. 전체 루프를 빠져나오면 s==e일 경우를 고려해줘서 ans++;
```

**[7393. 대규의 팬덤활동](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWm8gU7KljcDFASj)**
```
1. bitmask dp를 이용하여 풀이 (해결하지 못해서 답 참조)
2. 배열 [길이][0~9][2^10] 으로 설정하여 m[101][11][1024] 설정 ( 0~9까지 10이지만 dfs 탐색 도중 탐색 시간을 줄이기 위해 ret을 검사하는 과정에서 num이 10이 들어올 수 있으므로 11로 잡음)
3. ans는 1~9로 시작하면서 길이가 1에서 n일때까지 dfs 탐색을 한다.
4. 탐색 과정에서 msk |= (1<<num) 연산을 통해 해당 숫자가 포함되게 한다.
5. 길이가 n일 되었을 때 msk의 값이 1023이면 0~9까지의 숫자가 모두 들어있는 것이므로 1을 return
6. 따라서 bottom-up 방식으로 dfs를 진행해 값을 채워 나감.
```

**[7465. 창용 마을 무리의 개수](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWngfZVa9XwDFAQU)**
```
1. 두 사람 x,y에 대해 입력으로 받아 edge 배열에 저장
2. 1부터 N까지 dfs탐색을 하면서 연결되어 있고 방문하지 않은 상태라면 dfs
```

**[7701. 염라대왕의 이름 정렬](https://swexpertacademy.com/main/code/problem/problemDetail.do?problemLevel=4&contestProbId=AWqU0zh6rssDFARG&categoryId=AWqU0zh6rssDFARG&categoryType=CODE&problemTitle=&orderBy=FIRST_REG_DATETIME&selectCodeLang=ALL&select-1=4&pageSize=10&pageIndex=5)**
```
1. 입력을 set에 저장하여 중복 제거
2. set을 vector에 담은 후 cmp 비교 함수를 통해 
```

**[7699. 수지의 수지 맞는 여행](https://swexpertacademy.com/main/code/problem/problemDetail.do?problemLevel=4&contestProbId=AWqUzj0arpkDFARG&categoryId=AWqUzj0arpkDFARG&categoryType=CODE&problemTitle=&orderBy=FIRST_REG_DATETIME&selectCodeLang=ALL&select-1=4&pageSize=10&pageIndex=5)**
```
1. dfs 탐색을 하면서 방문한 문자열을 체크해서 다시 방문하지 못하게 한다.
```

**[7733. 치즈 도둑](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWrDOdQqRCUDFARG)**
```
1. 초기 입력을 받을 때 숫자에 대한 정보를 map에 넣음.
2. 1일차부터 maxn까지 세면서 해당 숫자 날짜를 0으로 만들어 bfs 탐색 진행.
```

**[7792. 반장 선출](https://swexpertacademy.com/main/code/problem/problemDetail.do?problemLevel=4&contestProbId=AWsBNHuqMMADFARG&categoryId=AWsBNHuqMMADFARG&categoryType=CODE&problemTitle=&orderBy=FIRST_REG_DATETIME&selectCodeLang=ALL&select-1=4&pageSize=10&pageIndex=4)**
```
1. 공백을 포함하여 입력을 받아야 하므로 getline(cin,str)로 입력을 받음.
2. 알파벳이 많이 포함되어 있는 것을 찾아야 하므로 입력받은 str의 길이만큼 루프를 돌면서 set에 char을 넣어 갯수를 구함.
3. 2의 과정에서 ' '(space)가 포함되지 않도록 주의.
```

**[7810. 승현이의 질문](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWslG2zqFQcDFASy)**
```
1. 이분 탐색 알고리즘으로 풀이
2. 입력으로 받은 숫자를 cnt배열에 증가시킴.
3. 최댓값부터 0까지 값을 줄여가며 이전값을 누적해서 더해나감(현재자리 이 후로 숫자가 몇개 있는지 저장)
4. 이분 탐색을 하면서 조건에 만족하면 ans 값 
```

**[7829. 보물왕 태혁](https://swexpertacademy.com/main/code/problem/problemDetail.do?problemLevel=4&contestProbId=AWtInr3auH0DFASy&categoryId=AWtInr3auH0DFASy&categoryType=CODE&problemTitle=&orderBy=FIRST_REG_DATETIME&selectCodeLang=ALL&select-1=4&pageSize=10&pageIndex=4)**
```
1. 입력을 오름차순으로 정렬 후 처음과 가장 마지막 수를 곱하면 된다.
```

**[7854. 최약수](https://swexpertacademy.com/main/code/problem/problemDetail.do?problemLevel=4&contestProbId=AWttVkiq5jEDFASy&categoryId=AWttVkiq5jEDFASy&categoryType=CODE&problemTitle=&orderBy=FIRST_REG_DATETIME&selectCodeLang=ALL&select-1=4&pageSize=10&pageIndex=4)**
```
1. 각 자리수에 따라 최약수가 정해져 있음, 3자리까지는 고정 이후로는 3자리 수에서 뒤에 0만 붙이면됨
2. 입력받은 X의 길이에 따라 맞게 처리하고 길이가 3이상부터 앞의 3자리만 substr해서 3자리 수의 최약체 수 배열을 돌며 크기 
```

**[7965. 퀴즈](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWuSh2IKmu0DFASy)**
```
1. dp배열에 값을 누적해서 쌓아가는 방식으로 풀이.
2. pows 함수를 통해 n^n을 계산.
3. 2의 과정에서 10^10 = 10^5 * 10^5 의 특성을 이용하여 풀이.
```

**[7988. 내전 경기](https://swexpertacademy.com/main/code/problem/problemDetail.do?problemLevel=4&contestProbId=AWvQZmdKUoEDFASy&categoryId=AWvQZmdKUoEDFASy&categoryType=CODE&problemTitle=&orderBy=FIRST_REG_DATETIME&selectCodeLang=ALL&select-1=4&pageSize=10&pageIndex=4)**
```
1. 입력을 받으면서 map<string,int> 에 저장. m.count(s1)의 값이 0이라면 새로운 값이므로 node 번호 할당.
2. 1의 과정을 진행하면서 동시에 edge 연결 정보 저장.
3. 0번 node부터 n번까지 진행하면서 i번째 node의 색이 바뀌지 않았다면 dfs 탐색시작.
4. 자신과 연결된 node의 색은 모두 다르게 색칠한다. 그래야 시너지 효과가 발생하지 않는다.
```

**[8049. 폭탄 감식반](https://swexpertacademy.com/main/code/problem/problemDetail.do?problemLevel=4&contestProbId=AWv0_-j6aRsDFASy&categoryId=AWv0_-j6aRsDFASy&categoryType=CODE&problemTitle=&orderBy=FIRST_REG_DATETIME&selectCodeLang=ALL&select-1=4&pageSize=10&pageIndex=4)**
```
1. FF~MCM~ 의 경우를 탐색
1-1. find() 메소드를 통해 "MCM" 문자열의 위치를 찾고 없다면 탐색 종료
1-2. 찾았다면 해당 위치부터 "MCM"만큼 visit 배열에 true로 바꾸고 앞의 위치에서 F를 탐색 후, 뒤에서 M을 탐색
2. FC~MF 의 경우를 탐색
2-1. 1과 마찬가지 경우로 탐색.
```

**[8382. 방향 전환](https://swexpertacademy.com/main/code/problem/problemDetail.do?problemLevel=4&contestProbId=AWyNQrCahHcDFAVP&categoryId=AWyNQrCahHcDFAVP&categoryType=CODE&problemTitle=&orderBy=FIRST_REG_DATETIME&selectCodeLang=ALL&select-1=4&pageSize=10&pageIndex=4&&&&&&&&&&)**
```
1. 두 좌표의 차이 x,y에 대해서 더 작은 값의 2배만큼 이동할 수 있다.
2. 그 후, x,y에서 각각 최솟값을 빼면 둘 중 하나는 0이 된다. 그러면 일직선 상에서 이동 경로를 찾으면 된다.
3. 일직선 상의 경로가 짝수면 2배이고 홀수면 2배 -1 해주면된다.
```

**[8424. 유일한 사이클](https://swexpertacademy.com/main/code/problem/problemDetail.do?problemLevel=4&contestProbId=AWyxsBd6lyADFAVP&categoryId=AWyxsBd6lyADFAVP&categoryType=CODE&problemTitle=&orderBy=FIRST_REG_DATETIME&selectCodeLang=ALL&select-1=4&pageSize=10&pageIndex=3)**
```
1. 노드의 연결정보를 edge 배열에 담은 후, dfs 탐색 시작
2. check배열에 각 노드의 depth를 기록하고 dfs 탐색을하면서 check배열이 0이 아니고 next와 prev가 다르다면 사이클 완성이으므로 ans을 갱신해준다.
3. 사이클은 총 1개이므로 ans 갱신후 ans가 0이 아니라면 함수를 종료 시켜준다.
```

**[8458. 원점으로 집합](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWzaq5KKk_ADFAVU)**
```
1. 좌표와 영점 사이의 거리를 계산해 dist 배열에 저장
2. 짝수와 홀수의 개수를 각각 세서 짝수와 홀수가 동시에 있다면 절대 영점으로 같이 보낼 수 없으므로 -1 출력
3. 짝수와 홀수 중 각각 최대인 값을 x에 저장하여 y에 1,2,3,4,...값을 누적시켜 더해가면서 y>=x 이고 x,y가 각각 2로 나눈 나머지가 같은지 다른지 탐색.
```

**[8501. 은비의 동전 뒤집기](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWz50CHK8DgDFARQ)**
```
1. dp[3]=5
1 2 3 / 1
1 3 2 / 2
2 1 3 / 1
2 3 1 / 1
3 1 2 / 0
3 2 1 / 0
2. dp[4]는 위의 각 자리에 4를 넣는 것.
2-1. 첫째 자리에 4를 넣으면 (4) 1 2 3 , (4) 1 3 2 , ... 기존과 같다.
2-2. 그 다음에 4를 넣으면 4가 앞면이 되므로 그것만큼 추가해줘야한다. (4-1)!
2-3. 4가 앞면이 되는 경우의 수를 고려해보면 4 앞의 수가 홀수개 이면 추가해준다.
3. 즉, dp[4] = dp[3] + ((n-1)! + dp[3]) + dp[3] + ((n-1)! + dp[3]) 이다.
4. 일반화 하면 dp[n] = n*dp[n-1] + (n/2)*(n-1)!
```

**[8567. 약수의 개수가 많은 수](https://swexpertacademy.com/main/code/problem/problemDetail.do?problemLevel=4&contestProbId=AW1B2yIa28MDFARC&categoryId=AW1B2yIa28MDFARC&categoryType=CODE&problemTitle=&orderBy=FIRST_REG_DATETIME&selectCodeLang=ALL&select-1=4&pageSize=10&pageIndex=3)**
```
1. 2부터 10^5+1까지 루프를 돌면서 cnt와 dp 배열을 채운다.
2. cnt배열은 숫자 i의 약수의 개수를 담은 배열이고, dp배열은 숫자 1~i까지 중 약수의 개수가 가장 많은 숫자를 담은 배열이다.
3. 매 루프마다 cnt,dp 배열을 채워나가면 해결.
```

**[8568. 3으로 나눈 순열](https://swexpertacademy.com/main/code/problem/problemDetail.do?problemLevel=4&contestProbId=AW1B8rJq3NUDFARC&categoryId=AW1B8rJq3NUDFARC&categoryType=CODE&problemTitle=&orderBy=FIRST_REG_DATETIME&selectCodeLang=ALL&select-1=4&pageSize=10&pageIndex=3)**
```
1. 선택정렬을 이용하여 해결.
2. 배열 끝까지 탐색했을 때 스왑을 하지 못한다면 cnt++
3. cnt가 증가 되었다면 스왑을 하지 못했으므로 최소 3개의 숫자가 자리를 바꾸지 못한 것이다. 그럴 경우 2번 이동해야 하므로 (cnt/3)*2의 값을 ans에 더해준다.
```

**[8676. 동현이와 한결이는 아이돌](https://swexpertacademy.com/main/code/problem/problemDetail.do?problemLevel=4&contestProbId=AW2Jo6bqABMDFATy&categoryId=AW2Jo6bqABMDFATy&categoryType=CODE&problemTitle=&orderBy=FIRST_REG_DATETIME&selectCodeLang=ALL&select-1=4&pageSize=10&pageIndex=3)**
```
1. dynamic programming으로 해결(풀지 못해서 다른 사람 코드를 참조)
2. 'SAMSUNG' 길이에 맞게 dp 배열을 선언후 0으로 초기화한다.
3. 입력된 문자열을 탐색하면서 'S'의 경우 0,3 인덱스를 이전의 값과 자신의 값을 더해 누적시켜 나간다. (dp[i] = dp[i-1] + dp[i])
```

**[8659. GCD](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AW1l1s2KWn4DFARC)**
```
1. GCD를 K번 진행했을 때, 가장 작은 A,B 조합을 구해야 하므로 GCD(1,0) 인 경우에서 역으로 올라가 계산하면 된다.
```

**[10994. 동전 수집](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AXXjAdya60IDFAST)**
```
1. 입력받은 배열 c만큼 루프를 돌면서 sum을 누적시키면서 조건을 만족할 때 개수를 증가시킨다.
2. sum + c[i]가 k보다 크거나 같으면 break;
3. d[i]가 1이 아니라면 새로운 동전을 얻는 경우 이므로 검사한다.
4. sum + c[i] < c[i+1] 인 경우에만 sum을 증가시켜주어야 한다. 거스름돈의 조건중 A센트 이하만큼 거슬러 주기 때문.
```
