#include <iostream>
using namespace std;

bool isPalindrome(int num) {
    int original = num;
    int reversed = 0;

    while (num > 0) {
        int digit = num % 10;          // get last digit
        reversed = reversed * 10 + digit; // build reversed number
        num /= 10;                     // remove last digit
    }

    return original == reversed;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    if (isPalindrome(n))
        cout << n << " is a palindrome number." << endl;
    else
        cout << n << " is not a palindrome number." << endl;

    return 0;
}
