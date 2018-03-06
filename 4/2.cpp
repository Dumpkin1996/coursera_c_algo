#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

class Point{
public:
	int i,j,h;
	Point(int _i, int _j, int _h):i(_i), j(_j), h(_h){}
	Point():i(-1), j(-1), h(-1){}
};

class Mycompare{
public:
	bool operator() (const Point & x, const Point & y) const{
		return x.h < y.h;
	}
};

multiset<Point, Mycompare> field;
int height[100][100];
int length[100][100];

int main(){
	int r,c; cin>>r>>c;
	for (int i=0; i<r; i++)
		for (int j=0; j<c; j++){
			int h; cin>>h;
			field.insert(Point(i, j,h));
			height[i][j] = h;
			length[i][j] = 1;
		}
	multiset<Point, Mycompare>::iterator p = field.begin();
	for ( ; p != field.end(); p++){
		if (p->i-1>=0 && p->i-1<r && height[p->i-1][p->j]<height[p->i][p->j])
			length[p->i][p->j] = max(length[p->i-1][p->j]+1, length[p->i][p->j]);
		
		if (p->i+1>=0 && p->i+1<r && height[p->i+1][p->j]<height[p->i][p->j])
			length[p->i][p->j] = max(length[p->i+1][p->j]+1, length[p->i][p->j]);
		
		if (p->j-1>=0 && p->j-1<c && height[p->i][p->j-1]<height[p->i][p->j])
			length[p->i][p->j] = max(length[p->i][p->j-1]+1, length[p->i][p->j]);
	
		if (p->j+1>=0 && p->j+1<r && height[p->i][p->j+1]<height[p->i][p->j])
			length[p->i][p->j] = max(length[p->i][p->j+1]+1, length[p->i][p->j]);
	}

	int result = 0;
	for (int i=0; i<r; i++)
		for (int j=0; j<c; j++){
			result = max(result, length[i][j]);
		}

	cout<<result<<endl;

	return 0;
}