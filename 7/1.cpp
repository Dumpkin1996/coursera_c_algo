#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main(){
	int target,num;
	while (true){
		cin>>target>>num;
		
		if (target==0&&num==0) break;
		
		else{
			int l = 1;
			while (pow(10, l)<=num) l++;

			int index = -1;
			int finalresult = 0;
			int finalresult2 = 0;
			
			for (int i=0; i<pow(2,l-1); i++){

				int copynum = num;
				int copyi = i;
				int scheme[l-1];
				vector<int> parts;
				for (int j=l-2; j>=0; j--){
					scheme[j] = copyi%2;
					if(copyi) copyi=copyi/2;
				}

				// cout<<"scheme = [ ";
				// for (int j=0; j<l-1; j++)
				// 	cout<<scheme[j]<<' ';
				// cout<<"]"<<endl;

				for (int j=0; j<l; j++)
					if(scheme[j]){
						int div = pow(10, l-1-j);
						parts.push_back(copynum/div);
						copynum = copynum%div;
					}
				if (copynum) parts.push_back(copynum);

				// cout<<"parts = [ ";
				// for (int k=0; k<parts.size(); k++)
				// 	cout<<parts[k]<<' ';
				// cout<<']'<<endl;
				
				int result = 0;
				for (int k=0; k<parts.size(); k++)
					result += parts[k];

				if(result<=target)
					if (result>=finalresult){
						if (result == finalresult)
							finalresult2 = result;
						else{
							finalresult = result;
							index = i;
						}
					}
			}

			if (index != -1){
				if (finalresult == finalresult2)
					cout<<"rejected"<<endl;
				else{
					int copyindex = index;
					int finalscheme[l-1];
					vector<int> finalparts;
					
					for (int j=l-2; j>=0; j--){
						finalscheme[j] = copyindex%2;
						if(copyindex) copyindex=copyindex/2;
					}
					
					for (int j=0; j<l; j++)
						if(finalscheme[j]){
							int div = pow(10, l-1-j);
							finalparts.push_back(num/div);
							num = num%div;
						}
					if (num) finalparts.push_back(num);

					cout<<finalresult<<' ';
					for (int k=0; k<finalparts.size()-1; k++)
						cout<<finalparts[k]<<' ';
					cout<<finalparts[finalparts.size()-1]<<endl;
				}
				
			}
			else
				cout<<"error"<<endl;
		}
	}
	return 0;
}
