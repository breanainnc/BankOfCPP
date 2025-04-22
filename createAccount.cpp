#include <iostream>

using namespace std;

string user;
string salt;
string hash;

void createAccountPrompts(int i);

bool checkUserExists(string username);
void createPassword();

void createAccount(){
    createAccountPrompts(1);
    string username;
    cin >> username;
    bool newUsername = checkUserExists(username);
    if (newUsername == true){
        user = username;
        createpassword();
    }
    else{
        createAccountPrompts(0);
    }


}

void createPassword(){
    createAccountPrompts(2);
}

bool checkUserExists(string username){
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
            
            return false;
        }   
    }   

    // Close the file
    MyReadFile.close();
    return true;
}