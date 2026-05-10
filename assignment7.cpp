#include<iostream>
#include<cmath>
#include<string>
using namespace std;

// Q1 - Polygon, Rectangle, Triangle with virtual function and base class pointer
class Polygon {
protected:
    float width, height;
public:
    void set_value(float w, float h){ width = w; height = h; }
    virtual float calculate_area(){ return 0; }
};
class RectPoly : public Polygon {
public:
    float calculate_area(){ return width * height; }
};
class TriPoly : public Polygon {
public:
    float calculate_area(){ return 0.5 * width * height; }
};

// Q2 - Shape with pure virtual functions, derived circle, rectangle, triangle
class Shape {
public:
    virtual float area() = 0;
    virtual void display() = 0;
};
class Circle : public Shape {
    float r;
public:
    Circle(float radius){ r = radius; }
    float area(){ return 3.14159 * r * r; }
    void display(){ cout<<"Circle radius="<<r<<" area="<<area()<<endl; }
};
class RectShape : public Shape {
    float w, h;
public:
    RectShape(float a, float b){ w = a; h = b; }
    float area(){ return w * h; }
    void display(){ cout<<"Rectangle w="<<w<<" h="<<h<<" area="<<area()<<endl; }
};
class TriShape : public Shape {
    float b, h;
public:
    TriShape(float a, float c){ b = a; h = c; }
    float area(){ return 0.5 * b * h; }
    void display(){ cout<<"Triangle base="<<b<<" height="<<h<<" area="<<area()<<endl; }
};

// Q3 - Function overloading for triangle areas
float triArea(float base, float height){
    return 0.5 * base * height;
}
float triArea(float side){
    return (sqrt(3.0) / 4.0) * side * side;
}
float triArea(float a, float b, float c){
    float s = (a + b + c) / 2.0;
    return sqrt(s * (s-a) * (s-b) * (s-c));
}

// Q4 - Abstract class Student, derived Engineering, Medicine, Science
class StudentAbs {
public:
    virtual void display() = 0;
};
class Engineering : public StudentAbs {
    string name;
public:
    Engineering(string n){ name = n; }
    void display(){ cout<<"Engineering student: "<<name<<endl; }
};
class Medicine : public StudentAbs {
    string name;
public:
    Medicine(string n){ name = n; }
    void display(){ cout<<"Medicine student: "<<name<<endl; }
};
class Science : public StudentAbs {
    string name;
public:
    Science(string n){ name = n; }
    void display(){ cout<<"Science student: "<<name<<endl; }
};

// Q5 - Time class with + operator overloading
class Time {
    int h, m, s;
public:
    Time(int a = 0, int b = 0, int c = 0){ h = a; m = b; s = c; }
    Time operator+(Time t){
        Time result;
        result.s = s + t.s;
        result.m = m + t.m + result.s / 60;
        result.s = result.s % 60;
        result.h = h + t.h + result.m / 60;
        result.m = result.m % 60;
        return result;
    }
    void show(){ cout<<h<<"h "<<m<<"m "<<s<<"s"<<endl; }
};

// Q6 - STRING class with == and + overloading
class STRING {
    char data[100];
    int len;
public:
    STRING(const char *str = ""){
        len = 0;
        while(str[len]) len++;
        for(int i = 0; i < len; i++) data[i] = str[i];
        data[len] = '\0';
    }
    bool operator==(STRING s){
        if(len != s.len) return false;
        for(int i = 0; i < len; i++)
            if(data[i] != s.data[i]) return false;
        return true;
    }
    STRING operator+(STRING s){
        STRING result;
        int i = 0;
        for(; i < len; i++) result.data[i] = data[i];
        for(int j = 0; j < s.len; j++) result.data[i+j] = s.data[j];
        result.len = len + s.len;
        result.data[result.len] = '\0';
        return result;
    }
    void show(){ cout<<data<<endl; }
};

// Q7 - Matrix class with * overloading using friend function
class Matrix {
    int mat[2][2];
public:
    Matrix(int a, int b, int c, int d){ mat[0][0]=a; mat[0][1]=b; mat[1][0]=c; mat[1][1]=d; }
    void show(){
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 2; j++) cout<<mat[i][j]<<" ";
            cout<<endl;
        }
    }
    friend Matrix operator*(Matrix a, Matrix b);
};
Matrix operator*(Matrix a, Matrix b){
    Matrix result(0, 0, 0, 0);
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++){
            result.mat[i][j] = 0;
            for(int k = 0; k < 2; k++)
                result.mat[i][j] += a.mat[i][k] * b.mat[k][j];
        }
    return result;
}

// Q8 - Overload [] to check array index out of bounds
class SafeArray {
    int arr[5];
public:
    SafeArray(){ for(int i = 0; i < 5; i++) arr[i] = i * 10; }
    int& operator[](int idx){
        if(idx < 0 || idx >= 5){
            cout<<"Index "<<idx<<" out of bounds!"<<endl;
            return arr[0];
        }
        return arr[idx];
    }
};

// Q9 - Overload () for arbitrary arguments
class Calc {
    int result;
public:
    Calc(){ result = 0; }
    void operator()(int a){ result = a; cout<<"One arg: "<<result<<endl; }
    void operator()(int a, int b){ result = a + b; cout<<"Two args sum: "<<result<<endl; }
    void operator()(int a, int b, int c){ result = a + b + c; cout<<"Three args sum: "<<result<<endl; }
};

// Q10 - Overload >> and <<
class Point2D {
    int x, y;
public:
    Point2D(int a = 0, int b = 0){ x = a; y = b; }
    friend istream& operator>>(istream &in, Point2D &p);
    friend ostream& operator<<(ostream &out, const Point2D &p);
};
istream& operator>>(istream &in, Point2D &p){
    cout<<"Enter x and y: ";
    in>>p.x>>p.y;
    return in;
}
ostream& operator<<(ostream &out, const Point2D &p){
    out<<"Point("<<p.x<<","<<p.y<<")";
    return out;
}

// Q11 - Convert float to UDT
class Temp {
    float val;
public:
    Temp(float v){ val = v; cout<<"Float converted to Temp object: "<<val<<endl; }
    void show(){ cout<<"Temp val: "<<val<<endl; }
};

// Q12 - Convert UDT to float
class Distance {
    float meters;
public:
    Distance(float m){ meters = m; }
    operator float(){ return meters; }
};

// Q13 - Convert one UDT to another (Polar to Cartesian)
class Cartesian;
class Polar {
public:
    float r, angle;
    Polar(float a, float b){ r = a; angle = b; }
    operator Cartesian();
};
class Cartesian {
public:
    float x, y;
    Cartesian(float a = 0, float b = 0){ x = a; y = b; }
    void show(){ cout<<"Cartesian x="<<x<<" y="<<y<<endl; }
};
Polar::operator Cartesian(){
    return Cartesian(r * cos(angle), r * sin(angle));
}

int main(){
    cout<<"=== Q1: Virtual function with base class pointer ==="<<endl;
    Polygon *ptr;
    RectPoly rp; rp.set_value(4, 5); ptr = &rp;
    cout<<"Rectangle area: "<<ptr->calculate_area()<<endl;
    TriPoly tp; tp.set_value(4, 5); ptr = &tp;
    cout<<"Triangle area:  "<<ptr->calculate_area()<<endl;

    cout<<"\n=== Q2: Pure virtual - Shape hierarchy ==="<<endl;
    Shape *shapes[3];
    shapes[0] = new Circle(7);
    shapes[1] = new RectShape(4, 6);
    shapes[2] = new TriShape(5, 8);
    for(int i = 0; i < 3; i++) shapes[i]->display();
    for(int i = 0; i < 3; i++) delete shapes[i];

    cout<<"\n=== Q3: Function overloading for triangle types ==="<<endl;
    cout<<"Right angle triangle area (base=6,h=4): "<<triArea(6.0f, 4.0f)<<endl;
    cout<<"Equilateral triangle area (side=5):     "<<triArea(5.0f)<<endl;
    cout<<"Isosceles triangle area (3,4,5):        "<<triArea(3.0f, 4.0f, 5.0f)<<endl;

    cout<<"\n=== Q4: Abstract class Student ==="<<endl;
    StudentAbs *students[3];
    students[0] = new Engineering("Rahul");
    students[1] = new Medicine("Priya");
    students[2] = new Science("Arjun");
    for(int i = 0; i < 3; i++) students[i]->display();
    for(int i = 0; i < 3; i++) delete students[i];

    cout<<"\n=== Q5: Time + operator overloading ==="<<endl;
    Time t1(5, 15, 34), t2(9, 53, 58), t3;
    t3 = t1 + t2;
    t3.show();

    cout<<"\n=== Q6: STRING == and + overloading ==="<<endl;
    STRING s1("Hello"), s2("World"), s3("Hello");
    cout<<"s1==s2: "<<(s1==s2 ? "Yes" : "No")<<endl;
    cout<<"s1==s3: "<<(s1==s3 ? "Yes" : "No")<<endl;
    STRING s4 = s1 + s2;
    cout<<"Concat: "; s4.show();

    cout<<"\n=== Q7: Matrix * overloading ==="<<endl;
    Matrix m1(1, 2, 3, 4), m2(5, 6, 7, 8);
    Matrix m3 = m1 * m2;
    cout<<"Result:"<<endl; m3.show();

    cout<<"\n=== Q8: [] out-of-bounds check ==="<<endl;
    SafeArray sa;
    cout<<"sa[2]="<<sa[2]<<endl;
    cout<<"sa[7]="; sa[7];

    cout<<"\n=== Q9: () overloading with arbitrary args ==="<<endl;
    Calc calc;
    calc(5);
    calc(3, 7);
    calc(1, 2, 3);

    cout<<"\n=== Q10: >> and << overloading ==="<<endl;
    Point2D p;
    cin>>p;
    cout<<p<<endl;

    cout<<"\n=== Q11: Float to UDT ==="<<endl;
    Temp t = 98.6;
    t.show();

    cout<<"\n=== Q12: UDT to float ==="<<endl;
    Distance dist(10.5);
    float f = dist;
    cout<<"Distance in float: "<<f<<endl;

    cout<<"\n=== Q13: Polar to Cartesian ==="<<endl;
    Polar pol(10, 0.5);
    Cartesian cart = pol;
    cart.show();

    return 0;
}
