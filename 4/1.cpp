#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main(){
	int s,n,a,b; cin>>n;
	multiset<int> av,bv;
	while (n--){
		cin>>s;
		cin>>a;
		for (int i=0; i<a; i++){
			int x; cin>>x;
			av.insert(x);
		}
		cin>>b;
		for (int i=0; i<b; i++){
			int x; cin>>x;
			bv.insert(x);
		}
		int result = 0;
		multiset<int>::iterator p = av.begin();
		for (; p!=av.end(); p++)
			result += bv.count(s-*p);
		cout<<result<<endl;
		av.clear();
		bv.clear();
	}

	return 0;
}