#include <iostream>
#include <string>
#include <set>
#include <vector>
using namespace std;
		
vector<string> v;

class Mycompare{
public:
	bool operator()(string x, string y){
		if (x.find('.')!=string::npos) x=x.substr(0, x.find('.'));
		if (y.find('.')!=string::npos) y=y.substr(0, y.find('.'));
		int l = min(x.length(), y.length());
		for (int i=0; i<l; i++){
			if (tolower(x[i])<tolower(y[i])) return true;
			else if (tolower(x[i])>tolower(y[i])) return false;
		}
		return x.length()<y.length();
	}
};

template <class T>
void Print(T first, T last, int d){
	for( ; first != last ; ++first){
		for(int i=0; i<d; i++) cout<<"|     ";
		cout<<*first<<endl;;
	}
}

void display(string s, int d){
	for(int i=0; i<d; i++) cout<<"|     ";
	cout<<s<<endl;
	multiset<string, Mycompare> files;
	while (true){
		string x = v.front();
		v.erase(v.begin());
		if (x=="]"||x=="*") break;
		if (x[0]=='f') files.insert(x);
		if (x[0]=='d') display(x, d+1);
	}
	Print(files.begin(), files.end(), d);
}


int main(){
	int x = 0;
	int k = 1;
	string c;
	while (true){
			cin>>c;
			if(c=="#") break;
			else v.push_back(c);
	}
	while (true){
		cout<<"DATA SET "<<k++<<":"<<endl;
		display(string("ROOT"), 0);
		if (v.empty()) break;
		cout<<endl;
	}
	return 0;
}