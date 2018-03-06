#include <iostream>
using namespace std;

long long history[40][40][40][40];
int visited[40][40][40][40];
int have[4];
int dial;
int mark = 0;

bool check(int first, int second){
	if (first == 0 || first == 2) return (second == 0 || second == 1);
	if (first == 1 || first == 3) return (second == 2 || second == 3);
	return true;
}

int goal(int x, int y){
	if (x == 0 || x == 1){
		if (y == 0 || y == 2) return 0;
		else if (y == 1 || y == 3) return 1;
	}
	if (x == 2 || x == 3){
		if (y == 0 || y == 2) return 2;
		else if (y == 1 || y == 3) return 3;
	}
	return -1;
}


long long dfs(int have0, int have1, int have2, int have3, int head, int togo){
	long long int result = 0;
	if (visited[have0][have1][have2][have3] == mark)
		return history[have0][have1][have2][have3];
	if (togo == 0) {
		if (check(head, dial)) return 1;
		else return 0;
	}
	else {
		if (have0 && check(head, 0)) result += dfs(have0-1, have1, have2, have3, 0, togo-1);
		if (have1 && check(head, 1)) result += dfs(have0, have1-1, have2, have3, 1, togo-1);
		if (have2 && check(head, 2)) result += dfs(have0, have1, have2-1, have3, 2, togo-1);
		if (have3 && check(head, 3)) result += dfs(have0, have1, have2, have3-1, 3, togo-1);
	}
	visited[have0][have1][have2][have3] = mark;
	history[have0][have1][have2][have3] = result;
	return result;
}

int trans (string s) {
	if (s == "LL") return 0;
	if (s == "LV") return 1;
	if (s == "VL") return 2;
	if (s == "VV") return 3;
	else return -1;
}

int main(){
	int n,k;
	while (cin >> n >> k){
		have[0] = have[1] = have[2] = have[3] = 0;
		string dials;
		cin >> dials;
		dial = trans (dials);
        for (int i=0; i < n; i++) {
        	string s;
        	cin >> s;
        	have[trans(s)] ++;
        }
        mark ++;
        long long result = dfs(have[0], have[1], have[2], have[3], dial, k);
        if (result) cout<<"YES"<<endl<<result<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}