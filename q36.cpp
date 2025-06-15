#include <bits/stdc++.h>
using namespace std;

bool is_palindrome(const string& s) {
    int n = s.size();
    for(int i = 0; i < n / 2; ++i) {
        if(s[i] != s[n - 1 - i]) {
            return false;
        }
    }
    return true;
}

string dec_to_bin(int n) {
    string res;
    while(n > 0) {
        res += (n % 2) + '0';
        n /= 2;
    }
    reverse(res.begin(), res.end());
    return res;
}

void solve(int n) {
    long long ans = 0;
    for(int i = 1; i < n; ++i) {
        string dec = to_string(i);
        if(is_palindrome(dec)) {
            string bin = dec_to_bin(i);
            if(is_palindrome(bin)) ans += i;
        }
    }
    cout << ans << endl;
}

int main() {
    solve(1000*1000);

    return 0;
}