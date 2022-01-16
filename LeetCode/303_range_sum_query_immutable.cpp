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

class NumArray {
    private:
        ll n;
        vector<ll> vec;

        int query(ll a, ll b, ll k, ll l, ll r) {
            if (r < a || b < l) return 0;

            if (a <= l && r <= b) {
                return vec[k];
            } else {
                int vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
                int vr = query(a, b, k * 2 + 2, (l + r) / 2 + 1, r);
                return vl + vr;
            }
        }

    public:
        NumArray(vector<int>& nums) {
            n = 1;
            while (n < nums.size()) n *= 2;

            vec.resize(n * 2 - 1);
            rep(n * 2 - 1) vec[i] = LLONG_MIN;

            rep(nums.size()) {
                ll num = nums[i];

                ll k = i + n - 1;
                vec[k] = num;

                while (k > 0) {
                    k = (k - 1) / 2;
                    ll right = k * 2 + 2;
                    if (vec[right] == LLONG_MIN) vec[k] = num;
                    else vec[k] = vec[k * 2 + 1] + vec[right];
                }
            }
        }

        int sumRange(int left, int right) {
            return query(left, right, 0, 0, n - 1);
        }
};

int main() {
    vector<int> nums = { -2, 0, 3, -5, 2, -1 };
    NumArray array(nums);

    print(array.sumRange(0, 2));
    print(array.sumRange(2, 5));
    print(array.sumRange(0, 5));

    return 0;
}