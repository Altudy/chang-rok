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
int Map[101][101];
int isGo[101][101];
bool ans;

int dfs(int x, int y) {
	if (x >= n || y >= n) return 0;
	if (x == n - 1 && y == n - 1) return 1;

	int &ret = isGo[x][y];
	if (ret != -1) return ret;

	int jumpSize = Map[x][y];
	
	return ret = (dfs(x + jumpSize, y) || dfs(x, y + jumpSize));;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	for (int tc = 0; tc < t; tc++) {
		cin >> n;
		memset(isGo, -1, sizeof(isGo));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> Map[i][j];
			}
		}
		ans = dfs(0, 0);
		if (ans==1) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
