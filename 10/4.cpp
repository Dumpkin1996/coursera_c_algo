#include <iostream>
#include <cmath>
using namespace std;

int main(){
	int c; cin>>c;
	while(c--){
		int x; cin>>x;
		long result = 1<<30 ;
		for (int i=1; i<=(int)(cbrt(x)); i++)
			for (int j=i; j<=min(x, x/i); j++)
				if (x%(i*j)==0){
					int k = x/(i*j);
					long temp = 2*(i*j + i*k + j*k);
					if (temp<result) result = temp;
				}
		cout<<result<<endl;
	}
	return 0;
}