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
string dir;
int m[21][21];
int ans[21][21];
bool check[21][21];

void solve() {
	if (dir == "up") {
		for (int j = 0; j < N; j++) {
			int c = 0;
			for (int i = 0; i < N; i++) {
				if (m[i][j] == 0) continue;
				else {
					ans[c][j] = m[i][j];
					if (c != 0 && ans[c - 1][j] == ans[c][j] && !check[c - 1][j]) {
						ans[c - 1][j] *= 2;
						ans[c][j] = 0;
						check[c - 1][j] = true;
					}
					else c++;
				}
			}
		}
	}
	else if (dir == "down") {
		for (int j = 0; j < N; j++) {
			int c = N-1;
			for (int i = N-1; i >= 0; i--) {
				if (m[i][j] == 0) continue;
				else {
					ans[c][j] = m[i][j];
					if (c != N-1 && ans[c + 1][j] == ans[c][j] && !check[c + 1][j]) {
						ans[c + 1][j] *= 2;
						ans[c][j] = 0;
						check[c + 1][j] = true;
					}
					else c--;
				}
			}
		}
	}
	else if (dir == "left") {
		for (int i = 0; i < N; i++) {
			int c = 0;
			for (int j = 0; j < N; j++) {
				if (m[i][j] == 0) continue;
				else {
					ans[i][c] = m[i][j];
					if (c != 0 && ans[i][c-1] == ans[i][c] && !check[i][c-1]) {
						ans[i][c-1] *= 2;
						ans[i][c] = 0;
						check[i][c-1] = true;
					}
					else c++;
				}
			}
		}
	}
	else {
		for (int i = 0; i < N; i++) {
			int c = N-1;
			for (int j = N-1; j >= 0; j--) {
				if (m[i][j] == 0) continue;
				else {
					ans[i][c] = m[i][j];
					if (c != N-1 && ans[i][c + 1] == ans[i][c] && !check[i][c + 1]) {
						ans[i][c + 1] *= 2;
						ans[i][c] = 0;
						check[i][c + 1] = true;
					}
					else c--;
				}
			}
		}
	}
}

int main() {
	
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		memset(m, 0, sizeof(m));
		memset(ans, 0, sizeof(ans));
		memset(check, 0, sizeof(check));
		cin >> N;
		cin >> dir;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> m[i][j];
			}
		}
		solve();
		cout << "#" << tc << "\n";
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cout << ans[i][j] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
