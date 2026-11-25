#include <iostream>
#include<string>
#include <limits>
using namespace std;
struct Product
{
int id;
string name;
double price;
Product*next;
Product*hashNext;
};
Product*head=NULL;
const int SIZE=20;
Product*hashTable[SIZE]={NULL};
int hashFunction(int id)
{
return id %SIZE;
}
void registerProduct()
{
Product *p = new Product;
cout<<"ENTER PRODUCT ID:";
cout << "ENTER PRODUCT ID: ";
cin >> p->id;
if (p->id < 0)
{
    cout << "Product ID cannot be negative.\n";
    delete p;
    return;
}
int index = hashFunction(p->id);
Product*temp = hashTable[index];
while(temp != NULL)
{
    if(temp->id == p->id)
    {
        cout << "PRODUCT ID ALREADY EXISTS!\n";
        delete p;
        return;
    }
    temp = temp->hashNext;
}
cin.ignore(numeric_limits<streamsize>::max(), '\n');
cout << "Enter Product Name: ";
getline(cin, p->name);
cout << "Enter price: ";
cin >> p->price;
if (p->price < 0)
{
    cout << "Price cannot be negative.\n";
    delete p;
    return;
}
p->next = head;
head = p;
p->hashNext = hashTable[index];
hashTable[index] = p;
cout << "Product registered successfully!\n";
}
void updateProduct()
{
    int id;
    cout << "Enter Product ID to update: ";
    cin >> id;
    if (id < 0)
    {
        cout << "Invalid Product ID.\n";
        return;
    }
    int index = hashFunction(id);
    Product* temp = hashTable[index];
    while (temp != NULL)
    {
        if (temp->id == id)
        {
            cout << "\nProduct Found!\n";
            cout << "Current Product Name: " << temp->name << endl;
            cout << "Current Price: " << temp->price << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nEnter New Product Name: ";
            getline(cin, temp->name);
            cout << "Enter New Price: ";
            cin >> temp->price;
            if (temp->price < 0)
            {
                cout << "Price cannot be negative.\n";
                return;
            }
            cout << "\nProduct details updated successfully!\n";
            return;
        }
        temp = temp->hashNext;
    }
    cout << "Product not found.\n";
}
void removeProduct()
{
    int id;
    cout << "Enter Product ID to remove: ";
    cin >> id;
    if (id < 0)
    {
        cout << "Invalid Product ID.\n";
        return;
    }
    int index = hashFunction(id);
    Product* temp = hashTable[index];
    Product* prev = NULL;
    while (temp != NULL && temp->id != id)
    {
        prev = temp;
        temp = temp->hashNext;
    }
    if (temp == NULL)
    {
        cout << "Product not found.\n";
        return;
    }
    if (prev == NULL)
    {
        hashTable[index] = temp->hashNext;
    }
    else
    {
        prev->hashNext = temp->hashNext;
    }
    if (head == temp)
    {
        head = temp->next;
    }
    else
    {
        Product* current = head;
        while (current != NULL && current->next != temp)
        {
            current = current->next;
        }
        if (current != NULL)
        {
            current->next = temp->next;
        }
    }
    delete temp;
    cout << "Product discontinued and removed successfully!\n";
}
void displayProduct()
{
    Product* temp = head;
    if (temp == NULL)
    {
        cout << "No product available.\n";
        return;
    }
    cout << "\n---- All Available Products ----\n";
    while (temp != NULL)
    {
        cout << "\nProduct ID: " << temp->id << endl;
        cout << "Name: " << temp->name << endl;
        cout << "Price: " << temp->price << endl;
        temp = temp->next;
    }
}
int main()
{
    int choice;
    do
    {
        cout << "\n--- E-COMMERCE PRODUCT CATALOG & INVENTORY SYSTEM ---\n";
        cout << "1. ADD PRODUCT\n";
        cout << "2. UPDATE PRODUCT\n";
        cout << "3. REMOVE PRODUCT\n";
        cout << "4. DISPLAY PRODUCT\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
            case 1:
                registerProduct();
                break;
            case 2:
                updateProduct();
                break;
            case 3:
                removeProduct();
                break;
                
            case 4:
                displayProduct();
                break;
            case 5:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 5);
    return 0;
}
