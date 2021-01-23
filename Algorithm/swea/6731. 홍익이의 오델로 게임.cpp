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
char m[1001][1001];
int row[1001];
int col[1001];

bool getBlack(int x, int y) {
	int cnt = row[x]+col[y];
	if (m[x][y] == 'B') cnt--;
	if (cnt % 2 == 1) return true;
	else return false;
}

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		memset(m, 'W', sizeof(m));
		memset(row, 0, sizeof(row));
		memset(col, 0, sizeof(col));
		cin >> N;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> m[i][j];
				if (m[i][j] == 'B') {
					row[i]++;
					col[j]++;
				}
			}
		}
		int ans = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (getBlack(i, j)) ans++;
			}
		}
		printf("#%d %d\n", tc, ans);
	}
	return 0;
}
