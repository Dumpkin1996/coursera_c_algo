#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class Point{
public:
	int x;
	int y;
	Point(int _x, int _y):x(_x), y(_y) {}
	Point():x(-1),y(-1){}
};

ostream & operator<< (ostream & o, Point p){
	o<<"("<<p.x<<", "<<p.y<<")";
	return o;
}

int board[5][5];
Point previous[5][5];

int main(){
	int board[5][5];

	for (int i=0; i<5; i++)
		for(int j=0; j<5; j++)
			cin>>board[i][j];
	
	queue<Point> q;
	q.push(Point(0,0));
	board[0][0]=1;
	
	while(!q.empty()){
		Point current = q.front();
		int cx = current.x; int cy = current.y;

		if(cx==4&&cy==4) break;
		else{
			q.pop();
			if (cx+1<=4 && board[cx+1][cy]==0){
				q.push(Point(cx+1,cy));
				board[cx+1][cy] = 1;
				previous[cx+1][cy] = current;				
			}
			if (cx-1>=0 && board[cx-1][cy]==0){
				q.push(Point(cx-1, cy));
				board[cx-1][cy] = 1;
				previous[cx-1][cy] = current;
			}
			if (cy+1<=4 && board[cx][cy+1]==0){
				q.push(Point(cx, cy+1));
				board[cx][cy+1] = 1;
				previous[cx][cy+1] = current;
			}
			if (cy-1>=0 && board[cx][cy-1]==0){
				q.push(Point(cx, cy-1));
				board[cx][cy-1] = 1;
				previous[cx][cy-1] = current;
			}
		}
	}


	stack<Point> result;
	int i=4, j=4;
	result.push(Point(4,4));
	while (! (i==0&&j==0)){
		result.push(previous[i][j]);
		int tempi = i; int tempj = j;
		i = previous[tempi][tempj].x;
		j = previous[tempi][tempj].y;
	}
	while (!result.empty()){
		cout<<result.top()<<endl;
		result.pop();
	}
	return 0;
}