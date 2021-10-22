#include <iostream>

using namespace std;

int fact(int N){
    if  (N == 1)
        return 1;
    return N * fact(N-1);
}

int main() {
    cout << "Calculating a factorial\n"
        << "Input a number:";
    int a;
    cin >> a;
    if (a != 0) {
        cout << a << "!=" << fact(a) << endl;
    }
    else
        cout << "1\n";
    return 0;
}
