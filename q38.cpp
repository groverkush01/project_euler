#include <bits/stdc++.h>
using namespace std;

long long pandigital(int n) {
    string s = to_string(n);
    int multiplier = 2;
    while(s.size() < 9) {
        s += to_string(n * multiplier);
        multiplier++;
    }
    if(s.size() > 9) return 0;
    string sorted_s = s;
    sort(sorted_s.begin(), sorted_s.end());
    if(sorted_s == "123456789") return stoll(s);
    return 0;
}

void solve(int n) {
    long long ans = 0;
    for (int i = 1; i<=n; i++){
        long long pan_num = pandigital(i);
        if(pan_num > ans) {
            ans = pan_num;
        }
    }
    cout << ans << endl;
}

int main() {
    solve(100000);
    return 0;
}