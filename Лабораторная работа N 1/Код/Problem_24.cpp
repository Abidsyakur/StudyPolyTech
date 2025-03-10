#include<iostream>
#include<cmath>
#include<math.h>

using namespace std;

double Fx(double x , double a){
    if ( x == 0 ){
        return NAN;
    }
   double xn = (1 - sqrt(a + tan(a + (x/3))));
   if (xn == 0 ){
    return NAN;
   }
     return 1/ xn ;
}

int main() {

    double a ; 
    double x0; 
    double x1;
    double delta_x;
    
    cout << "x0 : ";
    cin >>  x0 ; 

    cout << "x1 : ";
    cin>> x1;

    cout << " a : ";
    cin >> a;

    cout << "delta x : ";
    cin >> delta_x;

    cout  << "\nNo " << " | " << " x " << " | " << " a " << " | "  << " y "  << " | "  << endl;
    cout << "-----------------------------------------\n";          
    int no = 1;

    for(double x = x0 ; x <= x1 ; x += delta_x){
        double y = Fx(x,a);
        if ( a > 0){    
         cout  << no++ << " | " ;
        cout << x << " | "; 
        cout  << a << " | ";

        if(isnan(y)){
            cout  <<  "error 123123" << endl;
        }else {
            cout << y  << "\n" ;
        }
        }
    }
}