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
int score[101];
bool check[10001];
int maxn,ans;


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		memset(check, 0, sizeof(check));
		memset(score, 0, sizeof(score));
		maxn = 0;
		ans = 0;
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> score[i];
			maxn += score[i];
		}
		check[0] = true;
		for (int i = 0; i < N; i++) {
			for (int j = maxn; j >= 0; j--) {
				if (check[j]) check[j + score[i]] = true;
			}
		}
		for (int i = 0; i <= maxn; i++) {
			if (check[i]) ans++;
		}
		printf("#%d %d\n", tc, ans);
	}
	return 0;

}
