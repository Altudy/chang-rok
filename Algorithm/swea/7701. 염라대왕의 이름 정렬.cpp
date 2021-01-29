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

bool cmp(string s1, string s2) {
	if (s1.length() < s2.length()) return true;
	else if (s1.length() == s2.length()) return s1 < s2;
	else return false;
}

int main() {
	int t;
	scanf("%d", &t);
	for (int tc = 1; tc <= t; tc++) {
		scanf("%d", &N);
		set<string> ss;
		for (int i = 0; i < N; i++) {
			string str;
			cin >> str;
			ss.insert(str);
		}
		vector<string> vs(ss.begin(), ss.end());
		sort(vs.begin(), vs.end(), cmp);
		printf("#%d\n", tc);
		for (int i = 0; i < vs.size(); i++) {
			printf("%s\n", vs[i].c_str());
		}
	}
	return 0;
}
