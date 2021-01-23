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
		vector<int> interval;
		int n,ans=0;
		cin >> n;
		for (int i = 1; i < N; i++) {
			int n1;
			cin >> n1;
			interval.push_back(n1 - n);
			n = n1;
		}
		sort(interval.begin(), interval.end());
		for (int i = 0; i < N - K; i++) {
			ans += interval[i];
		}
		printf("#%d %d\n", tc, ans);
	}
	return 0;
}
