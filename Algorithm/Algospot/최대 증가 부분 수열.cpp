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
int num[501];
int dp[501];

int dfs(int idx) {
	int &ret = dp[idx];
	if (ret != -1) return ret;

	ret = 1;
	for (int i = idx + 1; i < n; i++) {
		if (num[idx] < num[i]) {
			ret = max(ret, dfs(i) + 1);
		}
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	for (int tc = 0; tc < t; tc++) {
		cin >> n;
		memset(dp, -1, sizeof(dp));
		for (int i = 0; i < n; i++) {
			cin >> num[i];
		}
		int ans = 0;
		for (int i = 0; i < n; i++) {
			ans = max(ans, dfs(i));
		}
		cout << ans << "\n";
	}
	return 0;
}
