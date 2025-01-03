#include <bits/stdc++.h>
using namespace std;


struct factor {
    int64_t num = 0;
    int64_t contribution = 0;
    factor() = default;
    factor(int64_t x) : num(x), contribution(x) {}
};

int64_t prefix_gcdSum(const vector<factor> &factors, int64_t target) {
    int64_t res = 0;
    for (int64_t i = 0; i < factors.size(); i++) {
        res += (target / factors[i].num) * factors[i].contribution;
    }
    return res;
}

vector<factor> getFactors(int64_t n) {
    vector<factor> factors;
    for (int64_t i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            factors.push_back(i);
            if(n / i != i)  factors.push_back(n / i);
        }
    }
    sort(factors.begin(), factors.end(), [](const factor &a, const factor &b) {
        return a.num < b.num;
    });
    
    for (int64_t i = 0; i < factors.size(); i++) {
        for (int64_t j = 0; j < i; j++) {
            if (factors[i].num % factors[j].num == 0) {
                factors[i].contribution -= factors[j].contribution;
            }
        }
    }

    return factors;
}


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int64_t T;
    cin >> T;
    while(T--) {
        int64_t n, m;
        cin >> n >> m;
        auto factors = getFactors(n);
        int64_t left = 0, right = n;
        
        while(left <= right) {
            int64_t mid = left + (right - left) / 2;
            int64_t sum = prefix_gcdSum(factors, mid);
           // cout << mid << " " << sum << endl;
            if(sum > m) {
                right = mid - 1;
            }
            else if(sum == m) {
                left = mid;
                break;
            }
            else {
                left = mid + 1;
            }
        }
        cout << min(left, n) << endl;
    }
}

