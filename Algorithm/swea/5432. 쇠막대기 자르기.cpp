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
stack<char> s;

int main() {
	
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		cin >> str;
		int ans = 0;
		for (int i = 0; i < str.length(); i++) {
			if (str[i] == '(') s.push(i);
			else if (str[i] == ')') {
				s.pop();
				if (i!=0 && str[i - 1] == '(') {
					ans += s.size();
				}
				else ans += 1;
			}
		}
		cout << "#" << tc << " " << ans << "\n";
	}
	return 0;
}
