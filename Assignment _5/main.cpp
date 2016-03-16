#include <iostream>
#include <fstream>

//#include './library.h"

const std::string CONFIG = "C:/Users/Tim/ClionProjects/Assignment_2_File_Generator/config.txt";
const std::string EDIT = "C:/Users/Tim/ClionProjects/Assignment_2_File_Generator/edit.txt";

void init();
void edit();


int main(int argc, char *argv[]) {

    if (static_cast<std::string>(argv[1]) == "init"){
        init();

    }

    else if (static_cast<std::string>(argv[1]) == "edit"){
        edit();

    }
return 0;
}
void init(){

        std::ofstream myfile;
        myfile.open(CONFIG);

        std::string first_and_last = "", email = "", cypher = "", timezone;

        std::cout << "Enter your first and last name, please" << std::endl;
        std::getline(std::cin, first_and_last);

        while (first_and_last == "") {
            std::cout << "Please enter your first and last name to continue" << std::endl;
            std::getline(std::cin, first_and_last);
        }
        myfile << first_and_last << std::endl;

        std::cout << "Enter your email address, please" << std::endl;
        std::getline(std::cin, email);

        while (email == "") {
            std::cout << "Please enter your email to continue" << std::endl;
            std::getline(std::cin, email);
        }
        myfile << email << std::endl;

        std::cout << "Enter your unique cypher, please" << std::endl;
        std::getline(std::cin, cypher);

        while (cypher == "") {
            std::cout << "Please enter your unique cypher to continue" << std::endl;
            std::getline(std::cin, cypher);
        }
        myfile << cypher << std::endl;

        std::cout << "Enter your timezone offset, please" << std::endl;
        std::getline(std::cin, timezone);


        while (timezone == "") {
            std::cout << "Please enter your timezone to continue" << std::endl;
            std::getline(std::cin, timezone);
        }
        myfile << timezone << std::endl;


        myfile.close();

    return void();
    }

void edit(){

    std::cout << "Something edited, blah blah blah" << std::endl;

    return void();
}
