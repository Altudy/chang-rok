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


int X, Y, Z, A, B, C, N;

int main()
{
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		scanf("%d %d %d %d %d %d %d", &X, &Y, &Z, &A, &B, &C, &N);
		long long arr[3][1001] = { 0 };
		long long ans[2][1001] = { 0 };
		for (int i = 0; i < X; i++) {
			arr[0][abs(i - A) % N]++;
		}
		for (int i = 0; i < Y; i++) {
			arr[1][abs(i - B) % N]++;
		}
		for (int i = 0; i < Z; i++) {
			arr[2][abs(i - C) % N]++;
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				ans[0][(i + j) % N] += arr[0][i] * arr[1][j];
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				ans[1][(i + j) % N] += ans[0][i] * arr[2][j];
			}
		}
		printf("#%d ", tc);
		for (int i = 0; i < N; i++) {
			printf("%lld ", ans[1][i]);
		}
		printf("\n");
	}
	return 0;

}
