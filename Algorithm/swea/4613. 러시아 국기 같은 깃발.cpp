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
int color[51][51];
int check[51];
int ans;

int calc() {
	int res = 9876543;
	for (int i = 1; i < N-1; i++) {
		if (check[i] == 2) {
			res = 0;
			break;
		}
	}
	if (res == 0) {
		for (int i = 1; i < N-1; i++) {
			int flag = check[i];
			for (int j = 0; j < M; j++) {
				if (color[i][j] != flag) res++;
			}
		}
	}
	return res;
}

void dfs(int line, int c) {
	if (line == N - 1) {
		int res = calc();
		ans = min(ans, res);
		return;
	}
	int prev = check[line - 1];
	for (int i = prev; i <= 3; i++) {
		check[line] = i;
		dfs(line + 1, i);
		check[line] = 3;
	}
}

int main()
{
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		memset(color, 0, sizeof(color));
		memset(check, 1, sizeof(check));
		cin >> N >> M;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				char c;
				cin >> c;
				if (c == 'W') color[i][j] = 1;
				else if (c == 'B') color[i][j] = 2;
				else color[i][j] = 3;
			}
		}
		ans = 9876543;
		int res = 0;
		for (int i = 0; i < M; i++) {
			if (color[0][i] != 1) {
				res++;
				color[0][i] = 1;
			}
			if (color[N - 1][i] != 3) {
				res++;
				color[N - 1][i] = 3;
			}
		}
		check[0] = 1;
		dfs(1, 1);
		cout << "#" << tc << " " << res + ans << "\n";
	}
	return 0;

}
