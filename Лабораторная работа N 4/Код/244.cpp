#include <iostream>
#include <cmath>  
#include <iomanip> 

using namespace std; 

double fx(double x, double tocnost) {
    double sum = 0; 
    double term = 1; 
    int n = 0;

    while (fabs(term) > tocnost && n < 10000) {
        sum += term; 
        n++;
        term *= (-1.0 * (3 * x) * (3 * x)) / ((2 * n - 1) * (2 * n)); 
    }

    return x * sum; 
}

void print_table_1(double x_start, double x_end, double step, double tocnost) {
    cout << "-------------------------------------------------------------\n";
    cout << "|     x     |   f(x)           |   F(x)           |   Delta (|f(x) - F(x)|)   |\n";
    cout << "-------------------------------------------------------------\n";

    for (double x = x_start; x <= x_end; x += step) {
        double znacenine_ryada = fx(x, tocnost);  
        double biblioteka_znacenie = x * cos(3 * x); 
        double delta = sqrt(fabs(pow(znacenine_ryada, 2) - pow(biblioteka_znacenie, 2)));
        
        cout << "| " << setw(7) << x 
             << " | " << setw(15) << znacenine_ryada
             << " | " << setw(15) << biblioteka_znacenie 
             << " | " << setw(24) << delta << " |\n";
    }
    
    cout << "-------------------------------------------------------------\n";
}

void print_table_2(double x_ideal) {
    cout << "-------------------------------------------------------------\n";
    cout << "|   epsilon   |   f(x_ideal)    |   F(x_ideal)    |   Delta (|f(x) - F(x)|)   |\n";
    cout << "-------------------------------------------------------------\n";
    
    double epsilons[] = {0.1, 0.01, 0.001, 0.0001, 0.000001}; 
    
    for (double epsilon : epsilons) {
        double znacenine_ryada = fx(x_ideal, epsilon);
        double biblioteka_znacenie = x_ideal * cos(3 * x_ideal);
        double delta = sqrt(fabs(pow(znacenine_ryada, 2) - pow(biblioteka_znacenie, 2)));
        
        cout << "| " << setw(10) << epsilon 
             << " | " << setw(15) << znacenine_ryada
             << " | " << setw(15) << biblioteka_znacenie
             << " | " << setw(24) << delta << " |\n";
    }
    
    cout << "-------------------------------------------------------------\n";
}

int main() {
    double x_start, x_end, step, tocnost, x_ideal;

    cout << "input x_start: ";
    cin >> x_start;
    cout << "input x_end: ";
    cin >> x_end;
    cout << "input step: ";
    cin >> step;
    cout << "input epsilon : ";
    cin >> tocnost;

    print_table_1(x_start, x_end, step, tocnost);

    cout << "\ninput x_ideal: ";
    cin >> x_ideal;
    
    print_table_2(x_ideal);

    return 0;
}