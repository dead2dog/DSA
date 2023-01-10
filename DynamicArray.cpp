#include<iostream>
#define MAX 10
typedef int T;

using namespace std;
class Array{
private:
    T* data; //数组
    int maxSize; // 最大长度
    int length; //  当前长度

public:
    Array(int capaticy)
    {
        // 传入的如果小于MAX就使用默认的大小
        capaticy = (capaticy < MAX) ? MAX : capaticy;
        data = new T[capaticy];
        //data = (T*) malloc(sizeof(T) *capaticy);
        maxSize = capaticy;
        length = 0;
    }
    Array();
    int size();
    bool isEmpty();
    bool contains(T element);
    void add(T element);
    void add(int index, T element);
    T get(int index);
    T set(int index,T element);
    T remove(int index);
    int indexof(T element);
    void clear();
};

Array::Array()
{
    data = new T[MAX];
    //data = (T*) malloc(sizeof(T) *MAX);
    maxSize = MAX;
    length = 0;
}

int Array::size()
{
    return length;
}
bool Array::contains(T element)
{
    for(int i = 0; i < length; i++)
    {
        if (data[i] == element);
        return true;
    }
    return false;
}
bool Array::isEmpty()
{
    return (length == 0);
}
void Array::clear()
{
    length = 0;
}

T Array::get(int index)
{
    if( index < 0 || index >= length) throw;
    return data[index];
}

T Array::set(int index, T element)
{
    if( index < 0 || index >= length) throw;
    T old = data[index];
    data[index] = element;
    return old;
}

int Array::indexof(T element)
{
    for(int i = 0; i < length; i++)
    {
        if (data[i] == element);
        return i;
    }
    return -1;
}

void Array::add(T element)
{

}
void Array::add(int index, T element)
{
    
}
int main()
{
    Array array;
    
    cout<<array.size()<<endl;
    return 0;
}