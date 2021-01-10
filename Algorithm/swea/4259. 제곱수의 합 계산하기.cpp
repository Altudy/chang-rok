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

#define ll long long 


string str_sum(string num1, string num2) {
	string res = "";
	int asc = 0, tmp;
	while (num1.length() > num2.length()) {
		num2 = '0' + num2;
	}
	while (num1.length() < num2.length()) {
		num1 = '0' + num1;
	}
	for (int i = num1.length() - 1; i >= 0; i--) {
		tmp = (num1[i] - '0') + (num2[i] - '0');
		tmp += asc;
		asc = tmp / 10;
		tmp %= 10;
		res = (char)(tmp + '0') + res;
	}
	if (asc != 0) {
		res = '1' + res;
	}
	return res;
}

string power_of_n(string number, int p) {
	string buf;
	int n1,n2;
	int asc = 0;
	string result[3];

	if (p == 0) return "1";
	buf = number;
	for (int k = 1; k < p; k++) {
		result[0] = "";
		result[1] = "";
		result[2] = "";
		for (int i = number.length() - 1; i >= 0; i--) {
			n1 = number[i] - '0';
			for (int j = buf.length() - 1; j >= 0; j--) {
				n2 = buf[j] - '0';
				n2 *= n1;
				n2 += asc;
				asc = n2 / 10;
				n2 %= 10;
				result[i] = (char)(n2 + '0') + result[i];
			}
			if (asc != 0) {
				result[i] = (char)(asc + '0') + result[i];
				asc = 0;
			}
			for (int j = number.length() - 1; j > i; j--) {
				result[i] += '0';
			}
		}
		buf = "0";
		for (int j = number.length()-1; j >= 0; j--) {
			buf = str_sum(buf, result[j]);
		}
	}
	return buf;
}

int main()
{
	int t;
	int n;
	string num, a;
	int power;
	string ans;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		cin >> n;
		ans = "0";
		for (int i = 0; i < n; i++) {
			cin >> num;
			power = num[num.length() - 1] - '0';
			a = num.substr(0, num.length() - 1);
			ans = str_sum(ans,power_of_n(a, power));
		}
		cout << "#" << tc << " " << ans << "\n";
	}
	return 0;

}
