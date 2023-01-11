// queue的底层实现是 deque双端队列，头部尾部都可以出队入队，也可以指定用list实现

#include<iostream>
using namespace std;
typedef int T;

class Queue{
public:
    struct Node
    {
        T data;
        Node* pre;
        Node* next;
        Node(T _data):data(_data),pre(nullptr),next(nullptr){}
    };
    
    Queue()
    {
        size = 0;
        head = new Node(0);
    }

    int getSize()
    {
        return size;
        head = new Node(0); //虚拟头结点
    }

    // 从队尾入队
    void enQueue(T element)
    {
        Node* newNode = new Node(element);
        Node* cur = head;
        while(cur->next != nullptr)
        {
            cur = cur->next;
        }
        newNode->pre = cur;
        cur->next = newNode;
        size++;
    }
    // 先进先出，队头出头
    T deQueue()
    {
        Node* tmp = head->next;
        T tmpData = tmp->data;
        head->next = head->next->next;
        head->next->pre = head;
        size--;
        delete tmp;
        return tmpData;
    }


private:
    int size;
    Node* head;
};

int main()
{
    Queue q;
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);
    cout<<q.getSize()<<endl;
    cout<<q.deQueue()<<endl;
    cout<<q.deQueue()<<endl;
    cout<<q.getSize()<<endl;
    return 0;
}