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

string solve(string::iterator &it) {
	char head = *it;
	it++;
	if (head == 'w' || head == 'b') return string(1, head);
	string upperLeft = solve(it);
	string upperRight = solve(it);
	string lowerLeft = solve(it);
	string lowerRight = solve(it);

	return string("x") + lowerLeft + lowerRight + upperLeft + upperRight;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	for (int tc = 0; tc < t; tc++) {
		cin >> str;
		string::iterator it = str.begin();
		cout << solve(it) << "\n";
	}
	return 0;
}
