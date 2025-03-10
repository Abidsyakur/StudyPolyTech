#include <iostream>
#include <cmath>

using namespace std;

struct RGB {
    double r, g, b;
};

struct HSL {
    double h, s, l;
};

void RGBtoHSL(const RGB& rgb, HSL& hsl) {
    double r = rgb.r / 255.0;
    double g = rgb.g / 255.0;
    double b = rgb.b / 255.0;

    hsl.l = (r + g + b) / 3.0;

    hsl.s = sqrt(r * r + g * g + b * b - b * g - b * r - g * r);

    if (hsl.s != 0) {
        hsl.h = asin(sqrt((3.0 / 2.0) * ((g - r) / hsl.s)));
        hsl.h = hsl.h * 180.0 / M_PI; 
    } else {
        hsl.h = 0; 
    }
}

int main() {
    RGB rgb;
    cout << "Input RGB (0-255):" << endl;
    cout << "R: ";
    cin >> rgb.r;
    cout << "G: ";
    cin >> rgb.g;
    cout << "B: "; 
    cin >> rgb.b;

    HSL hsl;
    RGBtoHSL(rgb, hsl);

    cout << "Result in HSL:\n";
    cout << "H: " << hsl.h << " graducov\n";
    cout << "S: " << hsl.s  * 100 << " percent\n";
    cout << "L: " << hsl.l * 100 << " percent\n";
    return 0;

}
