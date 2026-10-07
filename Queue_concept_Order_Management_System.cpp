#include<iostream>
using namespace std;

int main()
{
    int queue[10];
    int front = 0;
    int rear = 0;

    cout <<"Enter 10 customer orders:\n";

    for(int i = 0; i < 10; i++)

     {
        cin >> queue[rear];
        rear++;
     }

    //To process the orders
        cout <<"\nProcessing orders:\n";

            while (front < rear)
    { 
       cout <<"Processing orders:" <<queue[front] << endl;
       front++;
    }
    
        
}
