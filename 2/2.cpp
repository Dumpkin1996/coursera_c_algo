#include <iostream>
using namespace std;
	
int moves[9];
int minimum = 100;
int result[9];
int a,b,c,d,e,f,g,h,i;

bool end(){
	for (int i=0; i<9; i++)
		if (moves[i]!=3) return false;	
	return true;
}

bool guess(){
	int temp[9];
	temp[0]=a; temp[1]=b; temp[2]=c; temp[3]=d; temp[4]=e; temp[5]=f; temp[6]=g; temp[7]=h; temp[8]=i;
 	for (int i=0; i<moves[0]; i++) {temp[0]++; temp[1]++; temp[3]++; temp[4]++; }
	for (int i=0; i<moves[1]; i++) {temp[0]++; temp[1]++; temp[2]++; }
	for (int i=0; i<moves[2]; i++) {temp[1]++; temp[2]++; temp[4]++; temp[5]++; }
	for (int i=0; i<moves[3]; i++) {temp[0]++; temp[3]++; temp[6]++; }
	for (int i=0; i<moves[4]; i++) {temp[1]++; temp[3]++; temp[4]++; temp[5]++; temp[7]++; }
	for (int i=0; i<moves[5]; i++) {temp[2]++; temp[5]++; temp[8]++; }
	for (int i=0; i<moves[6]; i++) {temp[3]++; temp[4]++; temp[6]++; temp[7]++; }
	for (int i=0; i<moves[7]; i++) {temp[6]++; temp[7]++; temp[8]++; }
	for (int i=0; i<moves[8]; i++) {temp[4]++; temp[5]++; temp[7]++; temp[8]++; }
	for (int i=0; i<9; i++) if (temp[i]%4!=0) return false;
	return true;	
}

int main(){
	cin>>a>>b>>c>>d>>e>>f>>g>>h>>i;
	for (int i=0; i<9; i++) moves[i]=0;
	while (!end()){
		moves[0]++;
		int c = 0;
		while (moves[c]>3){
			moves[c]=0;
			moves[c+1]++;
			c++;
		}
		if (guess()){
			for (int i=0; i<9; i++)
				for (int j=0; j<moves[i]; j++) cout<<i+1<<' ';
			cout<<endl;
			// int count;
			// for (int i=0; i<9; i++) count+=moves[i];
			// if (count<minimum){
			// 	minimum = count;
			// 	for (int i=0; i<9; i++) result[i] = moves[i];
			// }
		}
	}
	// for (int i=0; i<9; i++)
	// 	for (int j=0; j<result[i]; j++) cout<<i+1<<' ';
	// cout<<endl;
}