#include <bits/stdc++.h>
using namespace std;


int num_triangles[1500000 + 1];
void solve(int maxn){
	for (int m = 2; m * m <= maxn / 2; m++) {
        for (int n = 1; n < m; n++) {
            if ((m + n) % 2 == 1 && __gcd(m, n) == 1) {
				int a = m * m - n * n;
                int b = 2 * m * n;
                int c = m * m + n * n;
                int L = a + b + c;
                for (int k = 1; k * L <= maxn; k++) {
					num_triangles[k * L]++;
                }
            }
        }
    }
    int count = 0;
    for (int i = 1; i <= maxn; i++) {
		if (num_triangles[i] == 1) {
			count++;
        }
    }
    cout << count << endl;
}

int main(){
	solve(1500000);
	return 0;
}