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

string BinExp(string a, int b){
    string res = "1";
    while(b){
        if(b&1){
            res = string_multiply(res, a);
        }
        a = string_multiply(a, a);
        b >>= 1;
    }
    return res;
}

void solve(int n){
    string ans = BinExp("2", n);
    int ret = 0;
    for(auto x : ans) ret += (x-'0');
    cout << ret << endl;
}

int main(){
    solve(15);
    solve(1000);

    return 0;
}