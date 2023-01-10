#include<iostream>
#include<string>
using namespace std;
#define MAX 5
typedef string T;

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
    ~Array()
    {
        delete []data;
        length = 0;
        maxSize = 0;
        cout<<"调用析构函数"<<endl;
    }
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
        if (data[i] == element) return i;
    }
    throw;
}

void Array::add(T element)
{
    if(length == maxSize)
    {
        // 扩容
        maxSize = maxSize * 2;
        T *newData = new T[maxSize];
        for (int i = 0; i < length; i++)
        {
            newData[i] = data[i];
        }
        delete []data;
        data = newData;
    }
    data[length] = element;
    length++;
}
void Array::add(int index, T element)
{
    if( index < 0 || index >= length) throw;
    if(length == maxSize)
    {
        // 扩容
        int maxSize = maxSize * 2;
        T *newData = new T[maxSize];
        for (int i = 0; i < length; i++)
        {
            newData[i] = data[i];
        }
        delete []data;
        data = newData;
    }
    // 第index位全部后移
    for(int i = length; i >= index; i--)
    {
        data[i + 1] = data[i]; 
    }
    data[index] = element;
    length++;
}
T Array::remove(int index)
{
    if( index < 0 || index >= length) throw;
    T element = data[index];
    for(int i = index; i < length-1;)
    {
        data[i] = data[++i];
    }
    length--;
    return element;
}
int main()
{
    Array array;
    array.add("j1");
    array.add("j2");
    array.add("j3");
    array.add("j4");
    array.add("j5");
    cout<<array.size()<<endl;
    cout<<array.get(4)<<endl;
    array.remove(4);
    cout<<array.size()<<endl;   
    cout<<array.get(3)<<endl;
    cout<<array.indexof("j5")<<endl;
    return 0;
}