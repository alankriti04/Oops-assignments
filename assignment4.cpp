#include<iostream>
using namespace std;

// Q1 - Rectangle with three constructors
class Rectangle {
    float len, br;
public:
    Rectangle(){
        len = 0; br = 0;
    }
    Rectangle(float a, float b){
        len = a; br = b;
    }
    Rectangle(float a){
        len = a; br = a;
    }
    float area(){
        return len * br;
    }
    ~Rectangle(){
        cout<<"Destructor called for Rectangle (len="<<len<<", br="<<br<<")"<<endl;
    }
};

// Q2 - Array of objects with default argument constructor
class Rect2 {
    float len, br;
public:
    Rect2(float a = 1, float b = 1){
        len = a; br = b;
    }
    float area(){
        return len * br;
    }
    ~Rect2(){
        cout<<"Rect2 destroyed (len="<<len<<" br="<<br<<")"<<endl;
    }
};

// Q3 - Destructor verification class
class DestrCheck {
public:
    DestrCheck(){
        cout<<"Constructor called"<<endl;
    }
    ~DestrCheck(){
        cout<<"Destructor called (no params, no return type, starts with ~)"<<endl;
    }
};

// Q4 - Dynamic memory allocation class
class Sample {
public:
    int val;
    Sample(int v = 0){ val = v; }
    void show(){ cout<<"Object val: "<<val<<endl; }
    ~Sample(){ cout<<"Sample destroyed val="<<val<<endl; }
};

int main(){
    cout<<"=== Q1: Three Constructors ==="<<endl;
    {
        Rectangle r1;
        Rectangle r2(4.0, 6.0);
        Rectangle r3(5.0);
        cout<<"r1 area (no param):   "<<r1.area()<<endl;
        cout<<"r2 area (two params): "<<r2.area()<<endl;
        cout<<"r3 area (one param):  "<<r3.area()<<endl;
    }

    cout<<"\n=== Q2: Array of Objects with Default Args ==="<<endl;
    {
        Rect2 arr[3];
        arr[0] = Rect2();
        arr[1] = Rect2(3.0);
        arr[2] = Rect2(4.0, 7.0);
        for(int i = 0; i < 3; i++)
            cout<<"Rect2["<<i<<"] area: "<<arr[i].area()<<endl;
    }

    cout<<"\n=== Q3: Destructor Verification ==="<<endl;
    {
        DestrCheck obj1;
        DestrCheck obj2;
        cout<<"Both objects created, going out of scope now..."<<endl;
    }

    cout<<"\n=== Q4: Dynamic Memory Allocation ==="<<endl;

    int *ip = new int(42);
    cout<<"Integer: "<<*ip<<endl;
    delete ip;

    float *fp = new float(3.14);
    cout<<"Float: "<<*fp<<endl;
    delete fp;

    int *iarr = new int[5];
    for(int i = 0; i < 5; i++) iarr[i] = (i+1) * 10;
    cout<<"Int array: ";
    for(int i = 0; i < 5; i++) cout<<iarr[i]<<" ";
    cout<<endl;
    delete[] iarr;

    float *farr = new float[3];
    farr[0] = 1.1; farr[1] = 2.2; farr[2] = 3.3;
    cout<<"Float array: ";
    for(int i = 0; i < 3; i++) cout<<farr[i]<<" ";
    cout<<endl;
    delete[] farr;

    Sample *obj = new Sample(99);
    obj->show();
    delete obj;

    Sample *objArr = new Sample[3];
    objArr[0].val = 10;
    objArr[1].val = 20;
    objArr[2].val = 30;
    cout<<"Object array vals: ";
    for(int i = 0; i < 3; i++) cout<<objArr[i].val<<" ";
    cout<<endl;
    delete[] objArr;

    return 0;
}
