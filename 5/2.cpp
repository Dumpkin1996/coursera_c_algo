#include <iostream>
using namespace std;

int n,m;
int w[4000];
int d[4000];
int c[12880] = {0};

int main(){
	cin>>n>>m;
	for (int i=0; i<n; i++)
		cin>>w[i]>>d[i];
	for (int i=0; i<n; i++)
		for (int j=m; j>=w[i]; j--)
			c[j] = max(c[j], c[j-w[i]]+d[i]);
	cout<<c[m]<<endl;	
}