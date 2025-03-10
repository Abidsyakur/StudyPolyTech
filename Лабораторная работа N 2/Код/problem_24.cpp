#include <iostream>
#include <cmath>

using namespace std;

struct RGB {
    float r, g, b;
};

struct HLS {
    float h, l, s;
};

void RGBtoHLS(const RGB& rgb, HLS& hls) {

    float r = rgb.r / 255.0;
    float g = rgb.g / 255.0;
    float b = rgb.b / 255.0;

    hls.l = (r + g + b) / 3.0;

    hls.s = sqrt(r * r + g * g + b * b - b * g - b * r - g * r);

    if (hls.s != 0) {
        hls.h = asin(sqrt((3.0 / 2.0) * ((g - r) / hls.s)));
        hls.h = hls.h * 180.0 / M_PI; 
        hls.h = 0; 
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

    HLS hls;
    RGBtoHLS(rgb, hls);

    cout << "Result in HLS:\n";
    cout << "H: " << hls.h << "\n";
    cout << "L: " << hls.l << "\n";
    cout << "S: " << hls.s << "\n";

    return 0;
}
