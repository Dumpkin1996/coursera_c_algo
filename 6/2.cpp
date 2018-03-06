#include <iostream>
using namespace std;


int p,q;
int already[26][26];
int moves[8][2]={{-1,-2},{1,-2},{-2,-1},{2,-1},{-2,1},{2,1},{-1,2},{1,2}};
int path[1000];



bool legal(int x, int y){
	if (x>=0 && x<p && y>=0 && y<q)
		if (already[x][y]==0)
			return true;
	return false;
}

bool guess(int i, int j, int s){
	already[i][j] = 1;
	if (s+1==p*q) return true;
	for (int k=0; k<8; k++)
		if (legal(i+moves[k][0], j+moves[k][1])){
			path[s]=k;
			if (guess(i+moves[k][0], j+moves[k][1], s+1))
				return true;
		}
	path[s]=-1;
	already[i][j] = 0;
	return false;
}

void print(int sx, int sy){
	int x = sx;
	int y = sy;
	cout<<(char)(y+65)<<x+1;
	int i=0;
	while(path[i]!=-1){
		x += moves[path[i]][0];
		y += moves[path[i]][1];
		cout<<(char)(y+65)<<x+1;
		i++;
	}
	cout<<endl;
}


void start(int k){
	cout<<"Scenario #"<<k+1<<':'<<endl;
	for (int i=0; i<1000; i++)
		path[i]=-1;
	for (int i=0; i<26; i++)
		for (int j=0; j<26; j++)
			already[i][j]=0;
	for (int j=0; j<q; j++)
		for (int i=0; i<p; i++)
			if (guess(i, j, 0)){
				print(i, j);
				return;
			}
	cout<<"impossible"<<endl;	
}

int main(){
	int n; cin>>n;
	int ps[n]; int qs[n];
	
	for (int i=0; i<n; i++)
		cin>>ps[i]>>qs[i];
	
	for (int k=0; k<n; k++){
		p = ps[k]; q = qs[k];
		start(k);
		if (k!=n-1) cout<<endl;
	}

	return 0;
}