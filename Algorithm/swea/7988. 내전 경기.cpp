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

int K;
map<string, int> m;
vector<int> v[101];
int color[101];

void dfs(int idx, int c) {
	color[idx] = c;
	for (auto n : v[idx]) {
		if (color[n] == 0) dfs(n, 3 - c);
	}
}

int main() {
	int t;
	scanf("%d", &t);
	for (int tc = 1; tc <= t; tc++) {
		scanf("%d", &K);
		memset(color, 0, sizeof(color));
		m.clear();
		for (int i = 0; i < 101; i++) v[i].clear();
		int idx = 0;
		for (int i = 0; i < K; i++) {
			string s1, s2;
			cin >> s1 >> s2;
			if (m.count(s1) == 0) m[s1] = idx++;
			if (m.count(s2) == 0) m[s2] = idx++;
			v[m[s1]].push_back(m[s2]);
			v[m[s2]].push_back(m[s1]);
		}
		for (int i = 0; i < idx; i++) {
			if(color[i]==0) dfs(i, 1);
		}
		string ans = "Yes";
		bool flag = true;
		for (int i = 0; i < idx; i++) {
			for (auto n : v[i]) {
				if (color[i] == color[n]) {
					ans = "No";
					flag = false;
					break;
				}
			}
			if (!flag) break;
		}
		printf("#%d %s\n", tc, ans.c_str());
	}
	return 0;
}
