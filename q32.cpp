#include <bits/stdc++.h>
using namespace std;

bool comp(string s) {
    sort(s.begin(), s.end());
    return s == "123456789";
}

bool check(int x) {
    for(int i = 2; i*i <= x; i++) {
        if(x%i == 0) {
            string s = to_string(x) + to_string(i) + to_string(x/i);
            if(comp(s)) return true;
        }
    }
    return false;
}

void solve() {
    long long ans = 0;
    for(int i = pow(10, 3); i<pow(10, 4); i++) {
        if(check(i)) ans += i;
    }
    cout << ans << endl;
}

int main() {
    solve();

    return 0;
}