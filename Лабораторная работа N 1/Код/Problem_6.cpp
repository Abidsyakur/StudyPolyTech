#include<iostream>
#include<cmath>
#include<math.h>
#include<stdlib.h>

using namespace std; 

double F(double x, double a){
    if ( x == 0 ){
        return NAN;
    }

    return sqrt( (pow(exp,a)) * cos(x));
}


int main(){
    double x0 ; 
    double x1 ; 
    double x ; 
    double a ; 
    double delta_x ; 

    cout << "Input x0 : " ;
    cin >> x0;

    cout << "Input x1 : " ;
    cin >> x1;

    cout << "Input delta_x : " ;
    cin >> delta_x;

    cout << "Input a : " ;
    cin >> a;

    cout  << "\nNo " << " | " << " x " << " | " << " a " << " | "  << " y "  << " | "  << endl;
    cout << "-----------------------------------------\n";

    int no = 1;

    for (x = x0 ; x <= x1; x += delta_x){
        double y = F(x,a);
        cout  << no++ << " | " ;
        cout << x << " | "; 
        cout  << a << " | ";

        if(isnan(y)){
            cout  <<  "error" << endl;
        }else {
            cout << y  << "\n" ;
        }
    }

}
