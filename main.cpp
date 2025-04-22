#include <iostream>
#include <limits>

using namespace std;
// Declaration of the functions from other files 
void greet();
void login();
void createAccount();

int getUserinput();
void mainMenuSelection(int choice);

int main() {
    greet();  // Print App Welcome message and user options
    int menuChoice = getUserinput(); 
    mainMenuSelection(menuChoice);
}

//Get input from the user (menu choice)
int getUserinput(){
    int x = 0;
    cout << "         Enter an 1 or 2: ";
    cin >> x;
    // check and see if the input is correct
    if (cin.fail() || x <  1 || x > 2) {
        cout << "       ********Invalid Choice*********" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return 0;
    }
    return x;
}

//MenuSelection
void mainMenuSelection(int choice){
    if (choice == 1){
        login();
    }
    else if (choice == 2){
        createAccount();
    }
    else if (choice == 0){
        int choice = getUserinput();
        mainMenuSelection(choice);
    }
}

