#ifndef UNTITLED_FUNCTIONS_H
#define UNTITLED_FUNCTIONS_H

struct Vector2D {
    double x;
    double y;
};

double operator*(Vector2D V1, Vector2D V2);
double angle(Vector2D V1, Vector2D V2);
bool isright(Vector2D V1, Vector2D V2);
double distance(Vector2D V1, Vector2D V2);

#endif //UNTITLED_FUNCTIONS_H
