#include <iostream>
using namespace std;

long long result[300][300];

long long f(int m, int n){
	long long temp;
	if (result[m][n]!=-1) return result[m][n];
	if (n==0) temp = 1;
	else if (m>n) temp = 0;
	else if (n>=m && n< 2*m) temp = 1;
	else temp = f(m, n-2*m) + f(m+1,n);
	if (m>=0 && n>=0) result[m][n]=temp;
	return temp;
}

int main(){
	int x;
	for (int i=0; i<300; i++)
		for (int j=0; j<300; j++)
			result[i][j]=-1;
	while (true){
		cin>>x;
		if (x==0) return 0;
		else cout<<x<<' '<<f(1,x)<<endl;
	}
}