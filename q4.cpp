#include <bits/stdc++.h>
using namespace std;

bool check_palindrome(int n){
    string s = to_string(n);
    int len = s.size();
    for(int i = 0; i<len/2; i++){
        if(s[i] != s[len-i-1]) return false;
    }
    return true;
}

int solve(int dig){
    int limit = 1;
    for(int i = 0; i<dig; i++) limit *= 10;
    int ans = -1;
    for(int i = limit/10; i < limit; i++){
        for(int j = limit/10; j<limit; j++){
            if(check_palindrome(i*j)) ans = max(ans, i*j);
        }
    }

    return ans;
}

int main(){
    cout << solve(2) << endl;
    cout << solve(3) << endl;

    return 0;
}