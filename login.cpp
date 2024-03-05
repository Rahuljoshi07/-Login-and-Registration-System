#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

struct User {
    string username;
    string password;
};

void registerUser() {
    ofstream file("users.txt", ios::app);
    User user;
    
    cout << "Enter username: ";
    cin >> user.username;
    cout << "Enter password: ";
    cin >> user.password;
    
    file << user.username << " " << user.password << endl;
    file.close();
    
    cout << "Registration successful!" << endl;
}

bool authenticateUser(string username, string password) {
    ifstream file("users.txt");
    string storedUsername, storedPassword;
    
    while (file >> storedUsername >> storedPassword) {
        if (storedUsername == username && storedPassword == password) {
            file.close();
            return true;
        }
    }
    
    file.close();
    return false;
}

int main() {
    int choice;
    string username, password;
    
    while (true) {
        cout << "1. Register\n2. Login\n3. Exit\nEnter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                cout << "Enter username: ";
                cin >> username;
                cout << "Enter password: ";
                cin >> password;
                
                if (authenticateUser(username, password)) {
                    cout << "Login successful!" << endl;
                } else {
                    cout << "Invalid username or password!" << endl;
                }
                break;
            case 3:
                exit(0);
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }
    
    return 0;
}
