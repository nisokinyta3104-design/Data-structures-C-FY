#include<iostream>
using namespace std;

int main()
{

	//input marks
	int marks[5];
	cout << "Enter the marks:";

	for(int i=0; i<5; i++)
	{
	cin >> marks[i];
	}
	//For Descending Order

	for (int i = 0; i < 4; i++)

	{
	 for(int j=0; j<4-1; j++)

	 {
	   if (marks[j] < marks[j+1])
	    {
	      int temp = marks[j];
	      marks[j] = marks[j+1];
	      marks[j+1] = temp;
	    }

	 }

	}

	 //For Display
	    cout << "From highest to lowest:";

	     for (int i=0;i<5; i++)
		{
		   cout << marks[i] << "";
		}

		   return 0;
}
