#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(n) for (ll i = 0; i < n; ++i)
#define rep2(i, n) for (ll i = 0; i < n; ++i)
#define rep3(i, a, b) for (ll i = a; i < b; ++i)
#define rep4(i, a, b, c) for (ll i = a; i < b; i += c)
#define erep(n) for (ll i = 0; i <= n; ++i)
#define erep2(i, n) for (ll i = 0; i <= n; ++i)
#define erep3(i, a, b) for (ll i = a; i <= b; ++i)
#define erep4(i, a, b, c) for (ll i = a; i <= b; i += c)
#define rrep(i, a, b) for (ll i = a; i > b; --i)
#define rrep2(i, a, b, c) for (ll i = a; i > b; i -= c)
#define errep(i, a, b) for (ll i = a; i >= b; --i)
#define errep2(i, a, b, c) for (ll i = a; i >= b; i -= c)
#define print(a) cout << a << endl;
#define printVec(v) printf("{"); for (const auto& i : v) { std::cout << i << ", "; } printf("}\n");
#define cin(x) cin >> x;
const ll MOD = 1000000007;
const double PI = 3.14159265358979323846264338327950;
inline int newline() { putchar('\n'); return 0; }

typedef pair<int, int> P;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> a(n, vector<int>(n - 1));
    rep2(i, n) {
        rep2(j, n - 1) {
            cin >> a[i][j];
            a[i][j]--;
        }
        // - Note: vectorは先頭より末尾の要素の削除の方が早いため
        reverse(a[i].begin(), a[i].end());
    }

    vector<P> q;
    auto check = [&](int i) {
        if (a[i].size() == 0) return;
        int j = a[i].back();
        if (a[j].size() == 0) return;
        if (a[j].back() == i) {
            P p(i, j);
            // - Note: 後ほど重複削除をするため
            if (p.second < p.first) swap(p.first, p.second);
            q.push_back(p);
        }
    };
    /// 最初の対戦相手のチェック
    rep2(i, n) check(i);

    int day = 0;
    while (q.size() > 0) {
        day++;

        /// 重複削除
        sort(q.begin(), q.end());
        q.erase(unique(q.begin(), q.end()), q.end());

        vector<P> prevQ;
        swap(prevQ, q);

        for (P p : prevQ) {
            int i = p.first, j = p.second;
            a[i].pop_back();
            a[j].pop_back();
        }

        for (P p : prevQ) {
            int i = p.first, j = p.second;
            check(i);
            check(j);
        }
    }

    rep2(i, n) {
        if (a[i].size() != 0) {
            puts("-1");
            return 0;
        }
    }

    cout << day << endl;
    return 0;
}