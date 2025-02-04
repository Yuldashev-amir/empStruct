// Использование классов и методов emp.h и emp.cpp
#include "emp.h"
#include "emp.cpp"
#include <iostream>
#include <cstdlib>
#include <string>
int main()
{
    using std::cout;
    using std::cin;
    using std::string;
    using std::endl;
    using std::flush;

    char ch;
    int cowDepartments = 0;
    cout << "Enter please cow departments your organization: ";
    cin >> cowDepartments;

    cout << "e select employee " << " r select manager " << flush;
    cout << " f select fink " << " h select highfink " << endl;
    cout << "Create new Organization structure: \n" << flush;
    abstr_emp ** GrandCS = new abstr_emp*[cowDepartments];

    for (int index = 0; index < cowDepartments; index++)
    {
        cout << "Departments number: " << index + 1 << "is a why employee need ";
        char ch;
        cin >> ch;
        switch(tolower(ch))
        {
            case 'e': GrandCS[index] = new employee;
            GrandCS[index]->SetAll();
            GrandCS[index]->ShowAll();
            break;
            case 'r': GrandCS[index] = new manager;
            GrandCS[index]->SetAll();
            GrandCS[index]->ShowAll();
            break;
            case 'f': GrandCS[index] = new fink;
            GrandCS[index]->SetAll();
            GrandCS[index]->ShowAll();
            break;
            case 'h': GrandCS[index] = new highfink;
            GrandCS[index]->SetAll();
            GrandCS[index]->ShowAll();
            break;
            default:
                --index;
                cout << "Invalid choise!" << endl;
                break;
        }
    }
    return 0;
}
