# [쿼드 트리 뒤집기](https://www.algospot.com/judge/problem/read/QUADTREE)

1. 분할 정복 알고리즘
2. 주어진 문자열을 쪼개는 부분이 일정하지 않으므로 string::iterator을 이용
3. 문자가 'w'나 'b'면 그 값을 리턴하고 아니라면 4부분에 대해 함수 재귀 호출 실행.

# [울타리 잘라내기](https://www.algospot.com/judge/problem/read/FENCE)

1. 분할 정복 알고리즘
2. mid 기준으로 1)왼쪽 2)오른쪽 3) mid를 포함한 값 중 max값을 리턴하며 함수 재귀 호출 실행.
3. left와 right가 같다면 현재 index의 height 리턴
4. 2에서 3)을 계산할 때, lo=mid, hi=mid+1로 초기화하고 lo-1과 hi+1 값을 비교하면서 높이가 더 높은 쪽으로 확장.
