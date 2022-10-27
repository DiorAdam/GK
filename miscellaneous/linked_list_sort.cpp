#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* merge(ListNode* h1, ListNode* h2){
        ListNode* ans = new ListNode();
        ListNode* root = ans;
        while (h1 && h2){
            if (h1->val < h2->val){
                root->next = h1;
                root = root->next;
                h1 = h1->next;
            }
            else{
                root->next = h2;
                root = root->next;
                h2 = h2->next;
            }
        }
        if (!h1)
            root->next = h2;
        else
            root->next = h1;
        return ans->next;
    }
    
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode* v1 = head, *v2 = head, *pv1 = head;
        while (v2 && v2->next){
            pv1 = v1;
            v1 = v1->next;
            v2 = v2->next->next;
        }
        pv1->next = NULL;
        return merge(sortList(head), sortList(v1));
    }
};


int main(){
    ListNode root = ListNode(10);
    ListNode* hd = &root;
    for (int i=9; i>0; i--){
        hd->next = new ListNode(i);
        hd = hd->next;
    }

    hd = &root;
    while (hd){
        cout << hd->val << " ";
        hd = hd->next;
    }
    cout << '\n';

    hd = Solution().sortList(&root);

    while (hd){
        cout << hd->val << " ";
        hd = hd->next;
    }
    cout << '\n';
    return 0;
}
