#include <iostream>
using namespace std;

int main() {
    // cout << "Hello world!" << endl;

    int a;
    cin >> a;
    // cout << "You entered: " << a << endl;

    if (a > 0) {
        cout << "The number is positive." << endl;
    } else if (a < 0) {
        cout << "The number is negative." << endl;
    } else {
        cout << "The number is zero." << endl;
    }
    
    return 0;
}