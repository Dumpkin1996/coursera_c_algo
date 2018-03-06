#include <iostream>
#include <queue>
using namespace std;

class Point{
public:
	int x;
	int y;
	int d;
	Point(int _x, int _y, int _d):x(_x), y(_y), d(_d) {}
	Point():x(-1),y(-1),d(-1){}
};


int main(){
	int t; cin>>t;
	while (t--){
		int r,c; cin>>r>>c;
		int sx; int sy;
		char board[r][c];
		int visited[r][c];
		for (int i=0; i<r; i++)
			for(int j=0; j<c; j++){
				cin>>board[i][j];
				if (board[i][j]=='S'){
					sx = i; sy = j;
				}
				visited[i][j]=0;
			}
		queue<Point> q;
		q.push(Point(sx,sy,0));
		int result = 0;
		bool flag  = 0;

		while(!q.empty()){
			Point current = q.front();
			int cx = current.x; int cy = current.y; int cd = current.d;
			if(board[cx][cy]=='E'){
				flag = 1;
				result = cd;
				break;
			}
			else{
				q.pop();
				if (cx+1<=r-1 && board[cx+1][cy]!='#' && visited[cx+1][cy]==0){
					q.push(Point(cx+1, cy, cd+1));
					visited[cx+1][cy] = 1;			
				}
				if (cx-1>=0 && board[cx-1][cy]!='#' && visited[cx-1][cy]==0){
					q.push(Point(cx-1, cy, cd+1));
					visited[cx-1][cy] = 1;	
				}
				if (cy+1<=c-1 && board[cx][cy+1]!='#' && visited[cx][cy+1]==0){
					q.push(Point(cx, cy+1, cd+1));
					visited[cx][cy+1] = 1;	
				}
				if (cy-1>=0 && board[cx][cy-1]!='#' && visited[cx][cy-1]==0){
					q.push(Point(cx, cy-1, cd+1));
					visited[cx][cy-1] = 1;	
				}
			}
		}

		if (flag) cout<<result<<endl;
		else cout<<"oop!"<<endl;
	}
}