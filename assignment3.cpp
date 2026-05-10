#include<iostream>
using namespace std;

// Q1 - Pointer to object and this pointer
class Box {
    int len;
public:
    Box(int l){ len = l; }
    void show(){
        cout<<"Length (dot): "<<len<<endl;
    }
    void showThis(){
        cout<<"this pointer: "<<this<<endl;
        cout<<"len via this: "<<this->len<<endl;
    }
};

// Q2 - Swap private values using friend function
class MyBox {
    int val;
public:
    MyBox(int v){ val = v; }
    void show(){ cout<<"Val: "<<val<<endl; }
    friend void swapVals(MyBox &a, MyBox &b);
};

void swapVals(MyBox &a, MyBox &b){
    int t = a.val;
    a.val = b.val;
    b.val = t;
}

// Q3 - Add objects of two different classes using friend function
class ClassB;
class ClassA {
    int x;
public:
    ClassA(int v){ x = v; }
    friend int addBoth(ClassA a, ClassB b);
};
class ClassB {
    int y;
public:
    ClassB(int v){ y = v; }
    friend int addBoth(ClassA a, ClassB b);
};
int addBoth(ClassA a, ClassB b){
    return a.x + b.y;
}

// Q4 - Friend class
class Engine {
    int power;
public:
    Engine(int p){ power = p; }
    friend class Car;
};
class Car {
public:
    void showPower(Engine e){
        cout<<"Engine power (accessed via friend class): "<<e.power<<endl;
    }
};

// Q5 - Array of Objects for rectangles
class Rect {
    int w, h;
public:
    void setData(int a, int b){ w = a; h = b; }
    void showArea(){
        cout<<"Width="<<w<<" Height="<<h<<" Area="<<w*h<<endl;
    }
};

// Q6 - Inline function cube
inline int cube(int n){
    return n * n * n;
}

// Q7 - Pass and return object
class Point {
public:
    int x, y;
    Point(int a = 0, int b = 0){ x = a; y = b; }
    void show(){ cout<<"Point("<<x<<","<<y<<")"<<endl; }
};

Point addByValue(Point p1, Point p2){
    return Point(p1.x + p2.x, p1.y + p2.y);
}

Point addByAddress(Point *p1, Point *p2){
    return Point(p1->x + p2->x, p1->y + p2->y);
}

int main(){
    cout<<"=== Q1: Pointer to Object and this pointer ==="<<endl;
    Box b(15);
    b.show();
    Box *ptr = &b;
    ptr->show();
    b.showThis();

    cout<<"\n=== Q2: Friend function - swap private values ==="<<endl;
    MyBox m1(5), m2(20);
    cout<<"Before: "; m1.show(); m2.show();
    swapVals(m1, m2);
    cout<<"After: ";  m1.show(); m2.show();

    cout<<"\n=== Q3: Friend function - add two class objects ==="<<endl;
    ClassA ca(7);
    ClassB cb(3);
    cout<<"Sum of ClassA and ClassB: "<<addBoth(ca, cb)<<endl;

    cout<<"\n=== Q4: Friend class ==="<<endl;
    Engine eng(200);
    Car car;
    car.showPower(eng);

    cout<<"\n=== Q5: Array of Objects - Rectangle Areas ==="<<endl;
    Rect rects[4];
    rects[0].setData(3, 4);
    rects[1].setData(5, 6);
    rects[2].setData(7, 2);
    rects[3].setData(9, 1);
    for(int i = 0; i < 4; i++){
        cout<<"Rectangle "<<i+1<<": ";
        rects[i].showArea();
    }

    cout<<"\n=== Q6: Inline cube function ==="<<endl;
    cout<<"Cube of 3 = "<<cube(3)<<endl;
    cout<<"Cube of 5 = "<<cube(5)<<endl;
    cout<<"Cube of 7 = "<<cube(7)<<endl;

    cout<<"\n=== Q7a: Pass by Value ==="<<endl;
    Point p1(2, 3), p2(4, 5);
    Point r1 = addByValue(p1, p2);
    cout<<"Result: "; r1.show();

    cout<<"\n=== Q7b: Pass by Address ==="<<endl;
    Point r2 = addByAddress(&p1, &p2);
    cout<<"Result: "; r2.show();

    return 0;
}
