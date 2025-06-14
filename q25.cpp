#include <bits/stdc++.h>
using namespace std;

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

void solve(int n) {
    string a = "1";
    string b = "1";
    int i = 1;
    while(a.size() < n){
        string c = string_add(a, b);
        a = b;
        b = c;
        i++;
    }
    cout << i << endl;
}

int main() {
    solve(3);
    solve(1000);

    return 0;
}