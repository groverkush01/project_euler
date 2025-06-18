#include <bits/stdc++.h>
using namespace std;

bool is_palindrome(string &s) {
    int n = s.size();
    for(int i =0; i<n/2; i++){
        if(s[i] != s[n-i-1]) return false;
    }
    return true;
}

string string_add(string &a, string &b){
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

bool check_lychrel(string s, int iter) {
    for(int i = 1; i<= iter; i++){
        string s2 = s;
        reverse(s2.begin(), s2.end());
        s = string_add(s, s2);
        if(is_palindrome(s)) return false;
    }
    return true;
} 

void solve(int n, int iter) {
    int ans = 0;
    for(int i = 1; i < 10000; i++){
        if(check_lychrel(to_string(i), iter)) ans++;
    }
    cout << ans << endl;
}

int main() {
    solve(10000, 50);

    return 0;
}