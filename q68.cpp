#include <bits/stdc++.h>
using namespace std;


string vec2str(const vector<int>& v) {
    string ret;
    
    vector<vector<int>> groups {
        {v[0], v[1], v[2]}, 
        {v[3], v[2], v[4]}, 
        {v[5], v[4], v[6]}, 
        {v[7], v[6], v[8]}, 
        {v[9], v[8], v[1]}, 
    };
    
    int start_index = min_element(
        groups.begin(), groups.end(),
        [](const auto& a, const auto& b) { return a[0] < b[0]; }
    ) - groups.begin();
    
    for (int i = 0; i < 5; i++) {
        for (int n : groups[(i + start_index) % 5]) ret += to_string(n);
    }
        
    return ret;
}

void solve() {
    vector<int> nums {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<string> strs;
    
    do {
        auto sum = nums[0] + nums[1] + nums[2];
        if (
            (nums[3] + nums[2] + nums[4] == sum) &&
            (nums[5] + nums[4] + nums[6] == sum) &&
            (nums[7] + nums[6] + nums[8] == sum) &&
            (nums[9] + nums[8] + nums[1] == sum)
        ) strs.push_back(vec2str(nums));
    } while (next_permutation(nums.begin(), nums.end()));
    
    sort(strs.begin(), strs.end());
    
    cout << strs.back() << endl;
}

int main(){
	solve();
	return 0;
}