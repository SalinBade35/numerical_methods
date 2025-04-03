
//________________________________________ HORNER'S RULE___________________________________________________

#include <iostream>
#include <conio.h>
#include <stdio.h>
#include<iostream>
using namespace std;
int main()
{
    cout << "Horner's Rule\n";

    int n, c[5], x;
    cout << "entre the highest degress of the equation: \n";
    cin >> n;

    cout << "now entre the coefficient:\n";

    for(int i = n; i >= 0; i--)
    {
        cout << "entre the coeff. of " << i << "th power:\n";
        cin >> c[i];
    }

    cout << "find the value of x:\n";
    cin >> x;

    int result;
    result = c[n];

    for (int i = n - 1; i >= 0; i--)
    {
        result = result * x + c[i];
        cout << result;
        cout << endl;
    }

    int answer = result;
    cout << "the final answer is: \n";
    cout << answer;

    return 0;
}


