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

int L, K;
int price['z'+1];
int memo[2001][2001];
string str;

int getMin(int st, int ed) {

	if (st >= ed) return 0;

	int &ret = memo[st][ed];
	if (ret != -1) return ret;

	
	ret = str[st] == str[ed] ? getMin(st + 1, ed - 1) : 9876543;

	ret = min(ret, getMin(st + 1, ed) + price[str[st]]);

	ret = min(ret, getMin(st, ed - 1) + price[str[ed]]);

	return ret;
}

int main() {
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		cin >> L >> K;
		memset(memo, -1, sizeof(memo));
		memset(price, 0, sizeof(price));
		cin >> str;
		for (int i = 0; i < K; i++) {
			int i1, i2;
			cin >> i1 >> i2;
			price[i + 'a'] = i1 < i2 ? i1 : i2;
		}
		int ans = getMin(0, L - 1);
		printf("#%d %d\n", tc, ans);
	}
	return 0;
}
