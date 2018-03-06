#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int t; cin>>t;
			while (t--){
			int n; cin>>n;
			int wallinitial[n+2][n+2];

			for (int i=0; i<n+2; i++){
				for (int j=0; j<n+2; j++){
					wallinitial[i][j]=0;
				}
			}

			for (int i=1; i<=n; i++){
				for (int j=1; j<=n; j++){
					char x; cin>>x;
					if (x=='w') wallinitial[i][j]=0;
					else if (x=='y') wallinitial[i][j]=1;
				}
			}

			int min = 1000;

			for (int attempt=0; attempt<pow(2,n); attempt++){

				int wall[n+2][n+2];
				int paint[n+2][n+2];

				for (int i=0; i<n+2; i++){
					for (int j=0; j<n+2; j++){
						paint[i][j] = 0;
						wall[i][j] = wallinitial[i][j];
					}
				}
				
		//list all posiible moves for the first row
				int k = attempt; int painttry = n;   
				while (k > 0){
					paint[1][painttry] = k%2;
					k /= 2;
					painttry--;
				}


		//paint the first row as planned
				for (int j=1; j<=n; j++){     
					if (paint[1][j]==1){
						wall[1][j] = (wall[1][j]+1)%2;
						wall[1][j+1] = (wall[1][j+1]+1)%2;
						wall[1][j-1] = (wall[1][j-1]+1)%2;
						wall[2][j] = (wall[2][j]+1)%2;
					}
				}


		//paint row 2 to row n-1 in such a way that the color of wall[i][j] is ensured by the paint of wall[i+1][j]
				for (int i=2; i<=n; i++){       
					for (int j=1; j<=n; j++){
						if (wall[i-1][j] == 0){
							paint[i][j] = 1;
							wall[i][j]= (wall[i][j]+1)%2;
							wall[i-1][j]= (wall[i-1][j]+1)%2;
							wall[i+1][j]= (wall[i+1][j]+1)%2;
							wall[i][j+1]= (wall[i][j+1]+1)%2;
							wall[i][j-1]= (wall[i][j-1]+1)%2;
						}
					}
				}

		//check the last row
				bool success = 1;
				for (int i=1; i<=n; i++){
					if (wall[n][i]==0){
						success = 0;
						break;
					}
				}

				if (success){
					int step = 0;
					for (int i=1; i<=n; i++){
						for (int j=1; j<=n; j++){
							if (paint[i][j]==1){
								step++;
							}
						}
					}
					if (step<min){
						min = step;
					}
				}

			}

			if (min==1000) cout<<"inf"<<endl;
			else cout<<min<<endl;
	}
}