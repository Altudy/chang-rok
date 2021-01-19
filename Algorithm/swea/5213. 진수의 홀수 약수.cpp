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

int L, R, Q;
long long dp[1000005];

int main() {
	dp[0] = 0;
	dp[1] = 1;
	for (int i = 2; i <= 1000000; i++) {
		L = (int)sqrt(i);
		R = 0;
		for (int j = 1; j <= L; j++) {
			if (i%j == 0) {
				if (j % 2 == 1) {
					R += j;
				}
				Q = i / j;
				if (Q % 2 == 1 && Q!=j) R += Q;
			}
		}
		dp[i] = dp[i - 1] + R;
	}

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		cin >> L >> R;
		cout << "#" << tc << " " << dp[R] - dp[L - 1] << "\n";
	}
	return 0;
}
