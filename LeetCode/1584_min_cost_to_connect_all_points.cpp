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

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        auto size = points.size();
        vector<vector<int>> cost(size, vector<int>(size));

        rep2(i, size) {
            rep2(j, size) {
                if (i == j) {
                    cost[i][j] = 0;
                } else {
                    vector<int> first = points[i], second = points[j];
                    cost[i][j] = abs(first[0] - second[0]) + abs(first[1] - second[1]);
                }
            }
        }

        int result = 0;
        vector<bool> used(size, false);
        vector<int> mincost(size, INT_MAX);

        mincost[0] = 0;

        while (true) {
            int v = -1;

            rep(size) {
                if (!used[i] && (v == -1 || mincost[i] < mincost[v])) v = i;
            }

            if (v == -1) break;
            used[v] = true;
            result += mincost[v];

            rep(size) {
                mincost[i] = min(mincost[i], cost[v][i]);
            }
        }

        return result;
    }
};

int main() {
    vector<vector<int>> input = {{0, 0}, {2, 2}, {3, 10}, {5, 2}, {7, 0}};

    Solution s;
    cout << s.minCostConnectPoints(input) << endl;

    return 0;
}