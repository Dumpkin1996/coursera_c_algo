#include <iostream>
#include <queue>
using namespace std;

class Point{
public:
	int a;
	int x;
	int y;
	int d;
	Point(int _a, int _x, int _y):a(_a), x(_x), y(_y){}
};


int main(){
	int t; cin>>t;
	while (t--){
		int k; cin>>k;
		bool cube[6][20][20];

		for (int a=0; a<6; a++)
			for (int i=0; i<20; i++)
				for (int j=0; j<20; j++)
					cube[a][i][j] = 0;

		for (int a=0; a<6; a++)
			for (int i=0; i<k; i++)
				for (int j=0; j<k; j++)
					cin>>cube[a][i][j];

		int result = 0;
		int max = 0;
		for (int a=0; a<6; a++)
			for (int i=0; i<k; i++)
				for (int j=0; j<k; j++)
					if (cube[a][i][j]==0){
						// cout<<"new room !"<<endl;
						queue<Point> q;
						int area = 0;
						q.push(Point(a, i, j));
						cube[a][i][j]=1;
						while (!q.empty()){
							Point current = q.front();
							q.pop();
							area++;
							int ca = current.a; int cx = current.x; int cy = current.y;
							// cout<<"point ("<<ca<<", "<<cx<<", "<<cy<<") added !"<<endl;
							if (cx+1<=k-1 && cube[ca][cx+1][cy]==0){
								q.push(Point(ca, cx+1,cy));
								cube[ca][cx+1][cy] = 1;				
							}
							if (cx-1>=0 && cube[ca][cx-1][cy]==0){
								q.push(Point(ca, cx-1, cy));
								cube[ca][cx-1][cy] = 1;
							}
							if (cy+1<=k-1 && cube[ca][cx][cy+1]==0){
								q.push(Point(ca, cx, cy+1));
								cube[ca][cx][cy+1] = 1;
							}
							if (cy-1>=0 && cube[ca][cx][cy-1]==0){
								q.push(Point(ca, cx, cy-1));
								cube[ca][cx][cy-1] = 1;
							}
							
							if (cx==0){
								switch (ca){
									case 0:{
										if (cube[4][k-1][cy]==0){
											q.push(Point(4, k-1, cy));
											cube[4][k-1][cy] = 1;
										}
										break;
									}
									case 1:{
										if (cube[4][k-1-cy][k-1]==0){
											q.push(Point(4, k-1-cy, k-1));
											cube[4][k-1-cy][k-1] = 1;
										}
										break;
									}
									case 2:{
										if (cube[4][0][k-1-cy]==0){
											q.push(Point(4, 0, k-1-cy));
											cube[4][0][k-1-cy] = 1;
										}
										break;
									}
									case 3:{
										if (cube[4][cy][0]==0){
											q.push(Point(4, cy, 0));
											cube[4][cy][0] = 1;
										}
										break;
									}
									case 4:{
										if (cube[2][0][k-1-cy]==0){
											q.push(Point(2, 0, k-1-cy));
											cube[2][0][k-1-cy] = 1;
										}
										break;
									}
									case 5:{
										if (cube[2][k-1][k-1-cy]==0){
											q.push(Point(2, k-1, k-1-cy));
											cube[2][k-1][k-1-cy] = 1;
										}
									}
								}
							}

							if (cx==k-1){
								switch (ca){
									case 0:{
										if (cube[5][k-1][cy]==0){
											q.push(Point(5, k-1, cy));
											cube[5][k-1][cy] = 1;
										}
										break;
									}
									case 1:{
										if (cube[5][k-1-cy][k-1]==0){
											q.push(Point(5, k-1-cy, k-1));
											cube[5][k-1-cy][k-1] = 1;
										}
										break;
									}
									case 2:{
										if (cube[5][0][k-1-cy]==0){
											q.push(Point(5, 0, k-1-cy));
											cube[5][0][k-1-cy] = 1;
										}
										break;
									}
									case 3:{
										if (cube[5][cy][0]==0){
											q.push(Point(5, cy, 0));
											cube[5][cy][0] = 1;
										}
										break;
									}
									case 4:{
										if (cube[0][0][cy]==0){
											q.push(Point(0, 0, cy));
											cube[0][0][cy] = 1;
										}
										break;
									}
									case 5:{
										if (cube[0][k-1][cy]==0){
											q.push(Point(0, k-1, cy));
											cube[0][k-1][cy] = 1;
										}
									}								}

							}

							if (cy==0){
								switch (ca){
									case 0:{
										if (cube[3][cx][k-1]==0){
											q.push(Point(3, cx, k-1));
											cube[3][cx][k-1] = 1;
										}
										break;
									}
									case 1:{
										if (cube[0][cx][k-1]==0){
											q.push(Point(0, cx, k-1));
											cube[0][cx][k-1] = 1;
										}
										break;
									}
									case 2:{
										if (cube[1][cx][k-1]==0){
											q.push(Point(1, cx, k-1));
											cube[1][cx][k-1] = 1;
										}
										break;
									}
									case 3:{
										if (cube[2][cx][k-1]==0){
											q.push(Point(2, cx, k-1));
											cube[2][cx][k-1] = 1;
										}
										break;
									}
									case 4:{
										if (cube[3][0][cx]==0){
											q.push(Point(3, 0, cx));
											cube[3][0][cx] = 1;
										}
										break;
									}
									case 5:{
										if (cube[3][k-1][cx]==0){
											q.push(Point(3, k-1, cx));
											cube[3][k-1][cx] = 1;
										}
									}
								}
							}

							if (cy==k-1){
								switch (ca){
									case 0:{
										if (cube[1][cx][0]==0){
											q.push(Point(1, cx, 0));
											cube[1][cx][0] = 1;
										}
										break;
									}
									case 1:{
										if (cube[2][cx][0]==0){
											q.push(Point(2, cx, 0));
											cube[2][cx][0] = 1;
										}
										break;
									}
									case 2:{
										if (cube[3][cx][0]==0){
											q.push(Point(3, cx, 0));
											cube[3][cx][0] = 1;
										}
										break;
									}
									case 3:{
										if (cube[0][cx][0]==0){
											q.push(Point(0, cx, 0));
											cube[0][cx][0] = 1;
										}
										break;
									}
									case 4:{
										if (cube[1][0][k-1-cx]==0){
											q.push(Point(1, 0, k-1-cx));
											cube[1][0][k-1-cx] = 1;
										}
										break;
									}
									case 5:{
										if (cube[1][k-1][k-1-cx]==0){
											q.push(Point(1, k-1, k-1-cx));
											cube[1][k-1][k-1-cx] = 1;
										}
									}
								}
							}
						}
						result ++;
						if (area > max) max = area;
					}
		cout<<result<<' '<<max<<endl;
	}
	return 0;
}