#include <iostream>
/*Console printer: functions that print various output to the console*/
void greet() {
    for(int i = 0; i < 50; i++){
        std::cout << "" << std::endl;
    }
    std::cout << "      Hello, Welome to the bank!" << std::endl;
    std::cout << "      ******************************************" << std::endl;
    std::cout << "      Please Choose one of the following options" << std::endl;
    std::cout << "      ******************************************" << std::endl;
    std::cout << "          1 - \"Log In\"" << std::endl;
    std::cout << "          2 - \"Create Account\"" << std::endl;
    
    std::cout << "       *****************************************" << std::endl;

}

void requestUsername() {
    std::cout << "      ******************************************" << std::endl;
    std::cout << "      Please Enter Your Username: " ;

}
void requestPassword() {

    std::cout << "      ******************************************" << std::endl;
    std::cout << "      Please Enter Your Password: " ;

}

void accessDenied() {
   
    std::cout << "      ******************************************" << std::endl;
    std::cout << "      ******WE HAVE NO USER WITH THAT NAME****** " << std::endl; 
    std::cout << "      ******************************************" << std::endl;
    std::cout << "      ------------------------------------------" << std::endl;
}