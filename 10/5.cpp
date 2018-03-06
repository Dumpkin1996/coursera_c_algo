#include <iostream>
using namespace std;

int main(){
	while (true){
		int x; cin>>x;
		if (x==0) return 0;
		else if (x==1) cout<<2<<endl;
		else if (x==2) cout<<7<<endl;
		else{
			long result = 1;
			for (int i=0; i<x; i++) result*=x;
			cout<<result+1-x<<endl;
		}
	}
	return 0;
}