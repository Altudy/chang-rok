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

struct Tree {
	Tree(): q1(0),q2(0),q3(0){}
	Tree operator+(Tree &t2) {
		t2.q1 += q1;
		t2.q2 += q2;
		t2.q3 += q3;
		return t2;
	}
	int q1;
	int q2;
	int q3;
};


int N, Q;
Tree tree[300005];
Tree m[100005];

Tree add(Tree t1, Tree t2) {
	return t1 + t2;
}

Tree init(int L, int R, int idx) {
	if (L == R) return tree[idx] = m[L];
	int mid = (L + R) / 2;
	return tree[idx] = add(init(L, mid, idx * 2),init(mid + 1, R, idx * 2 + 1));
}

void r_init() {
	for (int i = 0; i < 300005; i++) {
		tree[i].q1 = 0;
		tree[i].q2 = 0;
		tree[i].q3 = 0;
	}
	for (int i = 0; i < 100005; i++) {
		m[i].q1 = 0;
		m[i].q2 = 0;
		m[i].q3 = 0;
	}
}

Tree sum(int left, int right, int s, int e, int idx) {
	if (left > e || right < s) {
		Tree t;
		return t;
	}
	if (left <= s && e <= right) return tree[idx];
	int mid = (s + e) / 2;
	return add(sum(left, right, s, mid, idx * 2),sum(left, right, mid + 1, e, idx * 2 + 1));
}

int main() {
	

	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		cin >> N >> Q;
		r_init();
		vector<Tree> vt;
		for (int i = 0; i < N; i++) {
			int q;
			cin >> q;
			if (q == 1) m[i].q1++;
			else if (q == 2) m[i].q2++;
			else m[i].q3++;
		}
		init(0, N - 1, 1);
		for (int i = 0; i < Q; i++) {
			int l,r;
			cin >> l >> r;
			Tree t = sum(l-1, r-1, 0, N - 1, 1);
			vt.push_back(t);
		}
		cout << "#" << tc << "\n";
		for (int i = 0; i < vt.size(); i++) {
			cout << vt[i].q1 << " " << vt[i].q2 << " " << vt[i].q3 << "\n";
		}
	}
	return 0;
}
