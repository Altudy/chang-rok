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


int main() {
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		cin >> N;
		vector<int> v;
		for (int i = 0; i < N; i++) {
			int n;
			cin >> n;
			v.push_back(n);
		}
		sort(v.begin(), v.end());
		int s = 0, e = v.size() - 1;
		int ans = 0;
		while (s < e) {
			int sum = v[e];
			if (sum >= 50) {
				ans++;
				e--;
			}
			else {
				int cnt = 1;
				bool flag = true;
				while (sum*cnt < 50) {
					if (s == e) {
						flag = false;
						break;
					}
					cnt++;
					s++;
				}
				if (flag) {
					e--;
					ans++;
				}
			}
		}
		if (v[s] >= 50) ans++;
		printf("#%d %d\n", tc, ans);
	}
	return 0;
}
