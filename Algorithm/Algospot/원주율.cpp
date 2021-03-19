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

#define INF 987654321

int t;
string str;
int dp[10001];

int solve(int a,int b) {
	string s = str.substr(a, b - a + 1);
	if (s == string(s.size(), s[0])) return 1;

	bool flag1 = true;
	for (int i = 0; i < s.size() - 1; i++) {
		if (s[i + 1] - s[i] != s[1] - s[0]) flag1 = false;
	}
	if (flag1 && abs(s[1] - s[0]) == 1) return 2;
	if (flag1) return 5;

	bool flag2 = true;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] != s[i % 2]) flag2 = false;
	}
	if (flag2) return 4;
	return 10;
}

int dfs(int idx) {
	if (idx == str.size()) return 0;
	int &ret = dp[idx];
	if (ret != -1) return ret;

	ret = INF;
	for (int L = 3; L <= 5; L++) {
		if (idx + L <= str.size()) {
			ret = min(ret, dfs(idx + L) + solve(idx,idx+L-1));
		}
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	for (int tc = 0; tc < t; tc++) {
		cin >> str;
		memset(dp, -1, sizeof(dp));
		cout << dfs(0) <<"\n";
	}
	return 0;
}
