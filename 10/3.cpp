#include <iostream>
using namespace std;

int f(int m, int n){
	if (n>=m && n<2*m) return 1;
	else return f(m, n-m)+f(m+1,n);
}

int main(){
	int x;
	while (cin>>x)
		cout<<f(1, x)<<endl;
	return 0;
}