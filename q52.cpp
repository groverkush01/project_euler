#include <bits/stdc++.h>
using namespace std;

void solve(int n) {
    for(int i = 1; ; i++){
        set<string> st;
        for(int j = 1; j<=n; j++){
            string s = to_string(i*j);
            sort(s.begin(), s.end());
            st.insert(s);
        }
        if(st.size() == 1) {
            cout << i << endl;
            break;
        }
    }
}

int main() {
    solve(2);
    solve(6);

    return 0;
}