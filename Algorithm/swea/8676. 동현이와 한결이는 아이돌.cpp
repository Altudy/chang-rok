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

char S[10001];
int dp[7];

int main() {
	int t;
	scanf("%d", &t);
	for (int tc = 1; tc <= t; tc++) {
		scanf("%s", &S);
		memset(dp, 0, sizeof(dp));
		for (int i = 0; S[i] != '\0'; i++) {
			if (S[i] == 'S') {
				dp[0] = (dp[0] + 1) % mod;
				dp[3] = (dp[2] + dp[3]) % mod;
			}
			else if (S[i] == 'A') {
				dp[1] = (dp[0] + dp[1]) % mod;
			}
			else if (S[i] == 'M') {
				dp[2] = (dp[1] + dp[2]) % mod;
			}
			else if (S[i] == 'U') {
				dp[4] = (dp[3] + dp[4]) % mod;
			}
			else if (S[i] == 'N') {
				dp[5] = (dp[4] + dp[5]) % mod;
			}
			else if (S[i] == 'G') {
				dp[6] = (dp[5] + dp[6]) % mod;
			}
		}
		printf("#%d %d\n", tc, dp[6]);
	}
	return 0;
}
