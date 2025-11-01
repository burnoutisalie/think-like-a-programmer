#include <iostream>
#include <string>
using namespace std;

int main() {
    int age = 25;
    double height = 1.72;
    char initial = 'K';
    string name = "Komiljon";
    bool likesProgramming = true;
    cout << "Age: " << age << endl;
    cout << "Height: " << height << "m" << endl;
    cout << "Initial: " << initial << endl;
    cout << "Name: " << name << endl;
    cout << "Likes programming: " << likesProgramming << endl;

    double num1, num2;
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;

    cout << "Sum: " << num1 + num2 << endl;
    cout << "Difference: " << num1 - num2 << endl;
    cout << "Product: " << num1 * num2 << endl;
    cout << "Quotient: " << num1 / num2 << endl;

    int a = 7, b = 3;
    cout << "Integer division 7/3: " << a / b << endl;
    cout << "Remainder 7%3: " << a % b << endl;

    return 0;
}
