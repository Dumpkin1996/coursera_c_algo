#include <iostream>
using namespace std;

int n,k;
char board[8][8];
char temp[8][8];

int f(int x, int d){
	if (d==0){
		// cout<<"success!"<<endl;
		// for (int i=0; i<n; i++){
		// 	for (int j=0; j<n; j++)
		// 		cout<<board[i][j];
		// 	cout<<endl;
		// }
		return 1;
	}
	else if (x>n) return 0;
	int result = 0;
	for (int i=0; i<n; i++){
		if (board[x][i]=='#'){
			bool can = 1;
			for (int j=0; j<n; j++)
				if (j!=i && board[x][j]=='!'){
					can = 0;
					break;
				}
			if (can)
				for (int j=0; j<n; j++)
					if (j!=x && board[j][i]=='!'){
						can = 0;
						break;
					}
			if (can){
				board[x][i]='!';
				result += f(x+1, d-1);
				board[x][i]='#';
			}
		}
	}
	result += f(x+1, d);
	return result;
}

int main(){
	while(true){
		for (int i=0; i<8; i++)
			for (int j=0; j<8; j++){
				board[i][j] = '?';
				temp[i][j] = '?';
			}
		cin>>n>>k;
		if (n==-1&&k==-1) break;
		for (int i=0; i<n; i++)
			for (int j=0; j<n; j++)
				cin>>board[i][j];
		cout<<f(0, k)<<endl;
	}
}