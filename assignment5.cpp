#include<iostream>
#include<string>
using namespace std;

// Q1 - Simple base and derived class
class Animal {
public:
    string name;
    void speak(){ cout<<"Animal speaks"<<endl; }
};
class Dog : public Animal {
public:
    void bark(){ cout<<name<<" barks"<<endl; }
};

// Q2 - Protected access specifier in inheritance
class BaseP {
protected:
    int x;
public:
    BaseP(){ x = 50; }
};
class DerivedP : public BaseP {
public:
    void show(){ cout<<"Protected x from base: "<<x<<endl; }
};

// Q3 - Modes of inheritance
class Base3 {
public:
    int a;
protected:
    int b;
public:
    Base3(){ a = 1; b = 2; }
};
class PubD : public Base3 {
public:
    void show(){ cout<<"Public mode - a:"<<a<<" b:"<<b<<endl; }
};
class ProD : protected Base3 {
public:
    void show(){ cout<<"Protected mode - a:"<<a<<" b:"<<b<<endl; }
};
class PriD : private Base3 {
public:
    void show(){ cout<<"Private mode - a:"<<a<<" b:"<<b<<endl; }
};

// Q4 - Types of Inheritance

// Single
class A { public: void showA(){ cout<<"A"<<endl; } };
class B : public A { public: void showB(){ cout<<"B"<<endl; } };

// Multiple
class MA { public: void showMA(){ cout<<"Multiple Base A"<<endl; } };
class MB { public: void showMB(){ cout<<"Multiple Base B"<<endl; } };
class MC : public MA, public MB { public: void showMC(){ cout<<"Multiple Derived C"<<endl; } };

// Hierarchical
class HA { public: void showHA(){ cout<<"Hierarchical Base A"<<endl; } };
class HB : public HA { public: void showHB(){ cout<<"Hierarchical B"<<endl; } };
class HC : public HA { public: void showHC(){ cout<<"Hierarchical C"<<endl; } };
class HD : public HA { public: void showHD(){ cout<<"Hierarchical D"<<endl; } };

// Multilevel
class LA { public: void showLA(){ cout<<"Multilevel A"<<endl; } };
class LB : public LA { public: void showLB(){ cout<<"Multilevel B"<<endl; } };
class LC : public LB { public: void showLC(){ cout<<"Multilevel C"<<endl; } };

// Q5 - Constructors and destructors in inheritance
class Parent {
public:
    Parent(){ cout<<"Parent constructor"<<endl; }
    ~Parent(){ cout<<"Parent destructor"<<endl; }
};
class Child : public Parent {
public:
    Child(){ cout<<"Child constructor"<<endl; }
    ~Child(){ cout<<"Child destructor"<<endl; }
};

// Q6 - Book and Textbook (single inheritance)
class Book {
protected:
    string title, author;
    float price;
public:
    Book(string t, string a, float p){ title = t; author = a; price = p; }
    void display(){
        cout<<"Title: "<<title<<" Author: "<<author<<" Price: "<<price<<endl;
    }
};
class Textbook : public Book {
    string subject;
public:
    Textbook(string t, string a, float p, string s) : Book(t, a, p){ subject = s; }
    void display(){
        Book::display();
        cout<<"Subject: "<<subject<<endl;
    }
};

// Q7 - CarDashboard (multiple inheritance)
class Speedometer {
protected:
    int speed;
public:
    Speedometer(int s = 0){ speed = s; }
    void showSpeed(){ cout<<"Speed: "<<speed<<" km/h"<<endl; }
};
class FuelGauge {
protected:
    int fuel;
public:
    FuelGauge(int f = 0){ fuel = f; }
    void showFuel(){ cout<<"Fuel: "<<fuel<<"%"<<endl; }
};
class Thermometer {
protected:
    int temp;
public:
    Thermometer(int t = 0){ temp = t; }
    void showTemp(){ cout<<"Temperature: "<<temp<<"C"<<endl; }
};
class CarDashboard : public Speedometer, public FuelGauge, public Thermometer {
public:
    CarDashboard(int s, int f, int t) : Speedometer(s), FuelGauge(f), Thermometer(t){}
    void displayAll(){ showSpeed(); showFuel(); showTemp(); }
};

// Q8 - LibraryUser hierarchical inheritance
class LibraryUser {
protected:
    string name, id, contact;
public:
    LibraryUser(string n, string i, string c){ name = n; id = i; contact = c; }
    void show(){ cout<<"Name: "<<name<<" ID: "<<id<<" Contact: "<<contact<<endl; }
};
class StudentUser : public LibraryUser {
    int grade;
public:
    StudentUser(string n, string i, string c, int g) : LibraryUser(n, i, c){ grade = g; }
    void show(){ LibraryUser::show(); cout<<"Grade: "<<grade<<endl; }
};
class TeacherUser : public LibraryUser {
    string dept;
public:
    TeacherUser(string n, string i, string c, string d) : LibraryUser(n, i, c){ dept = d; }
    void show(){ LibraryUser::show(); cout<<"Department: "<<dept<<endl; }
};

// Q9 - Vehicle multilevel inheritance
class Vehicle {
protected:
    string make, model;
    int year;
public:
    Vehicle(string mk, string mo, int y){ make = mk; model = mo; year = y; }
    void show(){ cout<<"Make: "<<make<<" Model: "<<model<<" Year: "<<year<<endl; }
};
class Truck : public Vehicle {
protected:
    float load;
public:
    Truck(string mk, string mo, int y, float l) : Vehicle(mk, mo, y){ load = l; }
    void show(){ Vehicle::show(); cout<<"Load Capacity: "<<load<<"T"<<endl; }
};
class RefrigeratedTruck : public Truck {
    float tempCtrl;
public:
    RefrigeratedTruck(string mk, string mo, int y, float l, float t) : Truck(mk, mo, y, l){ tempCtrl = t; }
    void show(){ Truck::show(); cout<<"Temp Control: "<<tempCtrl<<"C"<<endl; }
};

// Q10 - Hybrid inheritance
class Person {
protected:
    string name, address;
public:
    Person(string n, string a){ name = n; address = a; }
    void show(){ cout<<"Name: "<<name<<" Address: "<<address<<endl; }
};
class Staff : virtual public Person {
protected:
    string empId, dept;
public:
    Staff(string n, string a, string e, string d) : Person(n, a){ empId = e; dept = d; }
    void show(){ Person::show(); cout<<"EmpID: "<<empId<<" Dept: "<<dept<<endl; }
};
class StudentP : virtual public Person {
protected:
    string stuId;
    int grade;
public:
    StudentP(string n, string a, string s, int g) : Person(n, a){ stuId = s; grade = g; }
    void show(){ Person::show(); cout<<"StuID: "<<stuId<<" Grade: "<<grade<<endl; }
};
class TeachingAssistant : public Staff, public StudentP {
public:
    TeachingAssistant(string n, string a, string e, string d, string s, int g)
        : Person(n, a), Staff(n, a, e, d), StudentP(n, a, s, g){}
    void show(){
        Person::show();
        cout<<"EmpID: "<<empId<<" Dept: "<<dept<<" StuID: "<<stuId<<" Grade: "<<grade<<endl;
    }
};

int main(){
    cout<<"=== Q1: Simple Inheritance ==="<<endl;
    Animal an; an.name = "Generic"; an.speak();
    Dog dg; dg.name = "Buddy"; dg.speak(); dg.bark();

    cout<<"\n=== Q2: Protected Access ==="<<endl;
    DerivedP dp; dp.show();

    cout<<"\n=== Q3: Modes of Inheritance ==="<<endl;
    PubD pd; pd.show();
    ProD prd; prd.show();
    PriD pvd; pvd.show();

    cout<<"\n=== Q4: Types of Inheritance ==="<<endl;
    cout<<"-- Single --"<<endl;
    B sb; sb.showA(); sb.showB();
    cout<<"-- Multiple --"<<endl;
    MC mc; mc.showMA(); mc.showMB(); mc.showMC();
    cout<<"-- Hierarchical --"<<endl;
    HB hb; hb.showHA(); hb.showHB();
    HC hc; hc.showHA(); hc.showHC();
    HD hd; hd.showHA(); hd.showHD();
    cout<<"-- Multilevel --"<<endl;
    LC lc; lc.showLA(); lc.showLB(); lc.showLC();

    cout<<"\n=== Q5: Constructors and Destructors in Inheritance ==="<<endl;
    { Child ch; }

    cout<<"\n=== Q6: Book and Textbook ==="<<endl;
    Book bk("Novel", "AuthorA", 250);
    bk.display();
    Textbook tb("OOP Book", "AuthorB", 500, "Computer Science");
    tb.display();

    cout<<"\n=== Q7: CarDashboard (Multiple Inheritance) ==="<<endl;
    CarDashboard cd(80, 60, 90);
    cd.displayAll();

    cout<<"\n=== Q8: Library Users (Hierarchical) ==="<<endl;
    StudentUser su("Alice", "S01", "9999999", 10);
    su.show();
    TeacherUser tu("Bob", "T01", "8888888", "Mathematics");
    tu.show();

    cout<<"\n=== Q9: Vehicle Fleet (Multilevel) ==="<<endl;
    RefrigeratedTruck rt("Volvo", "FH16", 2022, 10.0, -18.0);
    rt.show();

    cout<<"\n=== Q10: Teaching Assistant (Hybrid) ==="<<endl;
    TeachingAssistant ta("Tom", "Delhi", "E01", "CS", "ST01", 8);
    ta.show();

    return 0;
}
