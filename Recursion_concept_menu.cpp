#include<iostream>
using namespace std;

void menu()
{
    int choice;


    cout <<"\n\n====== MENU CARD =======\n";
    cout <<"\n1. Pizza";
    cout <<"\n2. Burger";
    cout <<"\n3. Maggi";
    cout <<"\n4. Pasta";
    cout <<"\n5. Exit";

    cout <<"\nEnter your choice:";   
        cin >> choice;

    if (choice ==1)
    {
       cout << "You selected Pizza.";
        menu();
    }   
    else if(choice == 2)
    {  
        cout << "You selected Burger.";
         menu();
    } 
    else if (choice == 3)
    {
        cout << "You selected Maggi.";
         menu();
    }
    else if (choice == 4)        
    {   
        cout << "You selected Pasta";
         menu();
    }
    else if (choice == 5)       
    {
        cout << "Exit";
         menu();
    }
    else
    {
        cout << "\nInvalid choice!";
            menu();
    }
    {
         cout << "\n Recently cancelled orders:\n";
    }
}
    int main()
    {
        menu();
    return 0;
    }
 

