#include <fstream>
#include <iostream>
#include <cmath>
#include <stdlib.h>

int main() {
    std::ifstream infile("in.txt");

    int x, y;
    int xl = 0, xr = 0, yl = 0, yr = 0;

    double _cos_r, _cos_l;
    _cos_l = 1; _cos_r = 1;

    int x0, y0;
    infile >> x0 >> y0;

    while (infile >> x >> y) {
        double cos = (x0*x+y0*y) / (sqrt(x*x+y*y)*sqrt(x0*x0+y0*y0));
        cos = std::round(cos * 10000000000.0) / 10000000000.0;
        
        if (cos <= _cos_l && (y0*x < x0*y)){
            _cos_l = cos;
            xl = x; yl = y;
        }

        else {
            _cos_r = cos;
            xr = x; yr = y;
        }
    }
    std::cout << "Leftmost: " << xl << " " << yl << "\n";
    std::cout << "Rightmost: " << xr << " " << yr << "\n";
}
