#include <iostream>
using namespace std;

int main(){
	int n,s; cin>>n>>s;
	long total = 0;
	int mincost = 10000;
	while (n--){
		int c,y; cin>>c>>y;
		mincost = min(mincost+s, c);
		total += mincost*y;
	}
	cout<<total<<endl;
}