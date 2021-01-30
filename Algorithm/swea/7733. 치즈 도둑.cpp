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

int N;
int m[101][101];
bool visited[101][101];
int ans;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

void make_zero(int day, map<int, vector<pair<int, int>>> &cheese_info) {
	for (auto &n : cheese_info[day]) {
		m[n.first][n.second] = 0;
	}
}

int dfs() {
	int cnt = 0;
	queue<pair<int, int>> q;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visited[i][j]) continue;
			visited[i][j] = true;
			if (m[i][j] == 0) continue;
			cnt++;
			
			q.push({ i,j });
			while (!q.empty()) {
				int x = q.front().first;
				int y = q.front().second;
				q.pop();

				for (int k = 0; k < 4; k++) {
					int nx = x + dx[k];
					int ny = y + dy[k];
					if (nx < 0 || ny < 0 || nx >= N || ny >= N)continue;
					if (visited[nx][ny] || m[nx][ny]==0)continue;
					visited[nx][ny]=true;
					q.push({ nx,ny });
				}
			}
		}
	}
	return cnt;
}

int main() {
	int t;
	scanf("%d", &t);
	for (int tc = 1; tc <= t; tc++) {
		scanf("%d", &N);
		int maxn = 0;
		map<int, vector<pair<int, int>>> cheese_info;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%d", &m[i][j]);
				cheese_info[m[i][j]].push_back({ i,j });
				if (maxn < m[i][j]) maxn = m[i][j];
			}
		}
		ans = 1;
		for (int i = 1; i <= maxn; i++) {
			memset(visited, 0, sizeof(visited));
			make_zero(i,cheese_info);
			ans = max(ans,dfs());
		}
		printf("#%d %d\n", tc, ans);
	}
	return 0;
}
