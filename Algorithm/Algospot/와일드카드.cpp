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

int t, n;
int cache[101][101];
string W, S;

bool match(int w, int s) {

	int &ret = cache[w][s];
	if (ret != -1) return ret;

	while (w < W.size() && s < S.size() &&
		(W[w] == S[s] || W[w] == '?')) {
		w++;
		s++;
	}

	if (w == W.size()) return s == S.size();
	if (W[w] == '*') {
		for (int skip = 0; skip + s <= S.size(); skip++) {
			if (match(w+1,s+skip))
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
		memset(cache, -1, sizeof(cache));
		vector<string> ans;
		for (int i = 0; i < n; i++) {
			cin >> S;
			if (match(0, 0)) ans.push_back(S);
		}
		sort(ans.begin(), ans.end());
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i] << "\n";
		}
	}
	return 0;
}
