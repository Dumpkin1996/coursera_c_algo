#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

class Point{
public:
	int x;
	int y;
	int q;
	int j;
	Point(int _x, int _y, int _d, int _j):x(_x), y(_y), q(_d), j(_j){}
};

int number(int j){
	int result = 0;
	while (j){
		result += j%2;
		j/=2;
	}
	return result;
}

int t,r,c,k; 
char board[201][201];
bool visited[201][201][32] = {};

int main(){
	cin>>t;
	while(t--){	
		cin>>r>>c>>k;
		memset(visited,0,sizeof(visited));  
		bool success = 0;
		vector<Point> v;
		queue<Point> q;
		
		for (int i=0; i<r; i++)
			for (int j=0; j<c; j++){
				cin>>board[i][j];
				if (board[i][j]=='$')
					v.push_back(Point(i, j, -1, -1));
				if (board[i][j]=='S')
					q.push(Point(i, j, 0, 0));
			}

		
		while (!q.empty()){
			Point current = q.front();
			q.pop();		
			int cx = current.x; int cy =  current.y;
			int cd = current.q; int cj = current.j;	

			
			if (board[cx][cy]=='E' && number(cj)>=k){
				cout<<cd<<endl;
				success = 1;
				break;
			}
			
			if (board[cx][cy]>=48 && board[cx][cy]<=57){
				int pos = (int)board[cx][cy] - (int)'0';
				int test = cj;
				// cout<<"cd == "<<cd<<", test == "<<test<<endl;
				for(int i=0; i<pos; i++) test=test/2;
				if (test%2==0){
					cj += pow(2,pos);
					visited[cx][cy][cj] = 1;
					// cout<<"cj == "<<cj<<endl;
					// cout<<"jewlery number "<<pos<<" collected at point("<<cx<<" , "<<cy<<")"<<endl;
				}		
			}

			for (int i=0; i<4; i++)
				if ( cx+dx[i]<=r-1 && cx+dx[i]>=0 && cy+dy[i]<=c-1 && cy+dy[i]>=0 &&
				board[cx+dx[i]][cy+dy[i]]!='#' && visited[cx+dx[i]][cy+dy[i]][cj]==0 ){
					q.push(Point(cx+dx[i], cy+dy[i], cd+1, cj));
					visited[cx+dx[i]][cy+dy[i]][cj] = 1;
				}
			

			if (board[cx][cy]=='$'){
				vector<Point>::iterator it;
				for (it=v.begin(); it<v.end(); it++)
					for (int i=0; i<4; i++)
						if ( it->x+dx[i]<=r-1 && it->x+dx[i]>=0 && it->y+dy[i]<=c-1 && it->y+dy[i]>=0 &&
						board[it->x+dx[i]][it->y+dy[i]] != '#' && visited[it->x+dx[i]][it->y+dy[i]][cj]==0 ){
							q.push(Point(it->x+dx[i], it->y+dy[i], cd+1, cj));
							visited[it->x+dx[i]][it->y+dy[i]][cj] = 1;
						}
			}
		}
		if (!success) cout<<"oop!"<<endl;
	}
	return 0;
}