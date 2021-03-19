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

int t, n, m;
int A[101],B[101];
int dp[102][102];

int dfs(int prev, int idx1, int idx2) {

	int &ret = dp[idx1][idx2];
	if (ret != -1) return ret;

	ret = 1;
	for (int i = idx1; i <= n; i++) {
		if (prev < A[i]) {
			ret = max(ret, dfs(A[i], i+1, idx2)+1);
		}
	}
	for (int i = idx2; i <= m; i++) {
		if (prev < B[i]) {
			ret = max(ret, dfs(B[i], idx1, i+1)+1);
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
		cin >> n >> m;
		memset(dp, -1, sizeof(dp));
		for (int i = 1; i <= n; i++) cin >> A[i];
		for (int i = 1; i <= m; i++) cin >> B[i];

		int ret = 0;
		for (int i = 1; i <= n; i++) {
			ret = max(ret, dfs(A[i],i + 1, 1));
		}
		for (int i = 1; i <= m; i++) {
			ret = max(ret, dfs(B[i], 1, i + 1));
		}
		cout << ret << "\n";
	}
	return 0;
}
