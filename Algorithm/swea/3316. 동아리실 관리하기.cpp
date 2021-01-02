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

string s;
int dp[10005][16];
long long ans;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		cin >> s;
		memset(dp, 0, sizeof(dp));
		ans = 0;
		for (int day = 0; day < s.length(); day++) {
			int admin = 1 << (s[day] - 'A');
			
			for (int i = 1; i < 16; i++) {
				if (day == 0) {
					if ((i & admin) != 0 && (i & 1) != 0) {
						dp[day][i] = 1;
					}
				}
				else {
					if (dp[day - 1][i] != 0) {
						for (int j = 1; j < 16; j++) {
							if ((i&j) != 0 && (j&admin) != 0) {
								dp[day][j] += dp[day - 1][i];
								dp[day][j] %= 1000000007;
							}
						}
					}
				}
			}
		}
		for (int i = 1; i < 16; i++) {
			ans += dp[s.length() - 1][i];
			ans %= 1000000007;
		}
		printf("#%d %lld\n", tc, ans);
	}
	return 0;

}
