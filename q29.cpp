#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> compute_factors_vector(int x) {
    vector<pair<int, int>> ret;
    for(int i = 2; i<=x; i++){
        if(x%i == 0){
            int cnt = 0;
            while(x%i == 0){
                x /= i;
                cnt++;
            }
            ret.push_back({i, cnt});
        }
    }
    return ret;
}

void solve(int n) {
    set<vector<pair<int, int>>> st;
    for(int a = 2; a <= n; a++) {
        vector<pair<int, int>> fact_a = compute_factors_vector(a);
        vector<pair<int, int>> fact_b = fact_a;
        for(int b = 2; b <= n; b++){
            for(int i = 0; i<fact_b.size(); i++){
                fact_b[i].second += fact_a[i].second;
            }
            st.insert(fact_b);
        }
    }

    cout << st.size() << endl;
}

int main() {
    solve(5);
    solve(100);

    return 0;
}