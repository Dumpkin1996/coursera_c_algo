#include <iostream>
using namespace std;

int gcd(int n, int m){
	if(n<m) return gcd(m,n);
	else{
		if(n%m==0) return m;
		else return gcd(n%m, m);
	}
}


int main(){
	int m,n;
	while(cin>>m>>n)
		cout<<gcd(n,m)<<endl;
}