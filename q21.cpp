#include <bits/stdc++.h>
using namespace std;

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
    return mp[x] = ans;
}

void solve(int n){
    long long ans = 0;

    for(int i = 1; i<=n; i++){
        calc_d(i);
    }

    for(int i = 1; i<=n; i++){
        if(mp[mp[i]] == i && mp[i] != i) {
            ans += i;
        }
    }
    cout << ans << endl;
}

int main(){
    solve(10000);
    
    return 0;
}