#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) return { i, j };
            }
        }
        return {};
    }
};

int main() {
    Solution s;
    vector<int> v = { 3, 2, 4 };
    vector<int> ans = s.twoSum(v, 6);
    for (int i = 0; i < ans.size(); i++) printf("%d\n", ans[i]);

    return 0;
}