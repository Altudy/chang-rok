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

int K;

int main() {
	int t;
	scanf("%d", &t);
	for (int tc = 1; tc <= t; tc++) {
		scanf("%d", &K);
		long long a = 2, b = 1, tmp;
		while (1) {
			K--;
			if (K <= 0) {
				if (a > b) break;
			}
			tmp = b;
			b = a;
			a = b + tmp;
		}
		printf("#%d %lld %lld\n", tc, a, b);
	}
	return 0;
}
