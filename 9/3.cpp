#include <iostream>
using namespace std;

void plan(int n, int h){
	int f[25]={},d[25]={},t[24]={},stay[25][25]={};
	for (int i=0; i<n; i++)
		cin>>f[i];
	for (int i=0; i<n; i++)
		cin>>d[i];
	for (int i=0; i<n-1; i++)
		cin>>t[i];
	// for (int i=0; i<25; i++)
	// 	for (int j=0; j<25; j++)
	// 		stay[i][j]=0;
	int max = 0;
	int maxend = 0;
	for (int end=0; end<n; end++){
		int temp=0;
		int intervals = h*12;
		for (int i=0; i<end; i++)
			intervals -= t[i];
		for (int k=0; k<intervals; k++){
			int index = -1;
			int maxplus = -1;
			for (int i=0; i<=end; i++){
				int tmp = f[i]-stay[end][i]*d[i];
				if (tmp<0) tmp=0;
				if (tmp>maxplus){
					index = i;
					maxplus = tmp;
				}
			}
			temp += maxplus;
			stay[end][index]++;
		}
		if (temp>max){
			max = temp;
			maxend = end;
		}
	}
	for (int i=0; i<n-1; i++)
		cout<<5*stay[maxend][i]<<", ";
	cout<<5*stay[maxend][n-1]<<endl;
	cout<<"Number of fish expected: "<<max<<endl;
	cout<<endl;
}

int main(){
	while (true){
		int n,h; cin>>n;
		if (n==0) break;
		else{
			cin>>h;
			plan(n,h);
		}
	}
	return 0;
}