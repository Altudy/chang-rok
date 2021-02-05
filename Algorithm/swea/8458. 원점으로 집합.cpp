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
long dist[11];

int main() {
	int t;
	scanf("%d", &t);
	for (int tc = 1; tc <= t; tc++) {
		scanf("%d", &N);
		memset(dist, 0, sizeof(dist));
		for (int i = 0; i < N; i++) {
			int x, y;
			cin >> x >> y;
			dist[i] = abs(x) + abs(y);
		}
		int even = -1, odd = -1;
		for (int i = 0; i < N; i++) {
			if (dist[i] % 2 == 0) {
				if (dist[i] > even) even = dist[i];
			}
			else {
				if (dist[i] > odd) odd = dist[i];
			}
		}
		if (even != -1 && odd != -1) {
			printf("#%d -1\n", tc);
			continue;
		}
		int x;
		if (even != -1)x = even;
		else x = odd;
		int i = 0, y = 0, ans = 0;
		while (true) {
			y += i;
			if (y >= x && y % 2 == x % 2) {
				ans = i;
				break;
			}
			i++;
		}
		printf("#%d %d\n", tc, ans);
	}
	return 0;
}
