#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
using namespace std;

int main() {
    string input;
    float num1, num2;
    int choice;

    do {
        system("cls");  // For Windows (use "clear" on Linux/Mac)

        cout << "--- Scientific Calculator ---" << endl;
        cout << "Choose an operation by number:\n" << endl;
        cout << "  1. Addition (+)" << endl;
        cout << "  2. Subtraction (-)" << endl;
        cout << "  3. Multiplication (*)" << endl;
        cout << "  4. Division (/)" << endl;
        cout << "  5. Percentage (%)" << endl;
        cout << "  6. Square (x²)" << endl;
        cout << "  7. Square Root (√x)" << endl;
        cout << "  8. Inverse (1/x)" << endl;
        cout << "  9. Exit" << endl;
        cout << "Type 'CL' anytime to clear.\n" << endl;

        // Step 1: Choose Operation
        cout << "Enter operation number (1-9): ";
        cin >> input;
        if (input == "CL" || input == "cl") continue;

        try {
            choice = stoi(input);
        } catch(...) {
            cout << "Invalid choice. Try again." << endl;
            continue;
        }

        // Step 2: Exit
        if (choice == 9) {
            cout << "\nThank you for using the calculator!" << endl;
            break;
        }

        // Step 3: Unary Operations
        if (choice >= 6 && choice <= 8) {
            cout << "Enter number: ";
            cin >> input;
            if (input == "CL" || input == "cl") continue;

            try {
                num1 = stof(input);
            } catch(...) {
                cout << "Invalid input. Try again." << endl;
                continue;
            }

            switch (choice) {
                case 6: cout << "Result: " << num1 * num1 << endl; break;
                case 7:
                    if (num1 >= 0) cout << "Result: " << sqrt(num1) << endl;
                    else cout << "Error: Negative input for square root." << endl;
                    break;
                case 8:
                    if (num1 != 0) cout << "Result: " << 1 / num1 << endl;
                    else cout << "Error: Cannot divide by zero." << endl;
                    break;
            }
        }

        // Step 4: Binary Operations
        else if (choice >= 1 && choice <= 5) {
            cout << "Enter first number: ";
            cin >> input;
            if (input == "CL" || input == "cl") continue;
            try {
                num1 = stof(input);
            } catch(...) {
                cout << "Invalid input. Try again." << endl;
                continue;
            }

            cout << "Enter second number: ";
            cin >> input;
            if (input == "CL" || input == "cl") continue;
            try {
                num2 = stof(input);
            } catch(...) {
                cout << "Invalid input. Try again." << endl;
                continue;
            }

            switch (choice) {
                case 1: cout << "Result: " << num1 + num2 << endl; break;
                case 2: cout << "Result: " << num1 - num2 << endl; break;
                case 3: cout << "Result: " << num1 * num2 << endl; break;
                case 4:
                    if (num2 != 0) cout << "Result: " << num1 / num2 << endl;
                    else cout << "Error: Division by zero." << endl;
                    break;
                case 5: cout << "Result: " << (num1 / 100) * num2 << endl; break;
            }
        } else {
            cout << "Invalid choice. Please choose between 1 and 9." << endl;
        }

        // Pause before clearing screen
        cout << "\nPress Enter to continue...";
        cin.ignore();
        cin.get();

    } while (true);

    return 0;
}
