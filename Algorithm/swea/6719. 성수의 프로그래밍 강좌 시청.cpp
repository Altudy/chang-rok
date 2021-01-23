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

int N, K;

int main() {
	
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		cin >> N >> K;
		vector<int> a;
		for (int i = 0; i < N; i++) {
			int n;
			cin >> n;
			a.push_back(n);
		}
		sort(a.begin(), a.end());
		float ans = 0;
		for (int i = N-K; i < N; i++) {
			ans = (ans + a[i]) / 2;
		}
		printf("#%d %0.6f\n", tc, ans);
	}
	return 0;
}
