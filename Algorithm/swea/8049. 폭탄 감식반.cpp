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
bool visit[135];

bool isBoom(string s) {

	memset(visit, 0, sizeof(visit));

	int idx = 0;
	int location;
	while (true) {
		location = s.find("MCM", idx);
		if (location == string::npos) break;

		visit[location] = true;
		visit[location + 1] = true;
		visit[location + 2] = true;
		
		int i = location - 1;
		while (true) {
			if (i == -1)break;
			if (s[i] != 'F') {
				if (s[i] == 'M' && !visit[i]) {
					visit[i + 1] = false;
					i++;
				}
				break;
			}
			visit[i] = true;
			i--;
		}
		i++;
		if (location - i < 2)return false;

		i = location + 3;
		while (true) {
			if (i == s.length() || s[i]!='M')
				break;
			visit[i] = true;
			i++;
		}
		idx = location + 3;
	}

	idx = 0;
	while (true) {
		location = s.find("MF", idx);
		if (location == string::npos) break;

		idx = location + 2;
		if (visit[location])continue;

		visit[location] = true;
		visit[location + 1] = true;

		int i = location - 1;
		while (true) {
			if (i == -1 || s[i] != 'C') break;
			visit[i] = true;
			i--;
		}
		if (i == -1 || s[i] != 'F') return 0;
		else visit[i] = true;
	}

	for (int i = 0; i < s.length(); i++) {
		if (!visit[i]) return false;
	}
	return true;
}

int main() {
	int t;
	scanf("%d", &t);
	for (int tc = 1; tc <= t; tc++) {
		cin >> str;

		if (isBoom(str))
			printf("#%d DETECTED!\n", tc);
		else
			printf("#%d NOTHING!\n", tc);
	}
	return 0;
}
