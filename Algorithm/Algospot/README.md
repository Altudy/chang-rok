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

1. 동적계획법
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
