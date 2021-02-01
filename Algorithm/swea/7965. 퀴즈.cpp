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

long mod = 1000000007;

int N;
int dp[1000005];

long pows(long a, long b) {
	if (b == 0) return 1;
	if (b == 1) return a;
	long long t = pows(a, b / 2);
	if (b % 2 == 0) return (t*t) % mod;
	else return (((t*t)%mod)*a) % mod;
}

int main() {
	dp[1] = 1;
	for (int i = 2; i <= 1000000; i++) {
		dp[i] = (dp[i - 1] + pows(i, i) % mod) % mod;
	}
	int t;
	scanf("%d", &t);
	for (int tc = 1; tc <= t; tc++) {
		scanf("%d", &N);
		printf("#%d %ld\n", tc, dp[N]);
	}
	return 0;
}
