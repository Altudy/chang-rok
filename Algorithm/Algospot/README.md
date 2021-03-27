# [쿼드 트리 뒤집기](https://www.algospot.com/judge/problem/read/QUADTREE)

1. 분할 정복 알고리즘
2. 주어진 문자열을 쪼개는 부분이 일정하지 않으므로 string::iterator을 이용
3. 문자가 'w'나 'b'면 그 값을 리턴하고 아니라면 4부분에 대해 함수 재귀 호출 실행.
4. 다시풀기

# [울타리 잘라내기](https://www.algospot.com/judge/problem/read/FENCE)

1. 분할 정복 알고리즘
2. mid 기준으로 1)왼쪽 2)오른쪽 3) mid를 포함한 값 중 max값을 리턴하며 함수 재귀 호출 실행.
3. left와 right가 같다면 현재 index의 height 리턴
4. 2에서 3)을 계산할 때, lo=mid, hi=mid+1로 초기화하고 lo-1과 hi+1 값을 비교하면서 높이가 더 높은 쪽으로 확장.
5. 다시풀기

# [외발 뛰기](https://www.algospot.com/judge/problem/read/JUMPGAME)

1. 동적 계획법
2. 시작점에서 게임판을 벗어나지 않는 한에서 아래, 오른쪽 방향으로 dfs 탐색을 해나간다.
3. 탐색 과정에서 이전에 탐색한 지점을 다시 탐색할 가능성이 있으므로 메모이제이션 한다.
3-1. (x,y) = (x+jumpsize,y) || (x,y+jumpsize)

# [와일드카드](https://www.algospot.com/judge/problem/read/WILDCARD)

1. 동적 계획법
2. 와일드카드 W와 입력받은 S를 비교하면서 가능하면 ans에 push_back
3. match 함수의 인자로 w,s를 주고 각 자리의 문자를 비교하면서 pos 증가
3-1. w[pos] == s[pos] || w[pos]=='?' , pos < w.size() && pos < s.size()
4. 3의 while문을 빠져나오면 w[pos]=='\*' 든지 두 문자열이 모두 일치하는 경우임.
5. w[pos]=='\*' 인 경우, skip을 얼마나 할 수 있을지 결정해주면서 match함수 진행, 만약 한번이라도 true값이라면 true를 리턴.
6. 5까지의 방법으로 하면 완전탐색이므로 각 \*에 대응되는 글자 수의 모든 조합을 검사하므로 시간이 오래 걸림.
7. 또한, 수행하는 과정에서 계산의 중복이 발생하므로 메모이제이션으로 처리
8. match 함수의 인자로 W와 S의 시작 index를 줌.
9. w의 위치와 s의 위치에서 이미 false가 나왔다면 이 값을 메모해줌. cache[w][s]
10. 따라서 함수를 시작하기 전에 cache[w][s]값이 이미 계산되었다면 그 값을 리턴하고 그렇지 않다면 3-1,4,5의 과정을 통해 계산한 값을 리턴해줌.
11. 다시풀기

# [삼각형 위의 최대 경로](https://www.algospot.com/judge/problem/read/TRIANGLEPATH)

1. 동적 계획법
2. top-down, bottom-up 두 가지 방식으로 해결 가능.
3. bottom-up 시 triangle 배열을 다음 테스트케이스 진행할 때마다 0으로 초기화 해주어야함.
4. dp[i][j] = max(dp[i+1][j],dp[i+1][j+1]) + triangle[i][j] -> top-down
5. return ret = max(dfs(i+1,j),dfs(i+1,j+1)) + triangle[i][j]; -> bottom-up

# [최대 증가 부분 수열](https://algospot.com/judge/problem/read/LIS)

1. 동적 계획법
2. bottom-up 방식으로 해결
3. 현재 위치 idx에서 idx+1부터 n-1까지 검사하는데 num[idx] < num[i] 인경우 dp의 현재값과 탐색한 값에 1 더한 값중 max 값을 저장.
4. 다시풀기

# [합친 LIS](https://algospot.com/judge/problem/read/JLIS)

1. 동적 계획법
2. 최대 증가 부분 수열의 해법과 비슷
3. dfs(inxA,idxB) = max( max(idxA+1,idxB)+1 , max(idxA,idxB+1)+1 )
4. 

# [원주율](https://algospot.com/judge/problem/read/PI)

1. 동적 계획법
2. 길이가 3인 조각의 난이도 + 3글자 빼고 나머지 수열의 최적해
2-1. 길이가 4인 조각의 난이도 + 4글자 빼고 나머지 수열의 최적해
2-2. 길이가 5인 조각의 난이도 + 5글자 빼고 나머지 수열의 최적해
3. 2,2-1,2-2에 해당하는 값중 max 값을 구하면 됨.
4.  dp[idx] = L(3~5) max(dfs(idx+L) + 난이도 계산 함수())
5.  다시풀기

# [Quntization](https://algospot.com/judge/problem/read/QUANTIZE)

1. 동적 계획법
2. 맨 앞에서부터 하나씩 채워 나가는 접근 방법을 택함.(주어진 수열 A의 첫 번째 숫자를 어떤 숫자로 표현할 것인지를 결정하고, 나머지 수열에 대해 재귀호출)
2-1. 사용할 수 있는 숫자의 가짓수에 제한이 걸려있기 때문에 남은 문제를 재귀적으로 해결할 때는 이전까지 사용한 숫자들을 무시할 수 없음.(최소 부분 조건의 성립x)
2-2. 2의 함수에 인자로 이전까지 사용한 숫자들의 집합 U를 입력으로 받아 구현하게 된다면 U의 크기만 해도 10인 경우에 1000C10 이므로 오래 걸림.

3. 답이 항상 어떤 구조를 가질 것이라고 예상.
3-1. a<b일 때 a에 대응되는 숫자는 b에 대응되는 숫자보다 항상 작음.
3-2. 주어진 수열 A를 오름차순 정렬한 뒤 s개의 묶음으로 나누어 최소 오류 제곱 합을 구하면 됨.
3-3. 첫 묶음의 크기를 x로 정하면 나머지 n-x개의 숫자를 s-1개의 묶음으로 나누면 됨.
3-4. ret = min(ret,minError(from,from+x-1)+dfs(from+x,s-1));

4. minError를 O(1)로 계산하기 위해 부분합과 부분제곱합을 각각 계산함.(pSum[i]=pSum[i-1]+A[i] , pSqSum[i]=pSqSum[i-1]+A[i]*A[i])
4-1. 미분을 통해 (A[i]-m)^2 를 계산하여 m의 값을 구할 수 있음. (m을 구할 시 평균에 가장 가까운 정수를 구해야하므로 반올림한 값을 사용)
5. 

# [삼각형 위의 최대 경로 개수 세기](https://algospot.com/judge/problem/read/TRIPATHCNT)

1. 동적 계획법
2. (삼각형 위의 최대 경로)를 구한 후 dp배열을 하나 더 만들어 동적 계획법으로 풀이
3. (x,y)에서 dp1[x+1][y] 와 dp1[x+1][y+1]의 크기를 비교하여 dp2[x][y]를 초기화
3-1. dp1[x+1][y] > dp1[x+1][y+1] 의 경우, dp2[x][y] = solve2(x+1,y)
3-2. dp1[x+1][y] < dp1[x+1][y+1] 의 경우, dp2[x][y] = solve2(x+1,y+1)
3-3. dp1[x+1][y] == dp1[x+1][y+1] 의 경우, dp2[x][y] = solve2(x+1,y) + solve2(x+1,y+1)

# [비대칭 타일링](https://algospot.com/judge/problem/read/ASYMTILING)

1. 동적 계획법
2. 메모이제이션을 통해 길이 n이 주어지면 만들 수 있는 개수를 반환하는 tiling 함수 이용
3. 2를 통해 길이 n 의 전체 개수를 구하고 대칭이 되는 경우의 수만 빼주면 됨.
3-1. 길이 n이 홀수라면 가운데에 길이가 1인 타일이 있고 양 쪽이 대칭이어야 함.
3-2. 길이 n이 짝수라면 가운데에 길이가 2인 타일이 있거나 양쪽이 대칭인 경우 2가지가 있음.
4. 양쪽은 서로 대칭이므로 그 중 한 쪽만 구하게 된다면 다른 쪽은 자동으로 결정됨 ( 이 부분 이해 못해서 오래 걸렸음)

# [폴리오미노](https://algospot.com/judge/problem/read/POLY)

1. 동적 계획법
2. 각 줄에 정사각형을 몇개씩 놓으면서 함수 재귀 호출
2-1. 이 경우 next를 진행할 때는 prev에 몇개의 정사각형을 놓았는지에 따라 놓을 수 있는 가지수가 달라지므로 인자로 넘겨준다.
3. 즉 인자로 (남아있는 정사각형의 개수, 그 줄에 놓은 정사각형의 수)
4. 기저 사례는 (남아있는 정사각형의 개수 == 그 줄에 놓은 정사각형의 수)
5. next와 prev가 있을 때 만들 수 있는 가지 수는 next+prev-1임.
6. 다시 풀기

# [두니발 박사의 탈옥](https://algospot.com/judge/problem/read/NUMB3RS)

1. 동적 계획법
2. 특정 지점에서 감옥까지 이동할 때 D만큼 걸리는지 재귀 함수를 통해 확인.
3. dfs 함수의 인자로 현재위치 start, 걸린 날짜 day 를 정함.
4. 현재 위치에서의 확률 ret 은 연결된 지점에서의 확률의 합과 같음.

# [여행 짐 싸기](https://algospot.com/judge/submission/recent/)

1. 동적 계획법
2. 짐을 선택하거나 선택하지 않거나 2가지 경우가 있음
3. pack() 함수는 잔여 용량, item의 idx를 인덱스로 받아 최대 절박도를 반환하는 함수임.
4. 짐을 선택할 시에 기존과 선택한 경우 중 max값을 return 하는 것에 주의
5. 짐을 선택했는지 안했는지 아는 경우는 pack(capacity,item) == pack(capacity,item+1) 이면 선택 안한것.

# [모스 부호 사전](https://algospot.com/judge/problem/read/MORSE)

1. 동적 계획법 & 재귀
2. 완전탐색 알고리즘으로 나열할 수 있는 모든 경우를 구함.
3. n==0 && m==0 일 때마다 skip을 줄여나가며 skip==0이 될 경우에 문자열 출력(시간초과)
4. 장점 n개, 단점 m개를 조합하여 얻을 수 있는 개수는 n+m C n 이므로 이 값을 skip과 비교
5. skip에 비해 작다면 그 값만큼 빼서 탐색 시간을 감소시킴. (메모이제이션)
6. 4와 원리는 비슷 코드 참조.

# [k번째 최대 증가 부분 수열](https://algospot.com/judge/problem/read/KLIS)

1. 동적계획법
2. lis(idx) = idx에서 시작하는 최대 증가 부분 수열의 길이 반환.
3. k번째 수열을 구해야 하므로 각 idx에서 가질 수 있는 경우의 수를 구하는 함수가 필요
4. count(idx) = idx를 포함하는 최대 증가 부분 수열의 개수 반환.
5. reconstruct(start,skip,ans) = start에서 시작하는 LIS 중 skip개를 건너뛴 수열을 ans에 저장.
6. start+1~n까지 루프를 돌면서 num[start]보다 크고 lis(start) == list(next)+1 인 idx를 followers에 저장
7. 사전순으로 정렬해야하므로 pair<int,int> 에 담아 정렬한다. (숫자,idx)
8. 해당 숫자의 count(idx)가 skip보다 작다면 그만큼 skip에서 빼고 아니라면 reconstruct 진행.
9. 다시풀기

# [드래곤 커브](https://algospot.com/judge/problem/read/DRAGON)

1. 동적 계획법
2. n세대 드래곤 커브의 p번째 글자를 찾는 문제로 변환, 그 후 l번 반복
3. p번째 글자를 찾기까지 skip할 수 있다면 skip.
4. xLength(n) = "X+YF" -> 2 + xLength(n-1)+yLength(n-1)
5. yLength(n) = "FX-Y" -> 2 + xLength(n-1)+yLength(n-1)
6. length(n) = 2+2\*length(n-1) 로 변환 가능.
