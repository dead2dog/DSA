// https://leetcode.cn/problems/reverse-linked-list/

#include<iostream>
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
    ListNode* reverseList1(ListNode* head) { // 递归1
        if (head == NULL || head->next == NULL) return head;
        ListNode* newHead = reverseList1(head->next);
        head->next->next = head;
        head->next = NULL;
        return newHead;
    }

    ListNode* reverse(ListNode* cur, ListNode* pre)
    {
        if (cur == NULL) return pre;
        ListNode* tmp = cur->next;
        cur->next = pre;
        return reverse(tmp,cur);

    }
    ListNode* reverseList2(ListNode* head) { // 递归2
        return reverse(head,NULL);
    }

    ListNode* reverseList3(ListNode* head) { // 双指针
        ListNode* cur = head;
        ListNode* pre = NULL;
        while (cur!=NULL)
        {
            ListNode* tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }
};