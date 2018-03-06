#include <iostream>
using namespace std;

int rio[1025][1025];
int ability[1025][1025];


int main(){
	int t; cin>>t;
	while(t--){
		int d; cin>>d;
		int n; cin>>n;
		for (int i=0; i<1025; i++)
			for (int j=0; j<1025; j++){
				rio[i][j] = 0;
				ability[i][j] = 0;
			}
		for (int k=0; k<n; k++){
			int x; int y; int c;
			cin>>x>>y>>c;
			rio[x][y] = c;
			for (int xi=x-d; xi<=x+d; xi++)
				if (xi>=0&&xi<=1024)
					for (int yi=y-d; yi<=y+d; yi++)
						if(yi>=0&&yi<=1024)
							ability[xi][yi]+=c;
		}
		int max = -1;
		int num = 0;


		for (int i=0; i<=1024; i++)
			for (int j=0; j<=1024; j++){
				if (ability[i][j]>max){
					max = ability[i][j];
					num = 1;
				}
				else if (ability[i][j]==max)
					num++;
			}

		cout<<num<<' '<<max<<endl;
	}
}