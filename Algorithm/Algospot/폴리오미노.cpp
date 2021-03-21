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
#define MOD 10000000

int n, t;
int dp[101][101];

int monotone(int m, int prev) {

	if (m == prev) return 1;

	int &ret = dp[m][prev];
	if (ret != -1)return ret;

	ret = 0;
	for (int next = 1; next <= m - prev; next++) {
		int add = prev + next - 1;
		add*=monotone(m - prev, next);
		add %= MOD;
		ret += add;
		ret %= MOD;
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
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			ans += monotone(n, i);
			ans %= MOD;
		}
		cout << ans << "\n";
	}

	return 0;
}
