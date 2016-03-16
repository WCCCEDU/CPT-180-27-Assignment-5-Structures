#include <iostream>
#include <fstream>

//#include "./library.h"

const std::string CONFIG = "C:/Users/Tim/ClionProjects/Assignment_2_File_Generator/app.cfg";


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

        std::string first_and_last = "", email = "", cypher = "", timzone;

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
        std::getline(std::cin, timzone);


        while (timzone == "") {
            std::cout << "Please enter your timezone to continue" << std::endl;
            std::getline(std::cin, timzone);
        }
        myfile << timzone << std::endl;


        myfile.close();

    return void();
    }

void edit(){

    std::string new_path;
    std::cout << "Please enter the new file path." << std::endl;
    std::cin >> new_path;

    std::ofstream editfile;
    editfile.open(new_path);

    if(editfile) {

        std::string new_first_and_last = "", new_email = "", new_cypher = "", new_timzone;

        std::cout << "Enter your first and last name, please" << std::endl;
        std::getline(std::cin, new_first_and_last);

        while (new_first_and_last == "") {
            std::cout << "Please enter your first and last name to continue" << std::endl;
            std::getline(std::cin, new_first_and_last);
        }
        editfile << new_first_and_last << std::endl;

        std::cout << "Enter your email address, please" << std::endl;
        std::getline(std::cin, new_email);

        while (new_email == "") {
            std::cout << "Please enter your email to continue" << std::endl;
            std::getline(std::cin, new_email);
        }
        editfile << new_email << std::endl;

        std::cout << "Enter your unique cypher, please" << std::endl;
        std::getline(std::cin, new_cypher);

        while (new_cypher == "") {
            std::cout << "Please enter your unique cypher to continue" << std::endl;
            std::getline(std::cin, new_cypher);
        }
        editfile << new_cypher << std::endl;

        std::cout << "Enter your timezone offset, please" << std::endl;
        std::getline(std::cin, new_timzone);


        while (new_timzone == "") {
            std::cout << "Please enter your timezone to continue" << std::endl;
            std::getline(std::cin, new_timzone);
        }
        editfile << new_timzone << std::endl;

    }
    std::cout << "Something edited, blah blah blah" << std::endl;

    return void();
}
