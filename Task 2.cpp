#include <iostream>

using namespace std;

int main() {
    char operation;
    double num1, num2, result;

    cout << "Enter an operator (+, -, *, /): ";
    cin >> operation;

    cout << "Enter number 1: ";
    cin >> num1;
    
    cout << "Enter number 2: ";
    cin >> num1;

    switch (operation) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if (num2 == 0) {
                cout << "Error! Division by zero is not allowed." << endl;
                return 1; 
            }
            result = num1 / num2;
            break;
        default:
            cout << "Invalid operator. Please use +, -, *, or /." << endl;
            return 1; 
    }

    cout << "Answer is: " << result << endl;
    
    return 0;
}