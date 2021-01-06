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

int N,K;
int main()
{
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		cin >> N;
		cin >> K;
		vector<int> v;
		vector<int> d;
		int ans = 0;
		for (int i = 0; i < N; i++) {
			int n;
			cin >> n;
			v.push_back(n);
		}
		sort(v.begin(), v.end());
		for (int i = 1; i < N; i++) {
			int dis = v[i] - v[i - 1];
			d.push_back(dis);
		}
		sort(d.begin(), d.end());
		for (int i = 0; i < N-K; i++) {
			ans += d[i];
		}
		printf("#%d %d\n", tc, ans);
	}
	return 0;

}
