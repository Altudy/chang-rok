#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<set>
#include<queue>
#include<map>
#include<unordered_map>
#include<string>
#include<cstdlib>
#include<limits.h>
#include<cstring>
#include<math.h>
#include<string.h>
#include<cmath>
using namespace std;

int N, M;
bool m[1001][1001];
int dx[4] = { -2,0,2,0 };
int dy[4] = { 0,2,0,-2 };

void check(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= N || ny < 0 || ny >= M)continue;
		m[nx][ny] = false;
	}
}

int main()
{
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		memset(m, true, sizeof(m));
		cin >> N >> M;
		int ans = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (m[i][j]) {
					ans++;
					check(i, j);
				}
			}
		}
		printf("#%d %d\n", tc, ans);
	}
	return 0;

}
