#include <bits/stdc++.h>
using namespace std;

string string_add(string a, string b){
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    long long n = a.size();
    long long m = b.size();
    for(int i = n; i<max(n, m); i++){
        a.push_back('0');
    }
    for(int i = m; i<max(n, m); i++){
        b.push_back('0');
    }
    string res = "";
    bool carry = false;
    for(int i=0; i<max(m, n); i++){
        int sum = ((a[i] - '0') + (b[i] - '0'));
        if(carry) {sum++; carry = false;}
        if(sum > 9){
            carry = true;
            sum -= 10;
        }
        res.push_back(sum+'0');
    }
    if(carry) res.push_back('1');
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    reverse(res.begin(), res.end());
    return res;
}

// 1 + 1/(1+num/den)
// 1 + den/(num+den)

void solve(int n){
	pair<string, string> a = {"3", "2"};
	int iter = 1;
	int cnt = 0;
	while(iter < n){
		pair<string, string> new_a;
		new_a.first = a.second;
		new_a.second = string_add(a.first, a.second);
		a.first = string_add(new_a.first, new_a.second);
		a.second = new_a.second;
		if(a.first.size() > a.second.size()) cnt++;
		iter++;
	}
	cout << cnt << endl;
}

int main(){
	solve(1000);

	return 0;
}