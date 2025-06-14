#include <bits/stdc++.h>
using namespace std;

bool check(int num, int den) {
    if (den % 10 != 0 && den % 10 == num % 10) { 
        // 2nd digit of den equal to 2nd digit of num
        if (num * (den / 10) == den * (num / 10)) return true;
    } else if (den % 10 == (num / 10) % 10) { 
        // 2nd digit of den equal to 1st digit of num
        if (num * (den / 10) == den * (num % 10)) return true;
    } else if ((den / 10) % 10 == num % 10) { 
        // 1st digit of den equal to 2nd digit of num
        if ((num * (den % 10) == den * (num / 10))) return true;
    } else if ((den / 10) % 10 == (num / 10) % 10) { 
        //1st digit of den equal to 1st digit of num
        if (num * (den % 10) == den * (num % 10)) return true;
    }
    return false;
}

void solve() {
    vector<pair<int, int>> ans;
    for(int i = 10; i<100; i++) {
        for (int j = i+1; j<100; j++) {
            if(check(i, j)) ans.push_back({i, j});
        }
    }
    int num = 1;
    int den = 1;
    for(auto x : ans) {
        num *= x.first;
        den *= x.second;
    }
    int hcf = __gcd(num, den);
    cout << den/hcf << endl;
}

int main() {
    solve();

    return 0;
}