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
#include<sstream>
using namespace std;

#define INF 987654321
#define MOD 1000000007

int n, t;
int path[101][101];
int dp1[101][101];
int dp2[101][101];

int solve1(int x, int y) {
	if (x == n - 1) return dp1[x][y] = path[x][y];

	int &ret = dp1[x][y];
	if (ret != -1) return ret;

	return ret = max(solve1(x + 1, y), solve1(x + 1, y + 1)) + path[x][y];
}

int solve2(int x, int y) {
	if (x == n - 1) return 1;

	int &ret = dp2[x][y];
	if (ret != -1) return ret;

	if (dp1[x + 1][y] > dp1[x + 1][y + 1]) {
		ret = solve2(x + 1, y);
	}
	else if (dp1[x + 1][y] < dp1[x + 1][y + 1]) {
		ret = solve2(x + 1, y + 1);
	}
	else {
		ret = solve2(x + 1, y) + solve2(x + 1, y + 1);
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	for (int tc = 0; tc < t; tc++) {
		memset(dp1, -1, sizeof(dp1));
		memset(dp2, -1, sizeof(dp2));
		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= i; j++) {
				cin >> path[i][j];
			}
		}
		solve1(0, 0);
		cout << solve2(0, 0) << "\n";
	}

	return 0;
}
