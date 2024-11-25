#include <bits/stdc++.h>
using namespace std;


int find(vector<int> &father, int a) {
    if(father[a] == a) {
        return a;
    }
    return father[a] = find(father, father[a]);
}

void unite(vector<int> &father, int a, int b) {
    int root_a = find(father, a);
    int root_b = find(father, b);
    if(root_a == root_b) {
        return;
    }
    father[root_a] = root_b;
}

int main() {
    int T;
    cin >> T;
    while(T--) {
        int n, m;
        cin >> n >> m;
        vector<int> father(n);
        iota(father.begin(), father.end(), 0);
        vector<pair<int, int>> edges(m);
        for (auto &e : edges) {
            cin >> e.first >> e.second;
        }

        int res = 0;

        for (int i = m - 1; i >= 0; --i ) {
            int a, b;
            tie(a, b) = edges[i];
            if(find(father, a)== find(father, b)) {
                continue;
            }
            unite(father, a, b);
            if(not(i + 1 <= n - 1)) {
                res++;
            }
        }

        cout << res << endl;
    }
}
