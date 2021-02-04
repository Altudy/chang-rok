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

int X1, Y1, X2, Y2;

int main() {
	int t;
	scanf("%d", &t);
	for (int tc = 1; tc <= t; tc++) {
		cin >> X1 >> Y1 >> X2 >> Y2;
		int ans = 0;
		int x = abs(X1 - X2);
		int y = abs(Y1 - Y2);
		int minn = min(x, y);
		ans += minn * 2;
		x -= minn;
		y -= minn;
		int len = x == 0 ? y : x;
		if (len % 2 == 0) ans += len * 2;
		else ans += len * 2 - 1;
		printf("#%d %d\n", tc, ans);
	}
	return 0;
}
