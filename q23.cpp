#include <bits/stdc++.h>
using namespace std;

vector<int> abundant_numbers;
map<int, int> mp;

int calc_d(int x) {
    int ans = 0;
    for(int i = 1; i*i<=x; i++){
        if(x%i == 0) {
            ans += i;
            ans += x/i;
        }
        if(i*i == x) {
            ans -= sqrt(x);
        }
    }
    ans -= x;
    return ans;
}

void calc_abundant_numbers(int n) {
    abundant_numbers.clear();
    for(int i = 12; i <= n; i++){
        if(calc_d(i) > i) {
            abundant_numbers.push_back(i);
            mp[i] = 1;
        }
    }
}

void solve(int n){
    calc_abundant_numbers(n);
    long long ans = (n*1LL*(n+1))/2;

    for(int i = 1; i<=n; i++){
        for(auto x : abundant_numbers){
            if(mp.find(i - x) != mp.end()) {
                ans -= i;
                break;
            }
        }
    }
    cout << ans << endl;
}

int main() {
    solve(24);
    solve(28123);

    return 0;
}