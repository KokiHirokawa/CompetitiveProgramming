#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
    void print() {
        _print(this);
        cout << endl;
    }

private:
    void _print(ListNode* node) {
        if (node == nullptr) return;

        cout << node->val << endl;
        _print(node->next);
    }
};
 
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        vector<int> v;
        
        ListNode* node = head;

        while (node != nullptr) {
            v.push_back(node->val);
            node = node->next;
        }

        sort(v.begin(), v.end());

        ListNode* result = new ListNode(v[0]);
        ListNode* target = result;

        for (int i = 1; i < v.size(); i++) {
            ListNode* next = new ListNode(v[i]);
            target->next = next;
            target = next;
        }

        return result;
    }
};

class LinkedNode {
public:
    int val;
    LinkedNode* next;
    
    LinkedNode() : val(0), next(nullptr) {}
    LinkedNode(int _val) : val(_val), next(nullptr) {}
    LinkedNode(int _val, LinkedNode* _next) : val(_val), next(_next) {}
};

bool hasCycle(ListNode* head) {
    if (head == nullptr || head->next == nullptr) return false;

    ListNode* slow = head;
    ListNode* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) return true;
    }

    return false;
}

int main() {
    {
        Solution s;

        // [4,2,1,3]

        ListNode* n1 = new ListNode(4);
        ListNode* n2 = new ListNode(2);
        ListNode* n3 = new ListNode(1);
        ListNode* n4 = new ListNode(3);

        n1->next = n2;
        n2->next = n3;
        n3->next = n4;

        n1->print();

        s.sortList(n1)->print();
    }

    {
        Solution s;

        // [-1,5,3,4,0]
        ListNode* n1 = new ListNode(-1);
        ListNode* n2 = new ListNode(5);
        ListNode* n3 = new ListNode(3);
        ListNode* n4 = new ListNode(4);
        ListNode* n5 = new ListNode(0);

        n1->next = n2;
        n2->next = n3;
        n3->next = n4;
        n4->next = n5;

        s.sortList(n1)->print();
    }
    
    {
        Solution* s = new Solution();
    }

    {
        ListNode* n1 = new ListNode(1);
        ListNode* n2 = new ListNode(3);
        ListNode* n3 = new ListNode(2);
        ListNode* n4 = new ListNode(5);

        n1->next = n2;
        n2->next = n3;
        n3->next = n4;
        n4->next = n2;

        cout << hasCycle(n1) << endl;
    }

    {
        vector<char> v = {'H', 'E', 'L', 'L', 'O', 'W', 'O', 'R', 'L', 'D'};

        for_each(v.begin(), v.end(), [](const char c) { cout << c; });
        cout << endl;

        cout << accumulate(v.begin(), v.end(), 0) << endl;
    }

    return 0;
}