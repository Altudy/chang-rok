## 완전탐색

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

#define INF 9999

int t, n;
string W, S;

bool match(const string &w, const string &s) {
	int pos = 0;
	while (pos < w.size() && pos < s.size() &&
		(w[pos] == s[pos] || w[pos] == '?')) {
		pos++;
	}

	if (pos == w.size()) return pos == s.size();
	if (w[pos] == '*') {
		for (int skip = 0; skip + pos <= s.size(); skip++) {
			if (match(w.substr(pos + 1), s.substr(pos + skip)))
				return true;
		}
	}
	return false;

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	for (int tc = 0; tc < t; tc++) {
		cin >> W;
		cin >> n;
		vector<string> ans;
		for (int i = 0; i < n; i++) {
			cin >> S;
			if (match(W, S)) ans.push_back(S);
		}
		sort(ans.begin(), ans.end());
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i] << "\n";
		}
	}
	return 0;
}

## 

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

#define INF 9999

int n;
string w, s;
int cache[101][101];

bool dfs(int w_idx, int s_idx) {
	int &ret = cache[w_idx][s_idx];
	if (ret != -1) return ret;

	while (w_idx < w.size() && s_idx < s.size()
		&& (w[w_idx] == s[s_idx] || w[w_idx] == '?')) {
		w_idx++;
		s_idx++;
	}
	if (w_idx == w.size()) {
		return ret = (s_idx == s.size());
	}
	if (w[w_idx] == '*') {
		for (int skip = 0; skip + s_idx <= s.size(); skip++) {
			if (dfs(w_idx + 1, s_idx + skip)) {
				return ret=1;
			}
		}
	}
	return ret=0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	for (int tc = 0; tc < t; tc++) {
		cin >> w;
		cin >> n;
		vector<string> ans;
		for (int i = 0; i < n; i++) {
			memset(cache, -1, sizeof(cache));
			cin >> s;
			if (dfs(0, 0)) {
				ans.push_back(s);
			}
		}
		sort(ans.begin(), ans.end());
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i] << "\n";
		}
	}
	return 0;
}
