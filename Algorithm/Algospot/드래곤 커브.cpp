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

#define INF 987654321
#define MOD 10000000

const int MAX = 1000000000 + 1;
const string EXPAND_X = "X+YF";
const string EXPAND_Y = "FX-Y";
int n, p, l;
int length[51];

void precalc() {
	length[0] = 1;
	for (int i = 1; i <= 50; i++) {
		length[i] = min(MAX,2 + 2 * length[i - 1]);
	}
}

char curve(const string &seed, int generations, int skip) {
	if (generations == 0) {
		return seed[skip];
	}
	


	for (int i = 0; i < seed.size(); i++) {
		if (seed[i] == 'X' || seed[i] == 'Y') {
			if (skip >= length[generations]) {
				skip -= length[generations];
			}
			else if (seed[i] == 'X')
				return curve(EXPAND_X, generations - 1, skip);
			else if (seed[i] == 'Y')
				return curve(EXPAND_Y, generations - 1, skip);
		}
		else if (skip > 0) skip--;
		else return seed[i];
	}
	return '#';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	for (int tc = 0; tc < t; tc++) {
		cin >> n >> p >> l;
		precalc();
		string ans = "FX";
		for (int i = p; i < p + l; i++) {
			cout << curve(ans, n, i - 1);
		}
		cout << "\n";
	}
	return 0;
}
