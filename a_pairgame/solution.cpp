#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        vector<int> nums(2 * n);
        for (auto &x : nums) {
            cin >> x;
        }

        int removed = 0;
        int res = 0;

        while(removed < 2 * n) {
            vector<int> first(n + 1, -1);
            vector<int> ser(2 * n);
            int cur = 0;
            int mn = INT_MAX;

            int left = 0;
            int right = 0;

            for(int i = 0; i < nums.size(); i++ ) {
                if(nums[i] == -1) {
                    continue;
                }
                ser[i] = cur;
                cur++;

                if(first[nums[i]] == -1) {
                    first[nums[i]] = i;
                }
                else {
                    //cout << nums[i] << " <> " << first[nums[i]] << endl;
                    if(ser[i] - ser[first[nums[i]]] < mn) {
                        mn = ser[i] - ser[first[nums[i]]];
                        right = i;
                        left = first[nums[i]];
                    }
                }
            }

            res += mn;

            nums[right] = -1;
            nums[left] = -1;
            removed += 2;
        }
        cout << res << "\n";
    }
}
