#include<iostream>
#include<string>
using namespace std;

// Q1 - Library with Book array, scope resolution, pass-by-reference
class Book {
    string title, author, isbn;
public:
    void setData(string t, string a, string i){ title = t; author = a; isbn = i; }
    string getIsbn(){ return isbn; }
    void display(){ cout<<"Title: "<<title<<"  Author: "<<author<<"  ISBN: "<<isbn<<endl; }
    bool isEmpty(){ return isbn == ""; }
};

class Library {
    Book books[10];
    int count;
public:
    Library(){ count = 0; }
    bool addNewBook(string &title, string &author, string &isbn);
    bool removeBooks(string &isbn);
    void displayDetails();
};

bool Library::addNewBook(string &title, string &author, string &isbn){
    if(count >= 10) return false;
    books[count].setData(title, author, isbn);
    count++;
    return true;
}

bool Library::removeBooks(string &isbn){
    for(int i = 0; i < count; i++){
        if(books[i].getIsbn() == isbn){
            for(int j = i; j < count - 1; j++)
                books[j] = books[j+1];
            count--;
            return true;
        }
    }
    return false;
}

void Library::displayDetails(){
    cout<<"Books in Library:"<<endl;
    for(int i = 0; i < count; i++) books[i].display();
}

// Q2 - Library using constructors and this pointer
class Book2 {
    string title, author, isbn;
public:
    Book2(){
        this->title = ""; this->author = ""; this->isbn = "";
    }
    Book2(string title, string author, string isbn){
        this->title = title; this->author = author; this->isbn = isbn;
    }
    Book2(const Book2 &b){
        this->title = b.title; this->author = b.author; this->isbn = b.isbn;
    }
    string getIsbn(){ return this->isbn; }
    void display(){
        cout<<"Title: "<<this->title<<"  Author: "<<this->author<<"  ISBN: "<<this->isbn<<endl;
    }
};

class Library2 {
    Book2 *books;
    int count;
public:
    Library2(){
        this->count = 0;
        this->books = new Book2[10];
    }
    ~Library2(){ delete[] books; }

    void addBook(string t, string a, string i){
        if(this->count < 10){
            this->books[this->count] = Book2(t, a, i);
            this->count++;
        }
    }
    bool removeBooks(string &isbn){
        for(int i = 0; i < this->count; i++){
            if(this->books[i].getIsbn() == isbn){
                for(int j = i; j < this->count - 1; j++)
                    this->books[j] = this->books[j+1];
                this->count--;
                return true;
            }
        }
        return false;
    }
    void displayDetails(){
        cout<<"Books in Library2:"<<endl;
        for(int i = 0; i < this->count; i++) this->books[i].display();
    }
};

// Q3 - Account class with const member function and const long account number
class Account {
    const long accNum;
    long txnId;
    string txnType;
    double balance;
    static long txnCounter;
public:
    Account(long acc, double bal) : accNum(acc), balance(bal), txnId(0), txnType("none"){}

    long depositAmount(const long to, const long from, const double amount){
        balance += amount;
        txnType = "credit";
        txnId = ++txnCounter;
        std::cout<<"Deposited Rs "<<amount<<" | To: "<<to<<" From: "<<from<<std::endl;
        return txnId;
    }

    long creditAmount(const long to, const long from, const double amount){
        balance -= amount;
        txnType = "debit";
        txnId = ++txnCounter;
        std::cout<<"Debited Rs "<<amount<<" | From: "<<from<<" To: "<<to<<std::endl;
        return txnId;
    }

    void displayDetails() const {
        std::cout<<"AccNo: "<<accNum<<"  Balance: "<<balance<<"  LastTxn: "<<txnType<<"  TxnID: "<<txnId<<std::endl;
    }
};
long Account::txnCounter = 0;

// Q4 - Add objects of two different classes using friend function
class ShapeB;
class ShapeA {
    int sides;
public:
    ShapeA(int s){ sides = s; }
    friend int addShapes(ShapeA a, ShapeB b);
};
class ShapeB {
    int sides;
public:
    ShapeB(int s){ sides = s; }
    friend int addShapes(ShapeA a, ShapeB b);
};
int addShapes(ShapeA a, ShapeB b){
    return a.sides + b.sides;
}

// Q5 - Complex with parameterized, copy constructor and friend sum function
class Complex {
    float real, imag;
public:
    Complex(float r = 0, float i = 0){ real = r; imag = i; }
    Complex(const Complex &c){ real = c.real; imag = c.imag; }
    void display(){ cout<<real<<"+"<<imag<<"i"<<endl; }
    friend void sum(Complex c1, Complex c2);
};

void sum(Complex c1, Complex c2){
    Complex result;
    result.real = c1.real + c2.real;
    result.imag = c1.imag + c2.imag;
    cout<<"Sum: "; result.display();
}

int main(){
    cout<<"=== Q1: Library with Scope Resolution ==="<<endl;
    Library lib;
    string t1="C++ Primer",  a1="Lippman",  i1="ISBN001";
    string t2="DSALGO",      a2="Cormen",   i2="ISBN002";
    string t3="OS Concepts",  a3="Silber",   i3="ISBN003";
    string t4="DBMS",         a4="Ramakr",   i4="ISBN004";
    string t5="Networks",     a5="Tanenb",   i5="ISBN005";
    lib.addNewBook(t1, a1, i1);
    lib.addNewBook(t2, a2, i2);
    lib.addNewBook(t3, a3, i3);
    lib.addNewBook(t4, a4, i4);
    lib.addNewBook(t5, a5, i5);
    lib.displayDetails();
    cout<<"Removing ISBN002..."<<endl;
    lib.removeBooks(i2);
    lib.displayDetails();

    cout<<"\n=== Q2: Library with Constructors and this pointer ==="<<endl;
    Library2 lib2;
    lib2.addBook("Java", "Gosling", "J001");
    lib2.addBook("Python", "Guido",  "P002");
    lib2.addBook("Rust",   "Klabnik","R003");

    Book2 copyBook("Go Lang", "Pike", "G004");
    Book2 copyBook2(copyBook);
    lib2.addBook("Go Lang", "Pike", "G004");

    cout<<"Initializer list style (dynamic init):"<<endl;
    Book2 arr[2] = {Book2("Scala","Odersky","SC01"), Book2("Kotlin","JBrains","KT01")};
    for(int i = 0; i < 2; i++) arr[i].display();

    lib2.displayDetails();
    string rem = "P002";
    lib2.removeBooks(rem);
    lib2.displayDetails();

    cout<<"\n=== Q3: Account ==="<<endl;
    Account acc1(1001, 5000);
    Account acc2(1002, 3000);
    Account acc3(1003, 8000);
    Account acc4(1004, 2000);
    Account acc5(1005, 6000);

    acc1.depositAmount(1001, 1002, 1000);
    acc1.displayDetails();
    acc2.creditAmount(1001, 1002, 500);
    acc2.displayDetails();
    acc3.depositAmount(1003, 1004, 2000);
    acc3.displayDetails();
    acc4.creditAmount(1003, 1004, 700);
    acc4.displayDetails();
    acc5.depositAmount(1005, 1001, 1500);
    acc5.displayDetails();

    cout<<"\n=== Q4: Friend function - add two class objects ==="<<endl;
    ShapeA sa(3);
    ShapeB sb(4);
    cout<<"Total sides: "<<addShapes(sa, sb)<<endl;

    cout<<"\n=== Q5: Complex with friend sum ==="<<endl;
    Complex c1(2.0, 3.0), c2(1.5, 2.5);
    Complex c3(c1);
    cout<<"C1: "; c1.display();
    cout<<"C2: "; c2.display();
    cout<<"Copy of C1: "; c3.display();
    sum(c1, c2);

    return 0;
}
