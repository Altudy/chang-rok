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

string word[10] = { "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
string S;
int N;

bool check(string s) {
	for (int i = 0; i < S.length(); i++) {
		int n = S[i]-'0';
		if (word[n].find(s[i]) == string::npos) return false;
	}
	return true;
}

int main()
{
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		cin >> S >> N;
		int word_size = S.length();
		int ans = 0;
		vector<string> vs;
		for (int i = 0; i < N; i++) {
			string s;
			cin >> s;
			if (s.length() == word_size) vs.push_back(s);
		}
		for (int i = 0; i < vs.size(); i++) {
			string str = vs[i];
			if (check(str)) ans++;
		}
		printf("#%d %d\n", tc, ans);
	}
	return 0;

}
