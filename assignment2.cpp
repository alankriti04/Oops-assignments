#include<iostream>
#include<string>
using namespace std;

// Q1 - Structure for Student
struct StudentStruct {
    string name;
    int roll;
    string degree;
    string hostel;
    float cgpa;

    void addDetails(){
        cout<<"Enter Name: "; cin>>name;
        cout<<"Enter Roll No: "; cin>>roll;
        cout<<"Enter Degree: "; cin>>degree;
        cout<<"Enter Hostel: "; cin>>hostel;
        cout<<"Enter CGPA: "; cin>>cgpa;
    }
    void updateDetails(){
        cout<<"Enter new Name: "; cin>>name;
        cout<<"Enter new Degree: "; cin>>degree;
    }
    void updateCGPA(){
        cout<<"Enter new CGPA: "; cin>>cgpa;
    }
    void updateHostel(){
        cout<<"Enter new Hostel: "; cin>>hostel;
    }
    void displayDetails(){
        cout<<"Name: "<<name<<" Roll: "<<roll<<" Degree: "<<degree<<" Hostel: "<<hostel<<" CGPA: "<<cgpa<<endl;
    }
};

// Q2 - Class with private data members and mix of private/public functions
class StudentClass {
private:
    string name;
    int roll;
    float cgpa;
    void checkCGPA(){
        if(cgpa > 10) cgpa = 10;
        if(cgpa < 0)  cgpa = 0;
    }
public:
    string degree;
    string hostel;
    void addDetails(){
        cout<<"Enter Name: "; cin>>name;
        cout<<"Enter Roll: "; cin>>roll;
        cout<<"Enter Degree: "; cin>>degree;
        cout<<"Enter Hostel: "; cin>>hostel;
        cout<<"Enter CGPA: "; cin>>cgpa;
        checkCGPA();
    }
    void updateDetails(){
        cout<<"Enter new Name: "; cin>>name;
        cout<<"Enter new Degree: "; cin>>degree;
    }
    void updateCGPA(){
        cout<<"Enter new CGPA: "; cin>>cgpa;
        checkCGPA();
    }
    void updateHostel(){
        cout<<"Enter new Hostel: "; cin>>hostel;
    }
    void displayDetails(){
        cout<<"Name: "<<name<<" Roll: "<<roll<<" Degree: "<<degree<<" Hostel: "<<hostel<<" CGPA: "<<cgpa<<endl;
    }
};

// Q3 - Private member function called inside public member function
class Demo {
private:
    void greet(){
        cout<<"Hello from private function"<<endl;
    }
public:
    void show(){
        cout<<"Inside public function, calling private:"<<endl;
        greet();
    }
};

// Q4 - Rectangle class
class Rectangle {
    int width, height;
public:
    void getdata(){
        cout<<"Enter width: "; cin>>width;
        cout<<"Enter height: "; cin>>height;
    }
    void calculatearea(){
        cout<<"Area = "<<width * height<<endl;
    }
};

// Q5 - Complex class
class Complex {
    float real, imag;
public:
    void setComplex(float r, float i){
        real = r;
        imag = i;
    }
    void displayComplex(){
        cout<<real<<"+"<<imag<<"i"<<endl;
    }
    Complex add(Complex c){
        Complex temp;
        temp.real = real + c.real;
        temp.imag = imag + c.imag;
        return temp;
    }
};

// Q6 - Scope resolution operator uses
int globalX = 100;

class ScopeClass {
public:
    static int count;
    int x;
    void showGlobal(int x){
        cout<<"Local x: "<<x<<endl;
        cout<<"Global x: "<<::globalX<<endl;
        cout<<"Static count: "<<ScopeClass::count<<endl;
        std::cout<<"Using std:: scope on cout"<<std::endl;
    }
};
int ScopeClass::count = 5;

void ScopeClass_outsideFunc();
void ScopeClass_outsideFunc(){
    cout<<"Function defined outside using scope resolution"<<endl;
}

// Q7 - Namespace
namespace First {
    int val = 10;
    void show(){ cout<<"First namespace val: "<<val<<endl; }
}
namespace Second {
    int val = 20;
    void show(){ cout<<"Second namespace val: "<<val<<endl; }
}

int main(){
    cout<<"=== Q1: Structure ==="<<endl;
    StudentStruct s1;
    s1.addDetails();
    s1.displayDetails();
    s1.updateCGPA();
    s1.displayDetails();

    cout<<"\n=== Q2: Class with private/public ==="<<endl;
    StudentClass s2;
    s2.addDetails();
    s2.displayDetails();
    s2.updateHostel();
    s2.displayDetails();

    cout<<"\n=== Q3: Private function in public ==="<<endl;
    Demo d;
    d.show();

    cout<<"\n=== Q4: Rectangle ==="<<endl;
    Rectangle r;
    r.getdata();
    r.calculatearea();

    cout<<"\n=== Q5: Complex Numbers ==="<<endl;
    Complex c1, c2, c3;
    c1.setComplex(3.0, 4.0);
    c2.setComplex(1.0, 2.0);
    cout<<"C1: "; c1.displayComplex();
    cout<<"C2: "; c2.displayComplex();
    c3 = c1.add(c2);
    cout<<"Sum: "; c3.displayComplex();

    cout<<"\n=== Q6: Scope Resolution ==="<<endl;
    ScopeClass sc;
    sc.x = 50;
    sc.showGlobal(25);
    ScopeClass_outsideFunc();

    cout<<"\n=== Q7: Namespace ==="<<endl;
    First::show();
    Second::show();
    cout<<"First::val = "<<First::val<<" Second::val = "<<Second::val<<endl;

    return 0;
}
