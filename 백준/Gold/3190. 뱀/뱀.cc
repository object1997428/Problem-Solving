#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <queue>
#pragma warning(disable:4996)
using namespace std;

typedef struct position {
	int x;
	int y;
}pos;
enum way { left=0,up,down,right };//enum은 int처럼, =은 없음
enum is { van=0, apple, snake };
enum is board[101][101];
enum way Nowway = right;
int time,n, nextturn_ind=0;
pos Now;
queue<pos> tempTale;
int times[101]; //[0][ind]=x초, [1][ind]=D or L
char ways[101];
int f(int y, int x, int t);
void move();
void turntoL();
void turntoD();
int main() {
	//freopen("a.inp", "r", stdin);
	//freopen("a.out", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i <= n; i++) {
		memset(board[i], van, sizeof(board[0]));
	}
	int k, l;
	scanf("%d", &k);//사과갯수
	int apple_y, apple_x;
	for (int i = 0; i < k; i++) {
		scanf("%d %d", &apple_y, &apple_x);
		board[apple_y][apple_x] = apple;
	}
	scanf("%d", &l);
	for (int i = 0; i < l; i++) {
		scanf("%d %c", &times[i], &ways[i]);
	}
	Now.x = 1;
	Now.y = 1;
	tempTale.push(Now);

	Nowway = right;

	int result=f(1, 1, 1);
	printf("%d\n", result);

	//fclose(stdin);
	//fclose(stdout);
}

int f(int y, int x,int t) {
	if (y == 1 && x == 1) {
		int w = 0;
	}
	move();
	if (Now.x <= 0 || Now.x > n || Now.y <= 0 || Now.y > n) {
		return t;
	}
	if (board[Now.y][Now.x] == snake) return t;
	if (board[Now.y][Now.x] == van) 
	{
		pos p = tempTale.front();
		tempTale.pop();
		board[p.y][p.x] = van;
	}
	board[Now.y][Now.x] = snake;
	tempTale.push(Now);

	if (t == times[nextturn_ind]) {
		if (ways[nextturn_ind] == 'L') turntoL();
		else turntoD();
		nextturn_ind++;
	}

	return f(Now.y, Now.x, t + 1);
}

void move() {
	if (Nowway == up) {
		Now.y--;
	}
	else if (Nowway == down) {
		Now.y++;
	}
	else if (Nowway == right) {
		Now.x++;
	}
	else if (Nowway == left) {
		Now.x--;
	}
}

void turntoL() {
	if (Nowway == up) Nowway = left;
	else if (Nowway == right) Nowway = up;
	else if (Nowway == down) Nowway = right;
	else Nowway = down;
	
	return;
}

void turntoD() {
	if (Nowway == up) Nowway = right;
	else if (Nowway == right) Nowway = down;
	else if (Nowway == down) Nowway = left;
	else Nowway = up;

	return;
}

