#include <bits/stdc++.h>
using namespace std;

bool check(int a, int b, int c) {
    return a < b && c < a && c < b;
}

int main() {
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for(auto &x : nums) {
            cin >> x;
        }
        vector<int> right(n);
        right.back() = n - 1;
        for (int i = right.size() - 2; i >= 0; --i ) {
            right[i] = nums[right[i + 1]] < nums[i] ? right[i + 1] : i;
        }
        bool found = 0;
        int mx = 0;
        for (int i = 1; i < nums.size() - 1; i++ ) {
            if(check(nums[mx], nums[i], nums[right[i + 1]])) {
                cout << "yes " << mx << " " << i << " " << right[i + 1] << "\n";
                found = 1;
                break;
            }
            mx = nums[i] > nums[mx] ? i : mx;
        }
        if(not found) {
            cout << "no\n";
        }
    }
}
