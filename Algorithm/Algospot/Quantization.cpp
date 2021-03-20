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

#define INF 987654321

int t,n,m;
int num[101], pSum[101], pSqSum[101];
int dp[101][101];

int minError(int a, int b) {
	int sum = pSum[b] - (a == 0 ? 0 : pSum[a-1]);
	int sqSum = pSqSum[b] - (a == 0 ? 0 : pSqSum[a - 1]);

	int m = int(0.5+(double)sum / (b - a + 1));
	int ret = sqSum - 2 * m*sum + m * m*(b - a + 1);
	return ret;
}

int dfs(int from, int parts) {
	if (from == n) return 0;
	if (parts == 0)return INF;
	int &ret = dp[from][parts];
	if (ret != -1) return ret;

	ret = INF;
	for (int x = 1; from + x <= n; x++) {
		ret = min(ret, minError(from, from + x - 1) + dfs(from + x, parts - 1));
	}
	return ret;
}

void precalc() {
	pSum[0] = num[0];
	pSqSum[0] = num[0] * num[0];
	for (int i = 1; i < n; i++) {
		pSum[i] = pSum[i - 1] + num[i];
		pSqSum[i] = pSqSum[i - 1] + num[i] * num[i];
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	for (int tc = 0; tc < t; tc++) {
		cin >> n >> m;
		memset(dp, -1, sizeof(dp));
		for (int i = 0; i < n; i++) {
			cin >> num[i];
		}
		sort(num, num + n);
		precalc();
		cout << dfs(0, m) <<"\n";
	}
	return 0;
}
