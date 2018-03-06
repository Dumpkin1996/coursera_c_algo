#include <iostream>
using namespace std;

int f(int m, int n, int k){
	if (k==1) return 1;
	else if (n>=m && n<2*m) return 0;
	else return f(m, n-m, k-1) + f(m+1, n, k); 
}

int g(int m, int n){
	if (n==m) return 1;
	if (m>n) return 0;
	else return g(m+1, n-m)+g(m+1,n);
}

int h(int m, int n){
	if (n==m) return 1;
	if (m>n) return 0;
	else return h(m, n-m)+h(m+2,n);
}

int main(){
	int n,k;
	while (cin>>n>>k){
		cout<<f(1, n, k)<<endl;
		cout<<g(1,n)<<endl;
		cout<<h(1,n)<<endl;
	}
	return 0;
}