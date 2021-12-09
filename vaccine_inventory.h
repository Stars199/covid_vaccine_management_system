#include <iostream>
#include <fstream>
#include <iomanip>
#include "searching.h"
#define center 50
using namespace std;

class record
{
public:
    int vaccine_code;
    string name_of_vaccine;
    long quantity;
    int gap_bw_dose;
};
int search_specific_vaccine(int);


void add_new()
{
    system("cls");
    goto_xy(1, center);
    cout << "ADD NEW VACCINE TO INVENTORY";
    goto_xy(1, center);
    FILE *fp;
    record r;
    fp = fopen("vaccine.txt", "a");
    char c = 'y';
    while (c == 'y' || c == 'Y')
    {
        goto_xy(1, center);
        printf("Enter name of the vaccine:  ");
        fflush(stdin);
        getline(cin, r.name_of_vaccine);
        goto_xy(1, center);
        printf("Enter vaccine code:  ");
        cin >> r.vaccine_code;
        goto_xy(1, center);
        printf("Enter initial quantity of vaccine :  ");
        scanf("%ld", &r.quantity);
        goto_xy(1, center);
        printf("Enter gap between two dose of this vaccine : ");
        scanf("%d", &r.gap_bw_dose);
        fwrite(&r, sizeof(r), 1, fp);
        goto_xy(1, center);
        printf("Your data of vaccine is inserted");
        goto_xy(1, center);
        printf("Do you want to add more Y|N  :    ");
        fflush(stdin);
        cin >> c;
    }
    fclose(fp);
    goto_xy(1, center);
    cout << endl
         << "Enter to continue....";
    cin.get();
}
void show_available_vaccine()
{
    FILE *fp;
    record r;
    system("cls");
    fp = fopen("vaccine.txt", "r");
    goto_xy(1, center);
    printf("List of All Vaccines");
    if (fp == NULL)
    {
        goto_xy(1, center);
        printf("Data is not created yet");
    }
    else
    {
        goto_xy(1, center);
        printf("Vaccine name           Vaccine code        Available quantity");
        goto_xy(1, center);
        printf("---------------------------------------------------------------");

        while (fread(&r, sizeof(r), 1, fp))
        {
            goto_xy(1, center);
            cout << r.name_of_vaccine;
            goto_xy(0, 25 - r.name_of_vaccine.size());
            cout << r.vaccine_code;
            string e = to_string(r.vaccine_code);
            goto_xy(0,23 - e.size());
            cout << r.quantity;
        }
    }
    fclose(fp);
    goto_xy(1, center);
    cout<<endl<<"Enter to continue......";
    cin.get();
}

void search()
{
    int c;
    int flag = 0;
    system("cls");
    goto_xy(2, center);
    cout << "VIEW VACCINE DETAILS BY VACCINE CODE";
    goto_xy(2, center);
    printf("Enter vaccine code to be searched:  ");
    cin>>c;
    flag = search_specific_vaccine(c);
    if (flag == 0)
    {
        goto_xy(2, center);
        printf("Vaccine code is not found please enter valid vaccine code...");
    }
    cout << endl
         << "Enter to continue.......";
    cin.get();
}
int search_specific_vaccine(int code)
{
    FILE *fp;
    record r;
    fp = fopen("vaccine.txt", "r");
    if (fp == NULL)
    {
        goto_xy(4, center);
        printf("Data is not created yet");
    }
    else
    {
        while (fread(&r, sizeof(r), 1, fp))
        {
            if (code == r.vaccine_code)
            {
                goto_xy(1, center);
                cout << "Vaccine Name : " << r.name_of_vaccine;
                goto_xy(1, center);
                cout << "Vaccine Code : " << r.vaccine_code;
                goto_xy(1, center);
                cout << "Available Quantity : " << r.quantity;
                goto_xy(1, center);
                cout << "Gap between dose : " << r.gap_bw_dose;
                fclose(fp);
                return 1;
            }
        }
    }
    fclose(fp);
    return 0;
}
void update_vaccine_quantity()
{
    FILE *fp;
    long q;
    int code;
    int flag = 0;
    system("cls");
    fp = fopen("vaccine.txt", "r+");
    record r;
    goto_xy(1, center);
    cout << "UPDATE VACCINE QUANTITY ";
    goto_xy(1, center);
    printf("Enter the vaccine code to update : ");
    scanf("%d", &code);
    while (fread(&r, sizeof(r), 1, fp))
    {
        if (code == r.vaccine_code)
        {
            goto_xy(1, center);
            printf("Enter quantity to be added: ");
            scanf("%ld", &q);
            r.quantity = q + r.quantity;
            fseek(fp, -(long)sizeof(r), 1);
            fwrite(&r, sizeof(r), 1, fp);
            flag = 1;
            break;
        }
    }
    if (flag == 1)
    {
        goto_xy(1, center);
        printf("New Quantity added");
    }
    else
    {
        goto_xy(1, center);
        printf("Vaccine code not found");
    }
    fclose(fp);
    cout<<endl<<"Enter to continue.....";
    cin.get();
}
int first_menu()
{
    system("cls");

    goto_xy(1, center);

    printf(" *** VACCINE INVENTORY SYSTEM *** ");
    goto_xy(5, center);
    goto_xy(1, center);
    printf("1. Add New Vaccines");
    goto_xy(1, center);
    printf("2. Show Available Vaccines");
    goto_xy(1, center);
    printf("3. Search Vaccine");
    goto_xy(1, center);
    printf("4. Update Vaccine Quantity");
    goto_xy(1, center);
    printf("5. Back to previous menu");
    cout << endl
         << "Choose the operation you wants to perform : ";
    int n;
    cin >> n;
    return n;
}
int vaccine_inventory()
{
    system("cls");
    int ch;
    while (1)
    {
        ch = first_menu();
        switch (ch)
        {
        case 1:
            add_new();
            break;
        case 2:
            show_available_vaccine();
            break;
        case 3:
            search();
            break;
        case 4:
            update_vaccine_quantity();
            break;
        case 5:
            return 0;
            break;
        }
    }
}