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
vector<int> edge[1001];
int check[1001];
int ans;

void dfs(int prev, int n, int dep) {
	check[n] = dep;
	for (int next : edge[n]) {
		if (ans != 0)return;
		if (check[next] != 0) {
			if (next != prev) {
				ans = check[n] - check[next] + 1;
				return;
			}
		}
		else dfs(n, next, dep + 1);
	}
}

int main() {
	int t;
	scanf("%d", &t);
	for (int tc = 1; tc <= t; tc++) {
		scanf("%d", &N);
		memset(check, 0, sizeof(check));
		for (int i = 0; i < 1001; i++)edge[i].clear();
		for (int i = 0; i < N; i++) {
			int a, b;
			cin >> a >> b;
			edge[a].push_back(b);
			edge[b].push_back(a);
		}
		ans = 0;
		dfs(0, 1, 1);
		printf("#%d %d\n", tc,ans);
	}
	return 0;
}
