#include <bits/stdc++.h>
using namespace std;

void solve(int n){
	map<string, vector<long long>> mp;
	long long i = 1;
	while(true){
		string num = to_string(i*i*i);
		sort(num.begin(), num.end());
		mp[num].push_back(i*i*i);
		if(mp[num].size() == n){
			cout << mp[num][0] << endl;
			return;
		}
		i++;
	}
}

int main(){
	solve(3);
	solve(5);

	return 0;
}