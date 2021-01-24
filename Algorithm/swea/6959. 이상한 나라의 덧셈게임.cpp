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

string str;

int main() {
	

	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		cin >> str;
		stack<int> s;
		for (int i = 0; i < str.length(); i++) {
			s.push(str[i] - '0');
		}
		int cnt = 0;
		while (s.size() != 1) {
			int n1 = s.top();
			s.pop();
			int n2 = s.top();
			s.pop();
			int res = n1 + n2;
			if (res >= 10) {
				s.push(res % 10);
				s.push(res / 10);
			}
			else s.push(res);
			cnt++;
		}
		if (cnt % 2 == 0) {
			printf("#%d B\n", tc);
		}
		else printf("#%d A\n", tc);
	}
	return 0;
}
