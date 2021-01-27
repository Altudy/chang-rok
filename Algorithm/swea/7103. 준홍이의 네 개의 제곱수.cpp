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

int N,n1,n2,n3;
float n4;
int m[183];

int main() {
	for (int i = 0; i < 183; i++) {
		m[i] = i * i;
	}

	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		cin >> N;
		int ans = 0;
		for (int i = 0; i <= sqrt(N); i++) {
			n1 = N - m[i];
			for (int j = 0; j <= i; j++) {
				n2 = n1 - m[j];
				if (n2 < 0) break;
				for (int k = 0; k <= j; k++) {
					n3 = n2 - m[k];
					if (n3 < 0)break;
					if (n3 > m[k]) continue;
					n4 = sqrt(n3);

					if (n4 != (int)n4) continue;
					ans++;
				}
			}
		}
		printf("#%d %d\n", tc, ans);
	}
	return 0;
}
