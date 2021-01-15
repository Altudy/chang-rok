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

string W;
int cnt[26];

bool Sort_sort(int a, int b) {
	if (a > b)return true;
	return false;
}

int main()
{
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		cin >> W;
		memset(cnt, 0, sizeof(cnt));
		int ans = 0;
		for (int i = 0; i < W.length(); i++) {
			cnt[W[i] - 'a']++;
		}
		sort(cnt, cnt+26, Sort_sort);

		for (int i = 0; i < 26; i++) {
			if (cnt[i] == 0)break;
			ans += ((cnt[i] + 1)*cnt[i]) / 2;
		}
		cout << "#" << tc << " " << ans <<"\n";
	}
	return 0;

}
