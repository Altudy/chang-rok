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
int m[50005];


int main() {
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		cin >> N;
		memset(m, 0, sizeof(m));
		for (int i = 0; i < N; i++) {
			cin >> m[i];
		}
		int ans = 0;
		int up = 0, down = 0;
		for (int i = 1; i < N; i++) {
			if (i == N - 1) {
				if (m[i - 1] > m[i]) {
					down++;
					ans += up * down;
				}
			}
			if (m[i - 1] < m[i]) {
				up++;
			}
			else if (m[i - 1] > m[i] && up != 0) {
				down++;
				if (m[i] < m[i + 1]) {
					ans += up * down;
					up = 0;
					down = 0;
				}
			}
		}
		printf("#%d %d\n", tc, ans);
	}
	return 0;
}
