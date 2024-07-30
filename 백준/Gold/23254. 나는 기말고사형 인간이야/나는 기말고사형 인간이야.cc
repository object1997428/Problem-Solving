#include <iostream>
#include <string.h>
#include <string>
#include <climits>
#include <cassert>
#include <cmath>
#include <algorithm>
#include <queue>
#pragma warning(disable:4996)
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
#define endl '\n'

int N, M;
vector<pii> v;
vector<pii> v2;
priority_queue<pii> q;
int sum = 0;
void init() {
	cin >> N >> M;
	v.resize(M, {-1,-1});
	for (int i = 0; i < M; i++) {
		int a; cin >> a;
		v[i].second = a;
		sum += a;
	}
	for (int i = 0; i < M; i++) {
		int b; cin >> b;
		v[i].first = b;
	}
	for (int i = 0; i < M; i++) {
		q.push({ min(v[i].first,100 - v[i].second),100 - v[i].second });
	}
}

void solve() {
	int t = N * 24;
	while (!q.empty() && t > 0) {
		int a = 100-q.top().second, b = q.top().first;
		q.pop();

		if (100 - a > 0) {
			t--;
			if (100 - a <= b) sum += 100 - a;
			else {
				sum += b;
				q.push({ min(b,100-a-b),100-a - b });
			}
		}
		else if (100 - a == 0) continue;
		else assert(0);
	}

	cout << sum << endl;
}

int main() {
	//freopen("a.txt", "r", stdin);

	init();
	solve();

	//fclose(stdout);
}