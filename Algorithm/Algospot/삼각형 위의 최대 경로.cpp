## top-down

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

#define INF 9999

int t, n;
int triangle[101][101];
int dp[101][101];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	for (int tc = 0; tc < t; tc++) {
		cin >> n;
		memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= i; j++) {
				cin >> triangle[i][j];
			}
		}
		dp[1][1] = triangle[1][1];
		for (int i = 2; i <= n; i++) {
			for (int j = 1; j <= i; j++) {
				dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
			}
		}
		int ans = 0;
		for (int j = 1; j <= n; j++) {
			if (ans < dp[n][j]) ans = dp[n][j];
		}
		cout << ans << "\n";
	}
	return 0;
}

## bottom-up

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

#define INF 9999

int t, n;
int triangle[101][101];
int dp[101][101];

int dfs(int x, int y) {
	if (y == n) return triangle[x][y];

	int &ret = dp[x][y];
	if (ret != -1) return ret;

	return ret = max(dfs(x + 1, y), dfs(x + 1, y + 1)) + triangle[x][y];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	for (int tc = 0; tc < t; tc++) {
		cin >> n;
		memset(dp, -1, sizeof(dp));
		memset(triangle, 0, sizeof(triangle));
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= i; j++) {
				cin >> triangle[i][j];
			}
		}
		int ans = dfs(1, 1);
		cout << ans << "\n";
	}
	return 0;
}
