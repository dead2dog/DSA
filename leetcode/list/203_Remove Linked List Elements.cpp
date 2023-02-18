// https://leetcode.cn/problems/remove-linked-list-elements/
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
    ListNode* removeElements1(ListNode* head, int val) {
        // 删除头结点
        while (head != NULL && head->val == val) { // 注意这里不是if
            ListNode* tmp = head;
            head = head->next;
            delete tmp;
        }

        // 删除非头结点
        ListNode* cur = head;
        while (cur != NULL && cur->next!= NULL) {
            if (cur->next->val == val) {
                ListNode* tmp = cur->next;
                cur->next = cur->next->next;
                delete tmp;
            } else {
                cur = cur->next;
            }
        }
        return head;
    }

    ListNode* removeElements2(ListNode* head, int val) {
        // 声明一个虚拟头结点
        ListNode* dummyHead = new ListNode;
        dummyHead->next = head;
        ListNode* cur = dummyHead;
        while(cur->next !=NULL)
        {
            if ( cur->next->val == val)
            {
                ListNode* tmp = cur->next;
                cur->next = cur->next->next;
                delete tmp;
            }else{
                cur = cur->next;
            }
        }
        //删除虚拟头结点
        head = dummyHead->next;
        delete dummyHead;
        return head;
    }
};