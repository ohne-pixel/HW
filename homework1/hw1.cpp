#include <fstream>
#include <iostream>
#include "functions.h"

using namespace std;

int main() {
    string file_name = "in.txt";
    int Variant = 2;

    char *str = new char [1024];
    int l=0;
    ifstream base(file_name);
    while (!base.eof()){
        base.getline(str, 1024, '\n');
        l++;
    }
    base.close();

    ifstream file(file_name); // создание объекта класса ifstream
    Vector2D Vectors[l];
    int i = 0;
    for (i = 0; i < l; i++){
        file >> Vectors[i].x >> Vectors[i].y;
        //cout << Vectors[i].x << " " << Vectors[i].y << endl;
    }

    Vector2D MVector = Vectors[0];
    Vector2D Leftmost, Rightmost;
    double rightangle, leftangle, anglee;
    rightangle = leftangle = 0;

    double distancee, rightdistance, leftdistance;
    rightdistance = leftdistance = 1;
    //bool flag;

    if (Variant == 1) {
        for (i = 1; i < l; i++) {
            //cout << Vectors[i].x << " " << Vectors[i].y << endl;
            //flag = (isright(MVector, Vectors[i]));
            //cout << "flag " << flag << endl;
            //cout << Vectors[i].x << " " << Vectors[i].y << " h = " << distance(MVector, Vectors[i]) << endl;
            anglee = angle(MVector, Vectors[i]);
            //cout << anglee << endl;
            if (isright(MVector, Vectors[i])) {
                if (anglee > rightangle) {
                    Rightmost = Vectors[i];
                    //cout << "Rx Ry " << Rightmost.x << " " << Rightmost.y << endl;
                    rightangle = anglee;
                }
            } else {
                if (anglee > leftangle) {
                    Leftmost = Vectors[i];
                    //cout << "Lx Ly " << Leftmost.x << " " << Leftmost.y << endl;
                    leftangle = anglee;
                }
            }
        }
    } else {
        for (i = 1; i < l; i++) {
            distancee = distance(MVector, Vectors[i]);
            if (isright(MVector, Vectors[i])) {
                if (distancee > rightdistance) {
                    Rightmost = Vectors[i];
                    rightdistance = distancee;
                }
            } else {
                if (distancee > leftdistance) {
                    Leftmost = Vectors[i];
                    leftdistance = distancee;
                }
            }
        }
    }
    cout << "Leftmost " << Leftmost.x << " " << Leftmost.y << endl;
    cout << "Rightmost " << Rightmost.x << " " << Rightmost.y << endl;
}
