#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int n,c;
set<long> stalls;

bool check(long a){
	long mark  = *stalls.begin();
	int rest = c-1;
	while (rest--){
		if (stalls.lower_bound(mark+a)!=stalls.end())
			mark = *stalls.lower_bound(mark+a);
		else
			return false;
	}
	return true;
}


int main(){
	cin>>n>>c;
	for (int i=0; i<n; i++){
		long x; cin>>x;
		stalls.insert(x);
	}
	long right = (*stalls.rbegin() - *stalls.begin())/(c-1);
	long left = 0;
	while (left<right-1){
		long mid = (left+right)/2;
		if (!check(mid))
			right=mid;
		else if (check(mid))
			left=mid;
	}
	cout<<left<<endl;
	return 0;
}