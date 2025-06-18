#include <bits/stdc++.h>
using namespace std;

constexpr int N = 2*1000*1000;
vector<bool> sieve(N+1, true);
void create_sieve() {
    sieve[0] = sieve[1] = false;
    for(int i = 2; i*i <= N; i++){
        if(sieve[i]) {
            for(int j = i*i; j <= N; j += i) sieve[j] = false;
        }
    }
}

int family_size(int p, vector<int> mask) {
    int res = 1;
    
    for (int i = 0; i < 10; i++)
        if (mask[i] > 0) {
            int cnt = 1;
            
            for (int j = i + 1; j < 10; j++) 
                if (sieve[p + (j - i) * mask[i]])
                    cnt++;

            res = max(res, cnt);
        }
    
    return res;
}

vector<int> get_valid_masks(int p) {
    int power = 1;
    std::vector<int> valid_masks(10);
    
    for (int i = 0; i < 10; i++)
        valid_masks[i] = 0;
        
    while (p > 0) {
        valid_masks[p % 10] += power;
        power *= 10;
        p /= 10;
    }

    return valid_masks;
}


void solve(int n) {
    for (int i = 10; i < N; i++) {
        if (sieve[i]) {
            if (family_size(i, get_valid_masks(i)) >= n) {
                cout << i << endl;
                break;
            }
        }
    }
}

int main() {
    create_sieve();
    solve(6);
    solve(7);
    solve(8);

    return 0;
}