#include <iostream>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <fstream>
#include "vaccine_dose_registration.h"
using namespace std;

void menu();
void choice()
{

    cout << "ENTER THE OPERATION YOU WANT TO PERFORM : ";
    int n;
    cin >> n;
    system("cls");
    goto_xy(5, center);
    switch (n)
    {
    case 1:
        rapid_covid_test();
        break;
    case 2:
        get_second_dose();
        break;
    case 3:
        goto_xy(36, center - 10);
        cout << "Thank You For Using Vaccine Management System........Press enter to exit";
        cin.get();
        exit(0);
        break;
    case 4:
        search_menu();
        break;
    case 5:
        vaccine_inventory();
        break;
    }
    menu();
}
void menu()
{
    system("cls");
    goto_xy(5, center);
    cout<<"***********************************************";
    goto_xy(1, center);
    cout<<"***********************************************";
    goto_xy(1, center);
    cout<<"**                                           **";
    goto_xy(1, center);
    cout<<"**                                           **";
    goto_xy(1, center);
    cout<<"**                                           **";
    goto_xy(1, center);
    cout<<"**          COVID                            **";
    goto_xy(1, center);
    cout<<"**          VACCINE                          **";
    goto_xy(1, center);
    cout<<"**          MANAGEMENT                       **";
    goto_xy(1, center);
    cout<<"**          SYSTEM                           **";
    goto_xy(1, center);
    cout<<"**                                           **";
    goto_xy(1, center);
    cout<<"**                                           **";
    goto_xy(1, center);
    cout<<"**                                           **";
    goto_xy(1, center);
    cout<<"***********************************************";
    goto_xy(1, center);
    cout<<"***********************************************";
    goto_xy(1, center);
    cout << "COVID MANAGEMENT SYSTEM";
    goto_xy(5, center);
    cout << "1. RAPID COVID TEST" << endl;
    goto_xy(1, center);
    cout << "2. GET 2nd DOSE " << endl;
    goto_xy(1, center);
    cout << "3. EXIT" << endl;
    goto_xy(1, center);
    cout << "4. SEARCH DATA" << endl;
    goto_xy(1, center);
    cout << "5. MANAGE VACCINATION RECORDS " << endl;
    goto_xy(1, center);
    choice();
}
int main()
{
    goto_xy(5, center);
    menu();
    return 0;
}