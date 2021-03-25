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
#include<sstream>
using namespace std;

#define INF 987654321
#define MOD 10000000

int n, t;
int N, D, P, T;
int connected[51][51], deg[51];
double dp[51][101];

double dfs(int start, int day) {
	if (day == 0) {
		return (start == P ? 1.0 : 0.0);
	}

	double &ret = dp[start][day];
	if (ret > -0.5) return ret;

	ret = 0.0;
	for (int there = 0; there < N; there++) {
		if (connected[start][there]) {
			ret += dfs(there, day - 1) / deg[there];
		}
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	for (int tc = 0; tc < t; tc++) {
		cin >> N >> D >> P;
		memset(connected, 0, sizeof(connected));
		memset(deg, 0, sizeof(deg));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> connected[i][j];
				deg[i] += connected[i][j];
			}
		}
		for (int i = 0; i < 51; i++) {
			for (int j = 0; j < 101; j++) {
				dp[i][j] = -1.0;
			}
		}

		cin >> T;
		for (int i = 0; i < T; i++) {
			cin >> n;
			cout.precision(8);
			cout << fixed << dfs(n, D) << " ";
		}
		cout << "\n";

	}

	return 0;
}
