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

int N;
int cnt[100001];
int dp[100001];

int main() {
	cnt[1] = 1;
	dp[1] = 1;
	for (int i = 2; i <= 100001; i++) {
		set<int> tmp;
		for (int j = 1; j <= sqrt(i); j++) {
			if (i%j == 0) {
				tmp.insert(j);
				tmp.insert(i / j);
			}
		}
		cnt[i] = tmp.size();
		dp[i] = cnt[i] >= cnt[dp[i - 1]] ? i : dp[i - 1];
	}
	int t;
	scanf("%d", &t);
	for (int tc = 1; tc <= t; tc++) {
		scanf("%d", &N);
		printf("#%d %d\n", tc, dp[N]);
	}
	return 0;
}
