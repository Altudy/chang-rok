# [쿼드 트리 뒤집기](https://www.algospot.com/judge/problem/read/QUADTREE)

1. 분할 정복 알고리즘
2. 주어진 문자열을 쪼개는 부분이 일정하지 않으므로 string::iterator을 이용
3. 문자가 'w'나 'b'면 그 값을 리턴하고 아니라면 4부분에 대해 함수 재귀 호출 실행.

# [울타리 잘라내기](https://www.algospot.com/judge/problem/read/FENCE)

1. 분할 정복 알고리즘
2. mid 기준으로 1)왼쪽 2)오른쪽 3) mid를 포함한 값 중 max값을 리턴하며 함수 재귀 호출 실행.
3. left와 right가 같다면 현재 index의 height 리턴
4. 2에서 3)을 계산할 때, lo=mid, hi=mid+1로 초기화하고 lo-1과 hi+1 값을 비교하면서 높이가 더 높은 쪽으로 확장.

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

# [합친 LIS](https://algospot.com/judge/problem/read/JLIS)

1. 동적 계획법
2. 최대 증가 부분 수열의 해법과 비슷
3. dfs(inxA,idxB) = max( max(idxA+1,idxB)+1 , max(idxA,idxB+1)+1 )

# [원주율](https://algospot.com/judge/problem/read/PI)

1. 동적 계획법
2. 길이가 3인 조각의 난이도 + 3글자 빼고 나머지 수열의 최적해
2-1. 길이가 4인 조각의 난이도 + 4글자 빼고 나머지 수열의 최적해
2-2. 길이가 5인 조각의 난이도 + 5글자 빼고 나머지 수열의 최적해
3. 2,2-1,2-2에 해당하는 값중 max 값을 구하면 됨.
4.  dp[idx] = L(3~5) max(dfs(idx+L) + 난이도 계산 함수())