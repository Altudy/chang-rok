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
#define MOD 10000000

const int MAX = 2000000000 + 1;
int n, k;
int num[501];
int cacheLen[501];
int cacheCnt[501];

int lis(int start) {
	int &ret = cacheLen[start + 1];
	if (ret != -1) return ret;

	ret = 1;
	for (int next = start + 1; next < n; next++) {
		if (start == -1 || num[start] < num[next]) {
			ret = max(ret, lis(next) + 1);
		}
	}
	return ret;
}

int count(int start) {
	if (lis(start) == 1) return 1;

	int &ret = cacheCnt[start+1];
	if (ret != -1) return ret;

	ret = 0;
	for (int next = start + 1; next < n; next++) {
		if ((start == -1 || num[start] < num[next]) &&
			lis(start) == lis(next) + 1) {
			ret = min<long long>(MAX, (long long)ret + count(next));
		}
	}
	return ret;
}

void reconstruct(int start, int skip, vector<int> &ans) {
	if (start != -1) ans.push_back(num[start]);

	vector<pair<int, int>> followers;
	for (int next = start + 1; next < n; next++) {
		if ((start == -1 || num[start] < num[next]) &&
			lis(start) == lis(next) + 1) {
			followers.push_back(make_pair(num[next], next));
		}
	}
	sort(followers.begin(), followers.end());

	for (int i = 0; i < followers.size(); i++) {
		int idx = followers[i].second;
		int cnt = count(idx);
		if (skip >= cnt) {
			skip -= cnt;
		}
		else {
			reconstruct(idx, skip, ans);
			break;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	for (int tc = 0; tc < t; tc++) {
		cin >> n >> k;
		memset(cacheLen, -1, sizeof(cacheLen));
		memset(cacheCnt, -1, sizeof(cacheCnt));
		for (int i = 0; i < n; i++) {
			cin >> num[i];
		}
		lis(-1);
		vector<int> ans;
		reconstruct(-1, k-1, ans);
		cout << ans.size() << "\n";
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i] << " ";
		}
		cout << "\n";
	}
	return 0;
}
