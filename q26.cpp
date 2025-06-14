#include <bits/stdc++.h>
using namespace std;

int calc_cycle(int x){
    map<int, int> mp;
    int i = 0;
    int num = 1;
    while(mp.find(num) == mp.end()) {
        mp[num] = i;
        i++;
        num *= 10;
        num %= x;
    }
    return i - mp[num];
}

void solve(int n) {
    int ans = 0;
    int mx = 0;
    for(int i = 1; i<=n; i++){
        int curr = calc_cycle(i);
        if(curr > mx) {
            mx = curr;
            ans = i;
        }
    }
    cout << ans << endl;
}

int main() {
    solve(10);
    solve(1000);

    return 0;
}