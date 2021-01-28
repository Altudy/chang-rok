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

long long y,m;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		cin >> y >> m;
		long long M = (y - 2016) * 12 + (m - 1);
		long long ny = M / 13;
		long long nm = M % 13;
		printf("#%d %lld %lld\n", tc, 2016 + ny, 1 + nm);
	}
	return 0;
}
