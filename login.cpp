#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;
string salt;
string pass; 

void requestUsername();
void requestPassword();
void accessDenied();
string hashPasswordWithSalt(const std::string& password, const std::string& salt);

bool checkIfUserExists(string username);



void login(){
    requestUsername();
    string username;
    cin >> username;
    bool doesUserExist = checkIfUserExists(username);

    if (doesUserExist == true){
        requestPassword();
        string password;
        cin >> password;  
        string test = hashPasswordWithSalt(password,salt);
        if (test == pass){
            cout << "  PASSWORD CORRECT!!\n";
        }
        else{
            cout << "  WRONG!!\n";
        }
    }
    if(doesUserExist == false){
        accessDenied();
    }
}

bool checkIfUserExists(string username){
    
    string input;
    ifstream MyReadFile("../Users.txt");
   
    while (getline (MyReadFile, input)) {

        stringstream ss(input);
        string item;
        vector<string> columns;

        while (std::getline(ss, item, ',')) {
            columns.push_back(item);
        }
        cout << columns[0] << ":\n";
        // Check if row has at least 3 columns and the first one matches
        if (columns[0] == username) {
            salt = columns[1];
            pass = columns[2];
            MyReadFile.close();
            return true;
        }       
    }   
    // Close the file
    MyReadFile.close();
    return false;
}



