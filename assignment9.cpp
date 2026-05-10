#include<iostream>
#include<fstream>
#include<string>
#include<cctype>
using namespace std;

// Q1 - Write numbers 1 to 200 in NUM.TXT
void q1(){
    ofstream f("NUM.TXT");
    for(int i = 1; i <= 200; i++)
        f<<i<<"\n";
    f.close();
    cout<<"Numbers 1-200 written to NUM.TXT"<<endl;

    ifstream fin("NUM.TXT");
    int n;
    cout<<"First 5 lines: ";
    for(int i = 0; i < 5; i++){ fin>>n; cout<<n<<" "; }
    cout<<endl;
    fin.close();
}

// Q2 - Count alphabets in NOTES.TXT
void countAlphabets(){
    ofstream fw("NOTES.TXT");
    fw<<"Hello World! This is a test file 123."<<endl;
    fw.close();

    ifstream f("NOTES.TXT");
    int count = 0;
    char ch;
    while(f.get(ch)){
        if(isalpha(ch)) count++;
    }
    f.close();
    cout<<"Number of alphabets in NOTES.TXT: "<<count<<endl;
}

// Q3 - Copy contents of one file to another
void q3(){
    ofstream fw("SOURCE.TXT");
    fw<<"This is the source file content."<<endl;
    fw<<"It has multiple lines."<<endl;
    fw.close();

    ifstream fin("SOURCE.TXT");
    ofstream fout("DEST.TXT");
    string line;
    while(getline(fin, line))
        fout<<line<<"\n";
    fin.close();
    fout.close();

    cout<<"File copied. Reading DEST.TXT:"<<endl;
    ifstream rd("DEST.TXT");
    while(getline(rd, line)) cout<<line<<endl;
    rd.close();
}

// Q4 - I/O on characters: input string, length, store in file, fetch back
void q4(){
    string str;
    cout<<"Enter a string: ";
    cin>>str;
    cout<<"Length: "<<str.length()<<endl;

    ofstream fw("CHARS.TXT");
    fw<<str;
    fw.close();

    ifstream fr("CHARS.TXT");
    char ch;
    cout<<"Fetched from file: ";
    while(fr.get(ch)) cout<<ch;
    cout<<endl;
    fr.close();
}

// Q5 - seekg, seekp, tellg operations
void q5(){
    ofstream fw("AZ.TXT");
    for(char c = 'A'; c <= 'Z'; c++) fw<<c;
    fw.close();

    cout<<"=== Q5a: Read 10th character using seekg ==="<<endl;
    ifstream fr("AZ.TXT");
    fr.seekg(9);
    char ch;
    fr.get(ch);
    cout<<"10th character: "<<ch<<endl;
    fr.close();

    cout<<"=== Q5b: Overwrite 5th character using seekp ==="<<endl;
    fstream fs("AZ.TXT", ios::in | ios::out);
    fs.seekp(4);
    fs.put('*');
    fs.close();
    ifstream fr2("AZ.TXT");
    string content;
    getline(fr2, content);
    cout<<"After overwrite: "<<content<<endl;
    fr2.close();

    cout<<"=== Q5c: File size using tellg ==="<<endl;
    ifstream fr3("AZ.TXT", ios::ate);
    cout<<"File size: "<<fr3.tellg()<<" bytes"<<endl;
    fr3.close();

    cout<<"=== Q5d: Read last character using seekg ==="<<endl;
    ifstream fr4("AZ.TXT", ios::ate);
    fr4.seekg(-1, ios::end);
    fr4.get(ch);
    cout<<"Last character: "<<ch<<endl;
    fr4.close();

    cout<<"=== Q5e: data.txt with seekg and tellg ==="<<endl;
    ofstream fw2("data.txt");
    fw2<<"Hello World! This is C++ file handling."<<endl;
    fw2<<"Second line of the file."<<endl;
    fw2.close();

    ifstream fr5("data.txt");
    fr5.seekg(10);
    cout<<"Position after seekg(10): "<<fr5.tellg()<<endl;
    string remaining;
    while(getline(fr5, remaining)) cout<<remaining<<endl;
    fr5.close();
}

// Q6 - Write "Hello World", show put pointer, replace "World" with "C++"
void q6(){
    string text = "Hello World";

    ofstream fw("HW.TXT");
    cout<<"Writing characters and put pointer positions:"<<endl;
    for(int i = 0; i < (int)text.size(); i++){
        fw.put(text[i]);
        cout<<"Wrote '"<<text[i]<<"'  put pointer at: "<<fw.tellp()<<endl;
    }
    fw.close();

    cout<<"Replacing 'World' with 'C++' using seekp:"<<endl;
    fstream fs("HW.TXT", ios::in | ios::out);
    fs.seekp(6);
    fs<<"C++  ";
    fs.close();

    ifstream fr("HW.TXT");
    string result;
    getline(fr, result);
    cout<<"File content after replace: "<<result<<endl;
    fr.close();
}

int main(){
    cout<<"=== Q1: Write 1-200 to NUM.TXT ==="<<endl;
    q1();

    cout<<"\n=== Q2: Count alphabets in NOTES.TXT ==="<<endl;
    countAlphabets();

    cout<<"\n=== Q3: Copy file ==="<<endl;
    q3();

    cout<<"\n=== Q4: Character I/O ==="<<endl;
    q4();

    cout<<"\n=== Q5: seekg / seekp / tellg ==="<<endl;
    q5();

    cout<<"\n=== Q6: Write + put pointer + replace ==="<<endl;
    q6();

    return 0;
}
