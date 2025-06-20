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

string string_multiply(string a, string b){
    if(b.size() == 1){
        long long x = stoll(b);
        string res = "0";
        while(x--){
            res = string_add(res, a);
        }
        return res;
    }
    reverse(b.begin(), b.end());
    string res = "0";
    for (char d: b) {
        string xm = string_multiply(a, to_string(d-'0'));
        res = string_add(res, xm);
        a.push_back('0');
    }
    return res;
}


void solve(int n){
	vector<long long> seq = {2, 1, 2};
	while(seq.size() < n) {
		if((seq.size())%3 != 2) seq.push_back(1);
		else seq.push_back(2*((seq.size() + 1)/3));
	}
	int iter = n-1;
	pair<string, string> number = {"1", to_string(seq[iter])};
	while(iter>0){
		iter--;
		pair<string, string> new_num;
		if(iter == 0) {
			number.first = string_add(number.first, string_multiply(number.second, to_string(seq[iter])));
		} else {
			new_num.first = number.second;
			new_num.second = string_add(number.first, string_multiply(number.second, to_string(seq[iter])));
			number = new_num;
		}
	}
	int ans = 0;
	for(auto x : number.first) ans += (x - '0');
	cout << ans << endl;
}

int main(){
	solve(10);
	solve(100);

	return 0;
}