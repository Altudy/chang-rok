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

#define INF 9999

int t, n, m;
string str;
vector<int> height;


int solve(int left, int right) {
	if (left == right) return height[left];

	int mid = (left + right) / 2;

	int ret = max(solve(left,mid),solve(mid+1,right));

	int lo = mid, hi = mid + 1;
	int minheight = min(height[lo], height[hi]);
	ret = max(ret,minheight * 2);
	while (left < lo || hi < right) {
		if (hi <right && (lo==left || height[lo - 1] < height[hi + 1])) {
			hi++;
			minheight = min(minheight, height[hi]);
		}
		else {
			lo--;
			minheight = min(minheight, height[lo]);
		}
		ret = max(ret, minheight*(hi - lo + 1));
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	for (int tc = 0; tc < t; tc++) {
		cin >> n;
		height.clear();
		for (int i = 0; i < n; i++) {
			int num;
			cin >> num;
			height.push_back(num);
		}
		cout << solve(0, n - 1) <<"\n";
	}
	return 0;
}
