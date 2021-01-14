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

long long A, B;

long long fn(long long n) {
	long long res = 0;
	long long pow = 1;
	while (n > 0) {
		res += ((n % 10) > 4) ? ((n % 10) - 1)*pow : (n % 10)*pow;
		n /= 10;
		pow *= 9;
	}
	return res;
}

int main()
{
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		cin >> A >> B;
		long long ans;
		if (B < 0) ans = fn(-A) - fn(-B);
		else {
			if (A < 0) ans = fn(-A) + fn(B) - 1;
			else ans = fn(B) - fn(A);
		}
		cout << "#" << tc << " " << ans << "\n";
	}
	return 0;

}
