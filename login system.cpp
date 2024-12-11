#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void registerUser() {
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ofstream file("users.txt", ios::app);
    if (file.is_open()) {
        file << username << " " << password << "\n";
        file.close();
        cout << "Registration successful!\n";
    } else {
        cout << "Error opening file for registration.\n";
    }
}

bool loginUser() {
    string username, password, storedUser, storedPass;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ifstream file("users.txt");
    if (file.is_open()) {
        while (file >> storedUser >> storedPass) {
            if (storedUser == username && storedPass == password) {
                file.close();
                return true;
            }
        }
        file.close();
    }
    return false;
}

int main() {
    int choice;
    cout << "1. Register\n2. Login\nEnter your choice: ";
    cin >> choice;

    switch (choice) {
    case 1:
        registerUser();
        break;
    case 2:
        if (loginUser()) {
            cout << "Login successful!\n";
        } else {
            cout << "Invalid username or password.\n";
        }
        break;
    default:
        cout << "Invalid choice.\n";
    }

    return 0;
}
