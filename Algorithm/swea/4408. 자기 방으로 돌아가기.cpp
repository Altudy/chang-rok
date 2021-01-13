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

int room[3][200];
bool visited[3][200];
int dist[3][200];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int N, a, b, sx, sy, ex, ey, turn;

void init() {
	if (a % 2 == 1) sx = 0;
	else sx = 2;
	sy = (a - 1) / 2;

	if (b % 2 == 1) ex = 0;
	else ex = 2;
	ey = (b - 1) / 2;

	if (a < b) turn = 0;//right
	else turn = 1;	
}

void sol() {
	queue< pair<int, int> > q;
	q.push({ sx,sy });
	visited[sx][sy] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();


		if (room[x][y] == b) return;

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= 3 || ny < 0 || ny >= 200) continue;
			if (visited[nx][ny]) continue;
			if (nx!=1 && room[nx][ny] != b) continue;
			if (turn == 0 && ny < y)continue;
			if (turn == 1 && ny > y)continue;
			if (turn == 0 && ny > ey) continue;
			if (turn == 1 && ny < ey)continue;
			visited[nx][ny] = true;
			q.push({ nx,ny });
			dist[nx][ny]++;
		}
	}
}

int main()
{
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		int num = 1;
		int ans = 0;
		for (int j = 0; j < 200; j++) {
			for (int i = 0; i < 3; i++) {
				if (i == 1) {
					room[i][j] = 0;
				}
				else {
					room[i][j] = num++;
				}
				dist[i][j] = 0;
			}
		}
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> a >> b;
			memset(visited, 0, sizeof(visited));
			init();
			sol();
		}
		for (int i = 0; i < 200; i++) {
			ans = max(ans, dist[1][i]);
		}
		cout << "#" << tc << " " << ans << "\n";
	}
	return 0;

}
