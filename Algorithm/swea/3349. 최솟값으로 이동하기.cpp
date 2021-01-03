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

int W, H, N;
vector< pair<int, int> > vii;
int ans;

int check(int x, int y, int nx, int ny) {
	int res = 0;
	if ((nx<x && ny>y) || (nx > x && ny < y))
		res += abs(nx - x) + abs(ny - y);
	else
		res += min(abs(nx - x), abs(ny - y)) + (abs(nx - x) - abs(ny - y));
	return res;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		cin >> W >> H >> N;
		vii.clear();
		ans = 0;
		for (int i = 0; i < N; i++) {
			int x, y;
			cin >> x >> y;
			vii.push_back({ x,y });
		}
		int nx = vii[0].first;
		int ny = vii[0].second;
		for (int i = 1; i < N; i++) {
			ans += check(nx, ny, vii[i].first, vii[i].second);
			nx = vii[i].first;
			ny = vii[i].second;
		}
		printf("#%d %d\n", tc, ans);
	}
	return 0;

}
