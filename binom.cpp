#include <iostream>

using namespace std;

int fact(int n){
    return (n==0)?1:(n==1)?1:n*fact(n-1);
}

int main() {
    int n,m;
    cout << "Input n:";
    cin >> n;
    cout << "Input m:";
    cin >> m;
    if (m > n){
        cout << "Achtung! m and/or n are wrong.";
        return 0;
    }
    cout << fact(n)/(fact(n-m)*fact(m));
    return 0;
}
