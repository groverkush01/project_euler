#include <bits/stdc++.h>
using namespace std;

vector<int> denominations = {1, 2, 5, 10, 20, 50, 100, 200};

void solve(int n){
    vector<int> dp(n+1);
    dp[0] = 1;
    for(int i = 0; i<denominations.size(); i++){
        for(int j = denominations[i]; j <= n; j++){
            dp[j] += dp[j-denominations[i]];
        }
    }
    cout << dp[n] << endl;
}

int main() {
    solve(200);

    return 0;
}