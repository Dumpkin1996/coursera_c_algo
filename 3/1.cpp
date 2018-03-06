#include <iostream>
using namespace std;

int f(int n){
	if (n==0) return 1;
	if (n%2!=0) return 0;
	if (n==2) return 3;
	int result = 3*f(n-2)+2;
	for (int i=2; i<n/2; i++)
		result += f(n-2*i)*2;
	return result;
}


int main(){
	int n;
	while (true){
		cin>>n;
		if(n==-1) break;
		cout<<f(n)<<endl;
	}
	return 0;
}