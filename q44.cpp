#include <bits/stdc++.h>
using namespace std;

bool is_pentagonal(long long n) {
    if (n < 0) {
        cout << "Invalid input: n must be non-negative." << endl;
        return false;
    }
    long long x = (sqrt(24 * n + 1) + 1) / 6;
    return x * (3 * x - 1) / 2 == n;
}

void solve(){
    vector<long long> pent_numbers = {1};
    int n = 2;
    long long ans = LONG_LONG_MAX;
    while(n < 3000){
        long long num = (n*1LL*(3*n-1))/2;
        if(num - pent_numbers.back() > ans) break;
        for(int i = 0; i < pent_numbers.size(); ++i){
            long long sum = num + pent_numbers[i];
            long long diff = num - pent_numbers[i];
            if(is_pentagonal(sum) && is_pentagonal(diff)){
                ans = min(ans, diff);
            }
        }
        n++;
        pent_numbers.push_back(num);
    }
    cout << ans << endl;
}

int main() {
    solve();

    return 0;
}