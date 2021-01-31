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

string X;
int len1[3] = { 1,2,5 };
int len2[4] = { 10,20,25,50 };
int len3[5] = { 100,125,200,250,500 };

int main() {
	int t;
	scanf("%d", &t);
	for (int tc = 1; tc <= t; tc++) {
		cin >> X;
		int ans = 0;
		int n = stoi(X);
		if (X.length() == 1) {
			for (int i = 0; i < 3; i++) {
				if (n >= len1[i])ans++;
				else break;
			}
		}
		else if (X.length() == 2) {
			ans += 3;
			for (int i = 0; i < 4; i++) {
				if (n >= len2[i])ans++;
				else break;
			}
		}
		else {
			for (int i = 0; i < X.length() - 1; i++) {
				if (i == 0) ans += 3;
				else if (i == 1) ans += 4;
				else ans += 5;
			}
			string tmp = X.substr(0, 3);
			int num = stoi(tmp);
			for (int i = 0; i < 5; i++) {
				if (num >= len3[i])ans++;
				else break;
			}
		}
		printf("#%d %d\n", tc, ans);
	}
	return 0;
}
