#include <iostream>    
#include "Utils.h"
#include <conio.h>

using namespace std;

int main()           
{
	Utils U;
	cout<<endl;
	int sum =U.sumUp(5);
	if(sum == 0)
		cout<<"Input a positive number";
	else
		cout<<sum;

	Dog d1("ruby");
	cout<< endl;
	cout<< d1.getName();

	d1.setHeight(2.5);

	Dog d2;
	d2=d1;

	cout<< endl;
	cout<< d2.getName();
	cout<< endl;
	cout<< d2.getHeight();

	getch();
}