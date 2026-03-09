#include<iostream>
using namespace std;    

int main(){
    int a, b, c,temp;
    cout << "Enter three numbers: ";
    cin >> a >> b >> c;

    // Swapping using a temporary variable
    temp = a;
    a = b;
    b = temp;
    temp = a;
    a = c;
    c = temp;
     

    cout << "After swapping : " << endl;
    cout << "First number: " << a << endl;
    cout << "Second number: " << b << endl;
    cout << "Third number: " << c << endl;


    // Swapping without using a temporary variable
    a = a + b;
    b = a - b;
    a = a - b; 
    c = a - b;
    a = a - c;
    b = b - c;

    cout << "After swapping : " << endl;
    cout << "First number: " << a << endl;
    cout << "Second number: " << b << endl;
    cout << "Third number: " << c << endl;
    return 0;
}