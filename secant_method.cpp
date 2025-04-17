#include<iostream>
#include<cmath>
using namespace std;

float f(float x){
	return (x*x)-(4*x)-10;
}

int main()
{
	float x1,x2,e, x;
	cout<<"entre initial guess :\n";
	cout<<"x1: ";
	cin>>x1;
	cout<<endl;
	cout<<"x2: ";
	cin>>x2;
	cout<<"entre error margin: ";
	cin>>e;
	
	do{
		x = ((f(x2)*x1)-(f(x1)*x2))/(f(x2)-f(x1));
		cout<<x;
		x1 = x2;
		x2 = x;
		
	}while(fabs(x2 - x1) > e);
	cout<<"root is "<<x;
	return 0;
}
