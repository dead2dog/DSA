#include<iostream>
using namespace std;

class MyLinkedList {
public:
    struct LinkedNode
    {
        int val;
        LinkedNode* next;
        LinkedNode(int _val):val(_val),next(nullptr){} 
    };
    
    MyLinkedList() {
        size = 0;
        dummyHead = new LinkedNode(0); // 虚拟头结点
    }
    // index是从0开始算的
    int get(int index) {
        if (index < 0 || index > (size - 1))
        {
            return -1;
        }
        LinkedNode* cur = dummyHead->next;
        while(index--)
        {
            cur = cur->next;
        }
        return cur->val;
    }
    
    void addAtHead(int val) {
        LinkedNode* newNode = new LinkedNode(val);
        newNode->next = dummyHead->next;
        dummyHead->next = newNode;
        size++;
    }
    
    void addAtTail(int val) {
        LinkedNode* newNode = new LinkedNode(val);
        LinkedNode* cur = dummyHead;
        while(cur->next != nullptr)
        {
            cur = cur->next;
        }
        cur->next = newNode;
        size++;
    }
    // 在第index个节点之前插入一个新节点，例如index为0，那么新插入的节点为链表的新头节点。
    // 如果index 等于链表的长度，则说明是新插入的节点为链表的尾结点
    void addAtIndex(int index, int val) {
        if(index > size) return;
        if(index < 0) index = 0;
        LinkedNode* newNode = new LinkedNode(val);
        LinkedNode* cur = dummyHead; // 这样的话找到的就是index前一个
        while(index--)
        {
            cur = cur->next;
        }
        newNode->next = cur->next;
        cur->next = newNode;
        size++;
    }
    
    void deleteAtIndex(int index) {
        if (index >= size || index < 0) {
            return;
        }
        LinkedNode* cur = dummyHead;
        while(index--)
        {
            cur = cur->next;
        }
        LinkedNode* tmp = cur->next;
        cur->next = cur->next->next;
        delete tmp;
        size--;
    }
private:
    int size;
    LinkedNode* dummyHead; // 虚拟头结点，可以统一链表的操作(增删)
};