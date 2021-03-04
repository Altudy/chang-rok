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

int n, k;

int c[500001];
int d[500001];




int main() {
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		cin >> n >> k;
		for (int i = 0; i < n; i++) {
			cin >> c[i] >> d[i];
		}
		int sum = 0;
		int ans = 0;
		for (int i = 0; i < n; i++) {
			if (sum + c[i] >= k)break;
			if (!d[i]) {
				if (sum + c[i] < c[i + 1] || i==n-1) {
					sum += c[i];
					ans++;
				}
			}
		}
		if (sum == 0) sum = 1;
		cout << "#" << tc << " " << ans << " " << k - sum << "\n";
	}
	
	return 0;
}
