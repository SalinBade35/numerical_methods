//#include <iostream>
//#include <cmath>
//
//using namespace std;
//
//
//double func(double x) {
//    return x * x - 4 * x - 10;
//}
//
//
//void bisection(double x1, double x2, double e) {
//    if (func(x1) * func(x2) >= 0) {
//        cout << "You have not assumed the correct initial guesses (x1 and x2)\n";
//        return;
//    }
//
////    double x0;
////    while ((x2 - x1) >= e) {
////       
////        x0 = (x1 + x2) / 2.0;  
//// 
////        if (fabs(func(x0)) < e) 
////            break;
////
////        else if (func(x0) * func(x1) < 0)
////            x2 = x0;
////            
////        else
////            x1 = x0;
////    }
//    else
//    {
//    	double f1,f2, f0, x0, a;
//    	f1 = func(x1);
//    	f2 = func(x2);
//    	f0 = func(f0);
//    	
//    	if(func(x1)*func(x2)<0)
//    	{
//    		x0 = (x1 + x2)/2;
//			
//			do{
//				a = x0;
//				if (func(x0)*func(x1)<0)
//				{
//					x2 = x0;
//					f2 = f0;
//				}
//				else{
//					x1 = x0;
//					f1 = f0;
//				}
//				
//				x0 = (x1 + x2) /2;
//			}while((x0-a)>=e)
//		}
//		cout<<"root is "<<x0;
//	}
//    cout << "The value of root is : " << x0 << endl;
//}
//
//int main() {
//    double x1, x2, e;
//
//    cout << "Enter your initial guesses: \n";
//    cout << "x1:  ";
//    cin >> x1;
//    cout << "x2:  ";
//    cin >> x2;
//    cout << "Margin of error (e):  ";
//    cin >> e;
//
//
//    bisection(x1, x2, e);
//
//    return 0;
//}






#include <iostream>
#include <cmath>

using namespace std;

double func(double x) {
    return x * x - 4 * x - 10;
}

void bisection(double x1, double x2, double e) {
    if (func(x1) * func(x2) >= 0) {
        cout << "You have not assumed the correct initial guesses (x1 and x2)\n";
        return;
    } 
	else {
        double x0;  // declare midpoint outside the loop
        double a;   // to store previous midpoint for convergence check
        
        // initial midpoint
        x0 = (x1 + x2) / 2.0;
        double f0 = func(x0);
        
        do {
            a = x0;
            f0 = func(x0);
            // Update the interval based on the sign of the function at x0
            if (func(x1) * f0 < 0)
                x2 = x0;
            else
                x1 = x0;
            
            x0 = (x1 + x2) / 2.0;  // compute new midpoint
        } while (fabs(x0 - a) >= e);  // check if the change is greater than error margin
        
        cout << "The value of the root is: " << x0 << endl;
    }
}

int main() {
    double x1, x2, e;

    cout << "Enter your initial guesses: \n";
    cout << "x1:  ";
    cin >> x1;
    cout << "x2:  ";
    cin >> x2;
    cout << "Margin of error (e):  ";
    cin >> e;

    bisection(x1, x2, e);

    return 0;
}

