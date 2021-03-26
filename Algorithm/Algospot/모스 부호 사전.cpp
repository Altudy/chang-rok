## 완전탐색(시간초과)

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

int skip;

void generate(int n, int m, string s) {
	if (skip < 0) return;

	if (n == 0 && m == 0) {
		if(skip==0)
			cout << s << "\n";
		skip--;
		return;
	}

	if (n > 0) generate(n - 1, m, s + "-");
	if (m > 0) generate(n, m - 1, s + "o");
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	for (int tc = 0; tc < t; tc++) {
		int n, m, k;
		cin >> n >> m >> k;
		skip = k - 1;
		string ans = "";
		generate(n, m, ans);
	}
	return 0;
}

## 메모이제이션

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

const int M = 1000000000 + 100;
int skip;
int bino[201][201];

void precalc() {
	memset(bino, 0, sizeof(bino));
	for (int i = 0; i <= 200; i++) {
		bino[i][0] = bino[i][i] = 1;
		for (int j = 0; j < i; j++) {
			bino[i][j] = min(M,bino[i - 1][j - 1] + bino[i - 1][j]);
		}
	}
}

void generate(int n, int m, string s) {
	if (skip < 0) return;

	if (n == 0 && m == 0) {
		if (skip == 0) cout << s << "\n";
		skip--;
		return;
	}

	if (skip >= bino[n + m][n]) {
		skip -= bino[n + m][n];
		return;
	}

	if (n > 0) generate(n - 1, m, s + "-");
	if (m > 0) generate(n, m - 1, s + "o");
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	for (int tc = 0; tc < t; tc++) {
		int n, m, k;
		cin >> n >> m >> k;
		skip = k - 1;
		precalc();
		string ans = "";
		generate(n, m, ans);
	}
	return 0;
}

## 

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

const int M = 1000000000 + 100;
int skip;
int bino[201][201];

void precalc() {
	memset(bino, 0, sizeof(bino));
	for (int i = 0; i <= 200; i++) {
		bino[i][0] = bino[i][i] = 1;
		for (int j = 0; j < i; j++) {
			bino[i][j] = min(M,bino[i - 1][j - 1] + bino[i - 1][j]);
		}
	}
}

string kth(int n, int m) {
	if (n == 0) return string(m, 'o');

	if (skip < bino[n + m - 1][n - 1]) {
		return "-" + kth(n - 1, m);
	}
	else {
		skip -= bino[n + m - 1][n - 1];
		return "o" + kth(n, m - 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	for (int tc = 0; tc < t; tc++) {
		int n, m, k;
		cin >> n >> m >> k;
		skip = k - 1;
		precalc();
		cout << kth(n, m) <<"\n";
	}
	return 0;
}
