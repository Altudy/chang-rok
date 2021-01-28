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
int m[13][13];
vector< pair<int, int> > vii;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int maxcnt, minlen;

void dfs(int idx, int len, int cnt) {
	if (idx == vii.size()) {
		if (cnt > maxcnt) {
			maxcnt = cnt;
			minlen = len;
		}
		else if (cnt == maxcnt) minlen = min(minlen, len);
		return;
	}
	
	for (int i = 0; i < 4; i++) {
		int nx = vii[idx].first;
		int ny = vii[idx].second;
		int c = 0;
		while (true) {
			nx += dx[i];
			ny += dy[i];
			c++;
			if (m[nx][ny] == 1 || m[nx][ny] == 2) {
				c = 0;
				break;
			}
			if (m[nx][ny] == 0 && (nx == 0 || nx == N - 1 || ny == 0 || ny == N - 1)) {
				break;
			}
		}
		if (c > 0) {
			nx = vii[idx].first;
			ny = vii[idx].second;
			while (true) {
				nx += dx[i];
				ny += dy[i];
				m[nx][ny] = 2;
				if (nx == 0 || nx == N - 1 || ny == 0 || ny == N - 1) break;
			}
			dfs(idx + 1, len + c, cnt + 1);
			nx = vii[idx].first;
			ny = vii[idx].second;
			while (true) {
				nx += dx[i];
				ny += dy[i];
				m[nx][ny] = 0;
				if (nx == 0 || nx == N - 1 || ny == 0 || ny == N - 1) break;
			}
		}
	}
	dfs(idx + 1, len, cnt);
}

int main() {
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		cin >> N;
		vii.clear();
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> m[i][j];
				if (m[i][j] == 1) {
					if (i*j == 0 || i == N - 1 || j == N - 1) continue;
					vii.push_back({ i,j });
				}
			}
		}
		maxcnt = 0;
		minlen = 9876543;
		dfs(0, 0, 0);
		printf("#%d %d\n", tc, minlen);
	}
	return 0;
}
