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

#define mod 1000000000

int N;
int m[101][11][1024];

int dfs(int len, int num, int msk) {
	int ret = m[len][num][msk];
	if (ret != -1) return ret;
	msk = msk | (1<<num);

	if (num < 0 || num>9) return 0;
	if (len == N) {
		if (msk == 1023) return 1;
		else return 0;
	}

	m[len][num][msk] = ((long long)dfs(len + 1, num - 1, msk) + dfs(len + 1, num + 1, msk)) % mod;
	return m[len][num][msk];
}

int main() {
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		cin >> N;
		memset(m, -1, sizeof(m));
		long long ans = 0;
		for (int i = 1; i < 10; i++) {
			ans = ((long long)ans + dfs(1, i, 0)) % mod;
		}
		printf("#%d %lld\n", tc, ans);
	}
	return 0;
}
