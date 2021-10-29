#include <cmath>
#include "functions.h"

double operator*(Vector2D V1, Vector2D V2){
    double s = V1.x*V2.x + V1.y*V2.y;
    return s;
}

double angle(Vector2D V1, Vector2D V2){
    double angle = acos((V1 * V2)/(sqrt(V1*V1) * sqrt(V2*V2)));
    return angle;
}

bool isright(Vector2D V1, Vector2D V2) {
    double a = V1.x;
    double b = V1.y;
    double x0 = V2.x;
    double y0 = V2.y;
    double h;

    if (a != 0) {
        h = -(y0 - b / a * x0);
    }
    else {
        if (b > 0) h = x0;
        else h = -x0;
    }
    //cout << "h = " << h << endl;

    if (a >= 0) {
        if (h >= 0) return true;
        else return false;
    }
    else {
        if (h > 0) return false;
        else return true;
    }
}

double distance(Vector2D V1, Vector2D V2) {
    double a = V1.x;
    double b = V1.y;
    double x0 = V2.x;
    double y0 = V2.y;
    double h;

    if (b == 0 and a != 0) {
        h = abs(y0);
    }
    else if (a == 0 and b != 0){
        h = abs(x0);
    }
    else h = abs(b * x0 - a * y0) / sqrt(a * a + b * b);

    return h;
}
