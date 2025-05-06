#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;


string saltNew;
string hashNew;

void createAccountPrompts(int i);
string hashPasswordWithSalt(const std::string& password, const std::string& salt);
string generateSalt(size_t length = 16);

bool checkUserExists(string username);
void createPassword(string user);

void createAccount(){
    createAccountPrompts(1);
    string username;
    cin >> username;
    
    bool newUsername = checkUserExists(username);
    
    if (newUsername == false){
        createPassword(username);
    }
    else{
        cout << " \n This user name already exists!\n";
        createAccount();
    }
}

void createPassword(string  user){
    createAccountPrompts(2);
    string password;
    cin >> password;
    
}

bool checkPasswordFormat(string password){
    if (password.length() > 7 || password.length() < 16){
        return false;
    }
    bool uppercase, lowercase, number = false;
    for(int i = 0; i < password.length(); i++){
        if(password[i] > 64 && password[i] < 91){
            uppercase = true;
        }
        if(password[i] > 96 && password[i] < 123){
            lowercase = true;
        }
        if(password[i] > 47 && password[i] < 58){
            number = true;
        }
    }
    if(uppercase && lowercase && number){
        return true;
    }
    return false;
}

bool checkUserExists(string username){
    
    string input;
    ifstream MyReadFile("../Users.txt");
   
    while (getline (MyReadFile, input)) {

        stringstream ss(input);
        string item;
        vector<string> columns;

        while (getline(ss, item, ',')) {
           columns.push_back(item);
        }
        // Check if row has at least 3 columns and the first one matches
        if (columns[0] == username) {
            MyReadFile.close();
            return true;
        }
        if (columns[0] == ""){
            break;
        }
    }   
    // Close the file
    MyReadFile.close();
    return false;
}