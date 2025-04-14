#include<iostream>
#include<cmath>

using namespace std;
float f(float x){
	return (3*x)-cos(x)-1;
}

float f1(float x){
	return (3+sin(x));
}


int main()
{
	float x, x0, e;
	cout<<"entre the initial guess :  ";
	cin>>x0;
	
	cout<<"entre the error margin:  ";
	cin>>e;
	
	do{
		x0 = x;
		x = x0-(f(x0)/f1(x0));		
	}while(fabs(x-x0)>e);
	
	cout<<"root is "<< x;
	return 0;
}

