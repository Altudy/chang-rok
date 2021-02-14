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

#define mod 1000000007

int N;
long long factorial[1001];
long long dp[1001];

int main() {
	int t;
	scanf("%d", &t);
	for (int tc = 1; tc <= t; tc++) {
		scanf("%d", &N);
		factorial[1] = 1;
		factorial[2] = 2;
		for (int i = 3; i <= 1000; i++) {
			factorial[i] = i * factorial[i - 1];
			factorial[i] %= mod;
		}
		dp[1] = 0;
		dp[2] = 1;
		for (int i = 3; i <= N; i++) {
			dp[i] = i * dp[i - 1] + (i / 2)*factorial[i - 1];
			dp[i] %= mod;
		}
		printf("#%d %lld\n", tc, dp[N]%mod);
	}
	return 0;
}
