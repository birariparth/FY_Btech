#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class employee
{
    string name[5];
    int id[5];
    string department[5];
    string DOJ[5];
    string address[5];
    string number[5];
    public:
    //employee
    //{

    //}
    void Getdata(int x)
    {
        int a = x;
        cout << "\nPlease enter your details";

        for(int i=0; i<a; i++)
        {
            cout << "\nName: ";
            getline(cin, name[i]);
   
            cout << "\nDepartment: ";
            getline(cin, department[i]);
   
            cout << "\nEmployee ID: ";
            cin >> id[i];
            cin.ignore();             //to clear newline character
   
            cout << "\nDate of joining: ";
            getline(cin, DOJ[i]);
   
            cout << "\nAddress: ";
            getline(cin, address[i]);
   
            cout << "\nContact details: ";
            getline(cin, number[i]);
        }
    }

    void Display(int x)
    {   
        int a = x;
        cout << "Employee details"<<endl;

        cout << left
            << setw(20)<<"\nName"
            << setw(20)<<"Department"
            << setw(20)<<"Employee ID"
            << setw(20)<<"Date of Joining"
            << setw(20)<<"Address"
            << setw(20)<<"Contact details"<<endl;

        for(int i=0; i<a; i++)
        {
            cout << left
                << setw(20)<<name[i]
                << setw(20)<<department[i]
                << setw(20)<<id[i]
                << setw(20)<<DOJ[i]
                << setw(20)<<address[i]
                << setw(20)<<number[i]<<endl;
        }
    }
};

int main()
{
    employee object;
    int x;

    cout << "\nEnter number of employees"<<endl;
    cin >> x;

    object.Getdata(x);
    object.Display(x);
    return 0;
}