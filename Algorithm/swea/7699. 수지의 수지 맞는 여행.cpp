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

int R, C;
char m[21][21];
bool check[26];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int ans;

void dfs(int x, int y, int cnt) {
	
	int nx, ny;
	for (int i = 0; i < 4; i++) {
		nx = x + dx[i];
		ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= R || ny >= C)continue;
		char c = m[nx][ny];
		if (check[c - 'A']) continue;
		check[c - 'A'] = true;
		dfs(nx, ny, cnt + 1);
		check[c - 'A'] = false;
	}
	if (cnt > ans) ans = cnt;
}

int main() {
	int t;
	scanf("%d", &t);
	for (int tc = 1; tc <= t; tc++) {
		scanf("%d %d", &R, &C);
		memset(check, 0, sizeof(check));
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				cin >> m[i][j];
			}
		}
		ans = 0;
		check[m[0][0] - 'A'] = true;
		dfs(0, 0, 1);
		printf("#%d %d\n", tc, ans);
	}
	return 0;
}
