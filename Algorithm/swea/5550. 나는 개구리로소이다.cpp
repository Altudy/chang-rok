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

int get_i(char c) {
	switch (c)
	{
		case 'c':
			return 0;
		case 'r':
			return 1;
		case 'o':
			return 2;
		case 'a':
			return 3;
		case 'k':
			return 4;
	}
}

int main() {
	
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		cin >> str;
		vector<int> croak;
		int ans = 0;
		for (int i = 0; i < str.length(); i++) {
			int n = get_i(str[i]);
			bool check = false;

			for (int j = 0; j < croak.size(); j++) {
				if (croak[j] == n) {
					croak[j]++;
					if (croak[j] == 5)
						croak[j] = 0;
					check = true;
					break;
				}
			}

			if (!check) {
				if (n == 0) croak.push_back(1);
				else {
					ans = -1;
					break;
				}
			}
		}

		if (ans != -1) {
			ans = croak.size();
			for (int i = 0; i < croak.size(); i++) {
				if (croak[i] != 0) ans = -1;
			}
		}
		cout << "#" << tc << " " << ans << "\n";
	}
	return 0;
}
