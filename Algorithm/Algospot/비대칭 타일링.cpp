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
int dp[101];

int tiling(int m) {
	if (m <= 1) return 1;

	int &ret = dp[m];
	if (ret != -1) return ret;

	return ret = (tiling(m - 1) + tiling(m - 2))%MOD;
}

int symmetric(int w) {
	if (w % 2 == 1) {
		return (tiling(w) - tiling(w / 2) + MOD) % MOD;
	}
	int ret = tiling(w);
	ret = (ret - tiling(w / 2 - 1) + MOD) % MOD;
	ret = (ret - tiling(w / 2) + MOD) % MOD;
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
		cout << symmetric(n) << "\n";
	}

	return 0;
}
