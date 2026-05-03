#include<iostream>
#include<string>
using namespace std;

struct Studentinfo{
    string name;
    int rollno;
};

struct Bank{
    string name;
    string manager;
    int amount;
};

int main()
{
    Studentinfo s1;

    s1.name = "Arham";
    s1.rollno = 1;

    cout<<"Student info is"<< " " << s1.name << " " << s1.rollno << endl;

    Bank b2;

    b2.name="Alfalah Bank";
    b2.manager="Awaiz";
    b2.amount=95000;

    cout<<"Bank Name :"<< " " << b2.name << endl;
    cout<<"Manager Name :"<< " " << b2.manager << endl;
    cout<<"Amount Exist :"<< " " << b2.amount << endl;


    return 0; 
}