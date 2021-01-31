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

int P;

int main() {
	int t;
	scanf("%d", &t);
	for (int tc = 1; tc <= t; tc++) {
		scanf("%d", &P);
		vector<int> v;
		for (int i = 0; i < P; i++) {
			int n;
			cin >> n;
			v.push_back(n);
		}
		sort(v.begin(), v.end());
		int ans = 0;
		if (P == 1) ans = v[0] * v[0];
		else {
			ans = v[0] * v[v.size() - 1];
		}
		printf("#%d %d\n", tc, ans);
	}
	return 0;
}
