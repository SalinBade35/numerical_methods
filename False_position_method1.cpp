//// false position method
//
#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<cmath>
using namespace std;



double func(double x)
{
//    return x*x*x - x*x + 2;
	return x*log10(x)-1.2;
}


void regulaFalsi(double a, double b)
{
    if (func(a) * func(b) >= 0)
    {
        cout << "You have not assumed right a and b\n";
        return;
    }

    double c = a;

    for (int i=0; i < 100; i++)
    {

        c = (a*func(b) - b*func(a))/ (func(b) - func(a));

      
        if (func(c)==0)
            break;

     
        else if (func(c)*func(a) < 0)
            b = c;
        else
            a = c;
    }
    cout << "The value of root is : " << c;
}


int main()
{
    
    double a =-200, b = 300;
    regulaFalsi(a, b);
    return 0;
}



