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

int n, w;
string name[100];
int volume[100], value[100];
int cache[1001][101];

int pack(int capacity, int item) {
	if (item == n) return 0;

	int &ret = cache[capacity][item];
	if (ret != -1) return ret;

	ret = pack(capacity, item + 1);
	if (capacity >= volume[item]) {
		ret = max(ret,pack(capacity - volume[item], item + 1) + value[item]);
	}
	return ret;
}

void reconstruct(int capacity, int item, vector<string> &ans) {
	if (item == n) return;

	if (pack(capacity, item) == pack(capacity, item + 1)) {
		reconstruct(capacity, item + 1, ans);
	}
	else {
		ans.push_back(name[item]);
		reconstruct(capacity - volume[item], item + 1, ans);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	for (int tc = 0; tc < t; tc++) {
		cin >> n >> w;
		for (int i = 0; i < n; i++) {
			cin >> name[i] >> volume[i] >> value[i];
		}
		memset(cache, -1, sizeof(cache));
		int maxValue = pack(w, 0);
		vector<string> ans;
		reconstruct(w, 0, ans);
		int size = ans.size();
		cout << maxValue << " " << size << "\n";
		for (int i = 0; i < size; i++) {
			cout << ans[i] << "\n";
		}
	}
	return 0;
}
