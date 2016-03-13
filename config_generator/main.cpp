#include <iostream>
#include <fstream>
#include "./config.h"


using std::cin;
using std::cout;
using std::endl;
using std::string;

const string CONFIG_FILE_PATH = "/users/outla/Documents/WCCC/Semester 4/CPT-180/Assignment2/app.cfg";
const string BLANK = "";


void init() {

    string name;
    do{
        cout << "Please Enter Your Name (First and Last)" << endl;
        getline(cin, name);
    }while(name == BLANK);
    if(name == BLANK) {
        cout << "You Must Enter a Name" << endl;
    }

    string email;
    if(email == BLANK){
        cout << " Please Enter Your Email Address" << endl;
        getline(cin, email);
    }else{
        cout << "You Must Enter an Email Address" << endl;
    }

    string cypher;
    if(cypher == BLANK){
        cout << "Please Enter Your Unique Cypher" << endl;
        getline(cin, cypher);
    }else{
        cout << "You Must Enter a Cypher" << endl;
    }

    string timezone_offset;
    if(timezone_offset == BLANK){
        cout << "Please Enter Your Timezone Offset" << endl;
        getline(cin, timezone_offset);
    }else{
        cout << "You Must Enter an Offset" << endl;
    }

    string file_path;
    if(file_path == BLANK){
        cout << "Please Enter the Recipient's File Path" << endl;
        getline(cin, file_path);
    }else{
        cout << "You Must Enter a File Path" << endl;
    }

    Config input;
    input.name = name;
    input.email = email;
    input.cypher = cypher;
    input.file_path = file_path;
    input. timezone_offset = timezone_offset;

    std::ofstream init_output_file;
    init_output_file.open(file_path);

    init_output_file << input.name << endl;
    init_output_file << input.email << endl;
    init_output_file << input.cypher << endl;
    init_output_file << input.timezone_offset << endl;
    init_output_file << input.file_path << endl;
    init_output_file.close();
    }

void edit(){
    bool file = true;
    string edit_path;
    string entered;
    cout << "Enter Path for the Recipient" << endl;
    cin >> edit_path;
    cout << "Enter Name,Email,Cypher,Timezone for what you want to edit";
    cin >> entered;


    std::ifstream edited_file;
    string name_edit;
    string email_edit;
    string cypher_edit;
    string timezone_edit;
    edited_file.open(edit_path);

    if (edited_file) {

        if(entered == "Name") {
            name_edit = BLANK;
            if (name_edit == BLANK) {
                cout << "Please Enter Your Name (First and Last)" << endl;
                getline(cin, name_edit);
                edited_file >> name_edit;
            } else {
                cout << "You Must Enter a Name" << endl;
            }
        } else if(entered == "Email"){
            email_edit = BLANK;
        if(email_edit == BLANK){
            cout << " Please Enter Your Email Address" << endl;
            getline(cin, email_edit);
            edited_file >> email_edit;
        }else{
            cout << "You Must Enter an Email Address" << endl;
        }
            }else if(entered == "Cypher") {
            cypher_edit = BLANK;
            if (cypher_edit == BLANK) {
                cout << "Please Enter Your Unique Cypher" << endl;
                getline(cin, cypher_edit);
                edited_file >> cypher_edit;
            } else {
                cout << "You Must Enter a Cypher" << endl;
            }
        }else if(entered == "Timezone") {
            timezone_edit = BLANK;
            if (timezone_edit == BLANK) {
                cout << "Please Enter Your Timezone Offset)" << endl;
                getline(cin, timezone_edit);
                edited_file >> timezone_edit;
            } else {
                cout << "You Must Enter an Offset" << endl;
            }
            edited_file.close();
        }else{
            cout << "You did not enter the right word";
        }
    } else{
          file= false;
        cout << "No File Found" << endl;
        }

    if(file){
        std::ofstream output_edited_file;
        output_edited_file.close();


        Config input;
        input.name = name_edit;
        input.email = email_edit;
        input.cypher = cypher_edit;
        input. timezone_offset = timezone_edit;


        output_edited_file << input.name << endl;
        output_edited_file << input.email << endl;
        output_edited_file << input.cypher << endl;
        output_edited_file << input.timezone_offset << endl;

        output_edited_file.close();
    }else{
        cout << " Please Find the Correct File Path" << endl;
    }
    }



int main(int argc, char *argv[]) {

    int option;
    cout << "Please Enter Option" << endl;
    cout << "1. Load File" << endl;
    cout << "2. Edit File" << endl;
    cin >> option;
    cin.ignore();

    if (option == 1){
        init();
    } else if(option == 2){
        edit();
    }else ( option > 2 or option < 1);{
        cout << "Please Enter 1 or 2" << endl;
    }
    return 0;
}

