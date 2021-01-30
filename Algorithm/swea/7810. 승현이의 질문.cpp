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
int cnt[1000005];

int main() {
	int t;
	scanf("%d", &t);
	for (int tc = 1; tc <= t; tc++) {
		memset(cnt, 0, sizeof(cnt));
		scanf("%d", &N);
		vector<int> v;
		int left = 0, right = -1000005;
		for (int i = 0; i < N; i++) {
			int n;
			scanf("%d", &n);
			v.push_back(n);
			right = max(right, n);
		}
		for (int i = 0; i < N; i++) {
			cnt[v[i]]++;
		}
		for (int i = right-1; i >= left; i--) {
			cnt[i] += cnt[i + 1];
		}
		int ans = -1;
		while (left <= right) {
			int mid = (left + right) / 2;
			if (mid <= cnt[mid]) {
				ans = mid;
				left = mid+1;
			}
			else {
				right = mid-1;
			}
		}
		printf("#%d %d\n", tc, ans);
	}
	return 0;
}
