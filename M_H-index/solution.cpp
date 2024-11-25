#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    if(T == 0) {
        cout << "0\n";
        return 0;
    }
    while(T--) {
        int m;
        cin >> m;
        vector<int> nums(m);
        for(auto &x : nums) {
            cin >> x;
        }
        sort(nums.begin(), nums.end(), greater<int>());
        int res = 0;
        for (int i = 0; i < nums.size(); i++ ) {
            int cur = min(i + 1, nums[i]);
            res = max(res, cur);
        }
        cout << res << "\n";
    }
}
