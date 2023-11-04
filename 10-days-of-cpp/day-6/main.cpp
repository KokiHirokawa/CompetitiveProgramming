#include <algorithm>
#include <iostream>
#include <string>
#include <queue>

using namespace std;

// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/?envType=study-plan-v2&envId=top-interview-150

// Input: nums = [1,3]
// Output: [3,1]
// Explanation: [1,null,3] and [3,1] are both height-balanced BSTs.

// Input: nums = [-10,-3,0,5,9]
// Output: [0,-3,9,-10,null,5]
// Explanation: [0,-10,5,null,-3,null,9] is also accepted:

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}

    void print() {
        queue<TreeNode*> q;
        q.push(this);

        cout << "[";

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node == nullptr) {
                cout << "null,";
                continue;
            } else {
                cout << node->val << ",";
            }

            if (node->left == nullptr && node->right == nullptr) continue;
            
            q.push(node->left);
            q.push(node->right);
        }

        cout << "]" << endl;
    }
};

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return _sortedArrayToBST(nums, 0, nums.size() - 1);
    }

private:
    TreeNode* _sortedArrayToBST(vector<int>& nums, int left, int right) {
        if (left == right) {
            return new TreeNode(nums[left]);
        }

        int mid = (left + right) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        if (left != mid) root->left = _sortedArrayToBST(nums, left, mid - 1);
        if (right != mid) root->right = _sortedArrayToBST(nums, mid + 1, right);
        return root;
    }
};

// ポインタ渡し
bool twice(int* x) {
    if (x == nullptr) {
        cout << "nullptr" << endl;
        return false;
    }

    cout << *x << endl;
    *x *= 2;
    cout << *x << endl;
    return true;
}

// 参照渡し
bool twice(int& x) {
    cout << &x << endl;
    cout << x << endl;
    x *= 2;
    cout << x << endl;
    return true;
}

void doSomething(const int& x) {
    cout << x << endl;
    cout << &x << endl;

    // &x = nullptr;

    // x *= 2;
}


int main() {
    {
        cout << "--- 1 ---" << endl;

        int x = -121;
        string s = to_string(x);
        
        cout << s << endl;
        
        reverse(s.begin(), s.end());
        cout << (to_string(x) == s) << endl;

        cout << endl;
    }

    {
        cout << "--- 2 ---" << endl;

        Solution s;
        vector<int> v = { -10, -3, 0, 5, 9 };
        TreeNode* root = s.sortedArrayToBST(v);

        root->print();
        cout << endl;
    }

    {
        cout << "--- 3 ---" << endl;

        Solution s;
        vector<int> v = { 1, 3 };
        TreeNode* root = s.sortedArrayToBST(v);

        root->print();
        cout << endl;
    }

    {
        cout << "--- 4 ---" << endl;

        twice(nullptr);
        int x = 16;
        twice(&x);
        cout << x << endl;

        cout << endl;
    }

    {
        cout << "--- 5 ---" << endl;

        // twice(nullptr);
        int x = 16;
        twice(x);
        cout << x << endl;

        cout << endl;
    }

    {
        cout << "--- 7 ---" << endl;

        int x = 16;
        doSomething(x);

        cout << endl;
    }

    return 0;
}