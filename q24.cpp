#include <bits/stdc++.h>
using namespace std;

void solve(string s, int x) {
    x--;
    while(x){
        next_permutation(s.begin(), s.end());
        x--;
    }
    cout << s << endl;
}

int main(){
    solve("0123456789", 1000*1000);

    return 0;
}