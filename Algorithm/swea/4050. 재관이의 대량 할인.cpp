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
int main()
{
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		cin >> N;
		vector<int> price;
		int ans = 0,tot = 0;
		for (int i = 0; i < N; i++) {
			int p;
			cin >> p;
			price.push_back(p);
			tot += p;
		}
		sort(price.begin(), price.end(), greater<int>());
		int i = 2;
		while (i < N) {
			ans += price[i];
			i += 3;
		}
		printf("#%d %d\n", tc, tot-ans);

	}
	return 0;

}
