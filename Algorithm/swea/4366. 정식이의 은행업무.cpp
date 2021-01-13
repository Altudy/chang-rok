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

string s1, s2;
long ans;

void pushValue(vector<long> &vm, string tmp) {
	long res = 0;
	int idx = 0;
	for (int i = tmp.length() - 1; i >= 0; i--) {
		if (tmp[i] == '1') {
			res += pow(2, idx);
		}
		idx++;
	}
	vm.push_back(res);
}

bool check(vector<long> vm, string tmp) {
	long res = 0;
	int idx = 0;
	for (int i = tmp.length() - 1; i >= 0; i--) {
		if (tmp[i] != '0') {
			res += (tmp[i]-'0')*pow(3, idx);
		}
		idx++;
	}
	for (auto n : vm) {
		if (n == res) {
			ans = res;
			return true;
		}
	}
	return false;
}

int main()
{
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		cin >> s1 >> s2;
		vector<long> vm;
		ans = 0;
		for (int i = 0; i < s1.length(); i++) {
			string tmp = s1;
			if (tmp[i] == '0') {
				tmp[i] = '1';
			}
			else {
				tmp[i] = '0';
			}
			pushValue(vm, tmp);
		}
		bool flag = false;
		for (int i = 0; i < s1.length(); i++) {
			string tmp = s2;
			for (int j = 0; j < 2; j++) {
				if (tmp[i] == '2') {
					tmp[i] = '0';
				}
				else if (tmp[i] == '1') {
					tmp[i] = '2';
				}
				else {
					tmp[i] = '1';
				}
				flag = check(vm, tmp);
			}
			if (flag) break;
		}
		printf("#%d %ld\n", tc, ans);
	}
	return 0;

}
