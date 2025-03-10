#include<iostream>
#include<cmath>
#include<math.h>
#include<stdlib.h>
#include<iomanip>

using  namespace std ;

//External function
double F(double x, double a){
    if(x == 0){
        return NAN;
    }
    return 0.7 /( (1.0/x) + (sin(x)/a) );  //это функция
}

int main(){

    // double x0 = -14; 
    // double x1 =  11 ;
    // double delta_x = 2.5;
    // double a = 1.0 ;

    double x0 ;
    double x1 ; 
    double delta_x ; 
    double a ; 

    cout << "Input x0 : ";
    cin >> x0 ; 
    cout << "Input x1 : ";
    cin >> x1 ; 
    cout << "Input delta x :" ;
    cin >> delta_x ; 
    cout << "Input a : " ;
    cin >> a ; 
    cout  << "\nNo " << " | " << " x " << " | " << " a " << " | "  << " y "  << " | "  << endl;
    cout << "-----------------------------------------\n";

    int no = 1;

    for(double x = x0 ; x <= x1 ; x += delta_x){
        double y = F(x,a);
        cout  << no++ << " | " ;
        cout << x << " | "; 
        cout  << a << " | ";

        if(isnan(y)){
            cout  <<  "error" << endl;
        }else {
            cout << y  << "\n" ;
        }
    
    }}