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

int S, T, a, b;
int ans;

int dfs(){
	if (b == 1) {
		if ((T - S) % a == 0) return (T - S) / a;
		else return -1;
	}
	while (S < T) {
		if (T%b == 0 && T / b >= S) T /= b;
		else T -= a;
		ans++;
	}
	if (S == T) return ans;
	else return -1;
}

int main() {
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		cin >> S >> T >> a >> b;
		ans = 0;
		printf("#%d %d\n",tc, dfs());
	}
	return 0;
}
