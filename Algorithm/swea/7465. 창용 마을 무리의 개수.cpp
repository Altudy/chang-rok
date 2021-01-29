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
bool visited[101];
bool edge[101][101];

void dfs(int n) {
	visited[n] = true;
	for (int i = 1; i <= N; i++) {
		if (edge[n][i] && !visited[i]) dfs(i);
	}
}

int main() {
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		cin >> N >> M;
		memset(edge, 0, sizeof(edge));
		memset(visited, 0, sizeof(visited));
		for (int i = 0; i < M; i++) {
			int x, y;
			cin >> x >> y;
			edge[x][y] = true;
			edge[y][x] = true;
		}
		int ans = 0;
		for (int i = 1; i <= N; i++) {
			if (!visited[i]) {
				dfs(i);
				ans++;
			}
		}
		printf("#%d %d\n", tc, ans);
	}
	return 0;
}
