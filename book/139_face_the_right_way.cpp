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

int N;
const int MAX_N = 5000;
int dir[MAX_N], isReversed[MAX_N];

// Kを固定したときの最小操作回数
// 解が存在しないときは-1
int calc(int K) {
    memset(isReversed, 0, sizeof(isReversed));

    int res = 0;
    int sum = 0;
    for (int i = 0; i + K <= N; i++) {
        // 区間[i, i + K - 1]に着目
        if ((dir[i] + sum) % 2 != 0) {
            // 先頭の牛が後ろを向いている
            res++;
            isReversed[i] = 1;
        }
        sum += isReversed[i];
        if (i - K + 1 >= 0) {
            sum -= isReversed[i - K + 1];
        }
    }

    // 残りの牛が前を向いているかをチェック
    for (int i = N - K + 1; i < N; i++) {
        if ((dir[i] + sum) % 2 != 0) {
            // 解なし
            return -1;
        }
        if (i - K + 1 >= 0) {
            sum -= isReversed[i - K + 1];
        }
    }

    return res;
}

int main() {
    cin >> N;
    rep2(i, N) {
        char c;
        cin >> c;
        dir[i] = c == 'F' ? 0 : 1;
    }

    int K = 1, M = N;
    erep3(i, 1, N) {
        int m = calc(i);
        if (m >= 0 && M > m) {
            M = m;
            K = i;
        }
    }

    printf("%d %d\n", K, M);
    return 0;
}