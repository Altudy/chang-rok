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

bool cmp(pair<string, int> v1, pair<string, int> v2) {
	int v1_alpha = v1.second;
	int v2_alpha = v2.second;

	if (v1_alpha > v2_alpha) return true;
	else if (v1_alpha == v2_alpha)
		return v1.first < v2.first;
	else return false;
}

int main() {
	int t;
	scanf("%d", &t);
	for (int tc = 1; tc <= t; tc++) {
		scanf("%d", &N);
		vector<pair<string,int>> vs;
		for (int i = 0; i <= N; i++) {
			string str;
			set<char> sc;
			getline(cin,str);
			for (int j = 0; j < str.length(); j++) {
				if (str[j] == ' ')continue;
				sc.insert(str[j]);
			}
			vs.push_back({ str,sc.size() });
		}
		sort(vs.begin(), vs.end(), cmp);
		printf("#%d %s\n", tc, vs[0].first.c_str());
	}
	return 0;
}
