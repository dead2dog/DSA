//stack的底层是 list vector deque（默认）
#include<iostream>
using namespace std;
typedef int T;
#define MAX 5

class Stack{
private:
    T* data;
    int size;
public:
    Stack()
    {
        data = new T[MAX];
        size = 0;
    }
    bool isEmpty()
    {
        return (size == 0);
    }
    void push(T element)
    {
        data[size] = element;
        size++;
    }
    T pop()
    {
        return data[--size];
    }
    T top()
    {
        return data[size-1];
    }
    int getSize()
    {
        return size;
    }
};

int main(){
    Stack s;
    s.push(3);
    s.push(2);
    s.push(1);
    cout<<s.top()<<endl;
    cout<<s.getSize()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.top()<<endl;
    cout<<s.getSize()<<endl;
    return 0;
}
