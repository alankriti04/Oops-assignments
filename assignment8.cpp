#include<iostream>
using namespace std;

// ===== FUNCTION TEMPLATES =====

// FT Q1 - Swap two variables of any data type
template<typename T>
void swapTwo(T &a, T &b){
    T temp = a;
    a = b;
    b = temp;
}

// FT Q2 - Find minimum element in array
template<typename T>
T findMin(T arr[], int n){
    T mn = arr[0];
    for(int i = 1; i < n; i++)
        if(arr[i] < mn) mn = arr[i];
    return mn;
}

// FT Q3 - Bubble sort
template<typename T>
void bubbleSort(T arr[], int n){
    for(int i = 0; i < n-1; i++)
        for(int j = 0; j < n-i-1; j++)
            if(arr[j] > arr[j+1]) swapTwo(arr[j], arr[j+1]);
}

// FT Q4 - Linear search
template<typename T>
int linearSearch(T arr[], int n, T key){
    for(int i = 0; i < n; i++)
        if(arr[i] == key) return i;
    return -1;
}

// FT Q5 - Overloaded process() templates
template<typename T>
void process(T a){
    cout<<"Single param: "<<a<<endl;
}
template<typename T>
void process(T a, T b){
    cout<<"Two same type params: "<<a<<" and "<<b<<endl;
}
template<typename T1, typename T2>
void process(T1 a, T2 b){
    cout<<"Two different type params: "<<a<<" and "<<b<<endl;
}

// ===== CLASS TEMPLATES =====

// CT Q1 - Stack
template<typename T>
class Stack {
    T arr[50];
    int top;
public:
    Stack(){ top = -1; }
    void push(T val){
        if(top < 49){ arr[++top] = val; cout<<"Pushed: "<<val<<endl; }
        else cout<<"Stack full"<<endl;
    }
    void pop(){
        if(top >= 0){ cout<<"Popped: "<<arr[top--]<<endl; }
        else cout<<"Stack empty"<<endl;
    }
    void show(){
        cout<<"Stack: ";
        for(int i = 0; i <= top; i++) cout<<arr[i]<<" ";
        cout<<endl;
    }
};

// CT Q2 - Queue
template<typename T>
class Queue {
    T arr[50];
    int front, back;
public:
    Queue(){ front = 0; back = 0; }
    void enqueue(T val){
        if(back < 50){ arr[back++] = val; cout<<"Enqueued: "<<val<<endl; }
        else cout<<"Queue full"<<endl;
    }
    void dequeue(){
        if(front < back){ cout<<"Dequeued: "<<arr[front++]<<endl; }
        else cout<<"Queue empty"<<endl;
    }
    void show(){
        cout<<"Queue: ";
        for(int i = front; i < back; i++) cout<<arr[i]<<" ";
        cout<<endl;
    }
};

// CT Q3 - Pair
template<typename T1, typename T2>
class Pair {
    T1 first;
    T2 second;
public:
    Pair(T1 a, T2 b){ first = a; second = b; }
    void show(){ cout<<"Pair: ("<<first<<", "<<second<<")"<<endl; }
};

// CT Q4 - Basic arithmetic operations
template<typename T>
class Arithmetic {
    T a, b;
public:
    Arithmetic(T x, T y){ a = x; b = y; }
    void add(){ cout<<"Add: "<<a+b<<endl; }
    void sub(){ cout<<"Sub: "<<a-b<<endl; }
    void mul(){ cout<<"Mul: "<<a*b<<endl; }
    void div(){
        if(b != 0) cout<<"Div: "<<a/b<<endl;
        else cout<<"Cannot divide by zero"<<endl;
    }
};

// CT Q5 - Array input and display
template<typename T>
class MyArray {
    T arr[20];
    int n;
public:
    MyArray(int size){ n = size; }
    void input(){
        cout<<"Enter "<<n<<" elements: ";
        for(int i = 0; i < n; i++) cin>>arr[i];
    }
    void display(){
        cout<<"Array: ";
        for(int i = 0; i < n; i++) cout<<arr[i]<<" ";
        cout<<endl;
    }
};

int main(){
    cout<<"=== FT Q1: Swap ==="<<endl;
    int p = 5, q = 10;
    cout<<"Before: p="<<p<<" q="<<q<<endl;
    swapTwo(p, q);
    cout<<"After:  p="<<p<<" q="<<q<<endl;
    float x = 1.5, y = 2.5;
    swapTwo(x, y);
    cout<<"Float swap: x="<<x<<" y="<<y<<endl;

    cout<<"\n=== FT Q2: Find Min ==="<<endl;
    int iarr[] = {5, 2, 8, 1, 9};
    cout<<"Min (int): "<<findMin(iarr, 5)<<endl;
    float farr[] = {3.5, 1.2, 7.8};
    cout<<"Min (float): "<<findMin(farr, 3)<<endl;

    cout<<"\n=== FT Q3: Bubble Sort ==="<<endl;
    int sarr[] = {64, 25, 12, 22, 11};
    bubbleSort(sarr, 5);
    cout<<"Sorted: ";
    for(int i = 0; i < 5; i++) cout<<sarr[i]<<" ";
    cout<<endl;

    cout<<"\n=== FT Q4: Linear Search ==="<<endl;
    int larr[] = {10, 20, 30, 40, 50};
    int idx = linearSearch(larr, 5, 30);
    cout<<"Search 30: index="<<idx<<endl;
    idx = linearSearch(larr, 5, 99);
    cout<<"Search 99: index="<<idx<<" (not found)"<<endl;

    cout<<"\n=== FT Q5: process() overloads ==="<<endl;
    process(42);
    process(3, 7);
    process(10, 3.14);

    cout<<"\n=== CT Q1: Stack ==="<<endl;
    Stack<int> stk;
    stk.push(10); stk.push(20); stk.push(30);
    stk.show();
    stk.pop(); stk.show();

    cout<<"\n=== CT Q2: Queue ==="<<endl;
    Queue<int> que;
    que.enqueue(1); que.enqueue(2); que.enqueue(3);
    que.show();
    que.dequeue(); que.show();

    cout<<"\n=== CT Q3: Pair ==="<<endl;
    Pair<int, float> pr1(1, 3.14);
    Pair<string, int> pr2(string("Age"), 21);
    pr1.show(); pr2.show();

    cout<<"\n=== CT Q4: Arithmetic ==="<<endl;
    Arithmetic<int> ar(10, 3);
    ar.add(); ar.sub(); ar.mul(); ar.div();

    cout<<"\n=== CT Q5: Array input/display ==="<<endl;
    MyArray<int> ma(5);
    ma.input();
    ma.display();

    return 0;
}
