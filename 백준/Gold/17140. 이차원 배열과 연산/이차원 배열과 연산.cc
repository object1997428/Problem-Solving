#include <iostream>
#include <string.h>
#include <string>
#include <climits>
#include <cassert>
#include <cmath>
#include <algorithm>
#include <vector>
#pragma warning(disable:4996)
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
#define endl '\n'

int r, c, k;
int arr[1001][1001];
int RnumCnt[101][101], CnumCnt[101][101];
int R, C;

void init() {
	cin >> r >> c >> k; r--, c--;
	R = C = 3;
	for (int i = 0; i < 3; i++)for (int j = 0; j < 3; j++) {
		cin >> arr[i][j];
		int num = arr[i][j];
		RnumCnt[i][num]++; CnumCnt[j][num]++;
	}
	if (arr[r][c] == k) {
		cout << "0";
		exit(0);
	}
}

int arrCopy[1001][1001];
int RnumCntCopy[101][101], CnumCntCopy[101][101];
void saveNum(int row, int col, int num) {
	RnumCntCopy[row][num]++;
	CnumCntCopy[col][num]++;
}

vector<pii> v;

void Rcal() {
	memset(arrCopy, 0, sizeof(arrCopy));
	memset(RnumCntCopy, 0, sizeof(RnumCntCopy));
	memset(CnumCntCopy, 0, sizeof(CnumCntCopy));
	C = 0;
	for (int i = 0; i < R; i++) {
		int idx = 0;
		v.clear();
		for (int j = 1; j <= 100; j++) {
			int num = j;
			if (RnumCnt[i][num] > 0) {
				v.push_back({ RnumCnt[i][num],num });
			}
		}
		sort(v.begin(), v.end());
		for (int j = 0; j < v.size(); j++) {
			int num = v[j].second;
			arrCopy[i][idx] = num;
			saveNum(i, idx++, num);

			int num2 = v[j].first;
			arrCopy[i][idx] = num2;
			saveNum(i, idx++, num2);
		}
		C = max(C, idx);
	}

	for (int i = 0; i < R; i++)for (int j = 0; j < C; j++)arr[i][j] = arrCopy[i][j];
	for (int i = 0; i <= 100; i++)for (int j = 0; j <= 100; j++) RnumCnt[i][j] = RnumCntCopy[i][j], CnumCnt[i][j] = CnumCntCopy[i][j];
}



void Ccal() {
	memset(arrCopy, 0, sizeof(arrCopy));
	memset(RnumCntCopy, 0, sizeof(RnumCntCopy));
	memset(CnumCntCopy, 0, sizeof(CnumCntCopy));
	R = 0;
	for (int i = 0; i < C; i++) {
		int idx = 0;
		v.clear();

		for (int j = 1; j <= 100; j++) {
			int num = j;
			if (CnumCnt[i][num] > 0) {
				v.push_back({ CnumCnt[i][num],num });
			}
		}
		sort(v.begin(), v.end());
		for (int j = 0; j < v.size(); j++) {
			int num = v[j].second; //num
			arrCopy[idx][i] = num;
			saveNum(idx++, i, num);

			int num2 = v[j].first; //count
			arrCopy[idx][i] = num2;
			saveNum(idx++, i, num2);
		}
		R = max(R, idx);
	}

	for (int i = 0; i < R; i++)for (int j = 0; j < C; j++) arr[i][j] = arrCopy[i][j];
	for (int i = 0; i <= 100; i++)for (int j = 0; j <= 100; j++) RnumCnt[i][j] = RnumCntCopy[i][j], CnumCnt[i][j] = CnumCntCopy[i][j];
}

void solve() {
	for (int t = 1; t <= 100; t++) {
		if (R >= C) Rcal();
		else Ccal();

		if (arr[r][c] == k) {
			cout << t;
			exit(0);
		}
	}
	cout << -1;
}

int main() {
	//freopen("a.txt", "r", stdin);

	init();
	solve();

	//fclose(stdout);
}