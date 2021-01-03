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


long long N;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		cin >> N;
		while (N > 1) {
			N = (N / 2) + 1;
			N = (N / 2) - 1;
		}
		if (N == 1)
			printf("#%d Bob\n", tc);
		else
			printf("#%d Alice\n", tc);
	}
	return 0;

}
