#include<bits/stdc++.h>
using namespace std;

struct state {
    int len{}, link{};
    array<int, 26> next{};
};

struct SAM {
    int sz{}, last{};
    vector<state> st;
    SAM(int maxlen) : st(maxlen * 2) {
        st[0].len = 0;
        st[0].link = -1;
        sz++;
        last = 0;
    }

    void insert(char c) {
        insert_impl(c - 'a');
    }

    void insert_impl(char c) {
        int cur = sz++;
        st[cur].len = st[last].len + 1;
        int p = last;
        while(p != -1 && !st[p].next[c]) {
            st[p].next[c] = cur;
            p = st[p].link;
        }
        if(p == -1) {
            st[cur].link = 0;
        }
        else {
            int q = st[p].next[c];
            if(st[p].len + 1 == st[q].len) {
                st[cur].link = q;
            }
            else {
                int clone_num = sz++;
                auto &clone = st[clone_num];
                auto &ps = st[p];
                auto &qs = st[q];
                clone.len = ps.len + 1;
                clone.next = qs.next;
                clone.link = qs.link;
                while(p != -1 && st[p].next[c] == q) {
                    st[p].next[c] = clone_num;
                    p = st[p].link;
                }
                st[q].link = st[cur].link = clone_num;
            }
        }
        last = cur;
    }

};

int main() {
    int T;
    cin >> T;
    while(T--) {
        string s;
        cin >> s;
        reverse(s.begin(), s.end());
        SAM sam(s.size());
        for(auto c : s) {
            sam.insert(c);
        }

        cout << sam.sz << endl;
    }
}
