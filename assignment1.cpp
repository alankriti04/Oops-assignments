#include<iostream>
#include<iomanip>
using namespace std;

// Q1
void q1(){
    cout<<"Hello World"<<endl;
}

// Q2
void q2(){
    int a;
    float b;
    char c;
    cout<<"Enter integer: ";
    cin>>a;
    cout<<"Enter decimal: ";
    cin>>b;
    cout<<"Enter character: ";
    cin>>c;
    cout<<"Integer: "<<a<<endl;
    cout<<"Decimal: "<<b<<endl;
    cout<<"Character: "<<c<<endl;
}

// Q3
void q3(){
    float a, b;
    cout<<"Enter two numbers: ";
    cin>>a>>b;
    cout<<"Addition: "<<a+b<<endl;
    cout<<"Subtraction: "<<a-b<<endl;
    cout<<"Multiplication: "<<a*b<<endl;
    if(b != 0)
        cout<<"Division: "<<a/b<<endl;
    else
        cout<<"Cannot divide by zero"<<endl;
}

// Q4
void q4(){
    float c, f;
    cout<<"Enter temperature in Celsius: ";
    cin>>c;
    f = 9*c/5 + 32;
    cout<<"Fahrenheit: "<<f<<endl;
}

// Q5
void q5(){
    cout<<"Hello\tWorld\n";
    cout<<"Line1"<<endl;
    cout<<"AB\bC"<<endl;
    cout<<setw(10)<<"Right"<<endl;
    cout<<setw(10)<<"Align"<<endl;
}

// Q6
void q6(){
    int a = 10;
    cout<<"Initial value: "<<a<<endl;
    a += 5;
    cout<<"After += 5: "<<a<<endl;
    a -= 3;
    cout<<"After -= 3: "<<a<<endl;
}

// Q7
void q7(){
    int a, b;
    cout<<"Enter two numbers: ";
    cin>>a>>b;
    cout<<"Before swap: a="<<a<<" b="<<b<<endl;
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    cout<<"After swap: a="<<a<<" b="<<b<<endl;
}

// Q8
void q8(){
    int days;
    cout<<"Enter number of days late: ";
    cin>>days;
    if(days > 30){
        cout<<"Membership cancelled"<<endl;
    } else if(days > 10){
        float fine = 5*0.50 + 5*1.0 + (days-10)*5.0;
        cout<<"Fine: Rs "<<fine<<endl;
    } else if(days > 5){
        float fine = 5*0.50 + (days-5)*1.0;
        cout<<"Fine: Rs "<<fine<<endl;
    } else if(days > 0){
        float fine = days * 0.50;
        cout<<"Fine: Rs "<<fine<<endl;
    } else {
        cout<<"No fine"<<endl;
    }
}

// Q9
void q9(){
    float a, b;
    int ch;
    cout<<"1.Add 2.Subtract 3.Multiply 4.Divide"<<endl;
    cout<<"Enter choice: ";
    cin>>ch;
    cout<<"Enter two numbers: ";
    cin>>a>>b;
    switch(ch){
        case 1: cout<<"Result: "<<a+b<<endl; break;
        case 2: cout<<"Result: "<<a-b<<endl; break;
        case 3: cout<<"Result: "<<a*b<<endl; break;
        case 4:
            if(b != 0)
                cout<<"Result: "<<a/b<<endl;
            else
                cout<<"Cannot divide by zero"<<endl;
            break;
        default: cout<<"Invalid choice"<<endl;
    }
}

// Q10
void q10(){
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    if(n % 2 == 0)
        cout<<"Even (if-else)"<<endl;
    else
        cout<<"Odd (if-else)"<<endl;
    cout<<(n%2==0 ? "Even" : "Odd")<<" (conditional operator)"<<endl;
}

int main(){
    int ch;
    cout<<"Enter question number (1-10): ";
    cin>>ch;
    switch(ch){
        case 1:  q1();  break;
        case 2:  q2();  break;
        case 3:  q3();  break;
        case 4:  q4();  break;
        case 5:  q5();  break;
        case 6:  q6();  break;
        case 7:  q7();  break;
        case 8:  q8();  break;
        case 9:  q9();  break;
        case 10: q10(); break;
        default: cout<<"Invalid"<<endl;
    }
    return 0;
}
