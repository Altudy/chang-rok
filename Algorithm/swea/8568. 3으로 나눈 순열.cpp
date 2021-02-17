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
int list1[1000][2];
bool visit[1000];

void swapValue(int i, int j) {
	int tmp0 = list1[i][0];
	list1[i][0] = list1[j][0];
	list1[j][0] = tmp0;
	int tmp1 = list1[i][1];
	list1[i][1] = list1[j][1];
	list1[j][1] = tmp1;
}

int main() {
	int t;
	scanf("%d", &t);
	for (int tc = 1; tc <= t; tc++) {
		scanf("%d", &N);
		memset(list1, 0, sizeof(list1));
		memset(visit, 0, sizeof(visit));
		for (int i = 0; i < N; i++) {
			scanf("%d", &list1[i][0]);
			list1[i][1] = list1[i][0] % 3;
		}
		int ans = 0;
		int cnt = 0;
		bool flag;
		for (int i = 0; i < N; i++) {
			if (list1[i][1] == (i + 1)%3) continue;
			flag = false;
			for (int j = i + 1; j < N; j++) {
				if (visit[j])continue;
				if (list1[i][1] == (j + 1) % 3 && list1[j][1] == (i + 1) % 3) {
					swapValue(i, j);
					visit[j] = true;
					ans++;
					flag = true;
					break;
				}
			}
			if (!flag) cnt++;
		}
		if (cnt != 0) {
			ans += (cnt / 3) * 2;
		}
		printf("#%d %d\n", tc, ans);
	}
	return 0;
}
