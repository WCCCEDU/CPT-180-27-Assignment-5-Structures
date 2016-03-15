#include "structures_header.h"
// Project should read the Config into the struct then Output the Struct to the file
int main() {
    string selection = "";
    cout << "What would you like to do? Create , Edit , or Read :";
    cin >> selection;
    if (selection == "Create")
    {
        writeConfig("C:\\Users\\Hanko\\Documents\\C++ Files\\Assignment3\\config.txt" , create_config());
    }else if (selection == "Edit")
    {
        writeConfig("C:\\Users\\Hanko\\Documents\\C++ Files\\Assignment3\\config.txt" ,
                    edit_config("C:\\Users\\Hanko\\Documents\\C++ Files\\Assignment3\\config.txt", selection));
    }else if (selection == "Read")
    {
        writeConfig("C:\\Users\\Hanko\\Documents\\C++ Files\\Assignment3\\config.txt" ,
                    read_config("C:\\Users\\Hanko\\Documents\\C++ Files\\Assignment3\\config1.txt"));
    }

    return 0;
}
int size_finder(string path)
{
    int count = 0;
    string line;
    fstream myFile(path);
    while(getline(myFile,line))
    {
        count++;
    }
    return count;
}
configStruct read_config(string config_file_path) {
    configStruct info;
    int const SIZE = size_finder(config_file_path) + 1;
    fstream file(config_file_path);
    if (file.is_open()) {
        string myArray[SIZE];
        cout <<"Config Read\n";
        for (int i = 0; i < SIZE; ++i) {
            file >> myArray[i];
        }
        info.first_name = myArray[0];
        info.last_name = myArray[1];
        info.email = myArray[2];
        info.password = myArray[3];
        info.timezone = myArray[4];

return info;
    }
}

configStruct create_config() {
    configStruct create;

        cout <<"Create Config\n";
        cout << "Enter your first name , Last name email , password , and timezone ; Hit Enter after each input :";
        for (int i = 0; i < 5; ++i) {
           if (i == 0)
           {
               cout <<"Enter yor first name : \n";
               std::cin >>create.first_name;
           }else if (i == 1)
            {
                cout <<"Enter your Last name : \n";
                std::cin >> create.last_name;
            }else if (i == 2)
           {
               cout <<"Enter your Email : \n";
               std::cin >> create.email;
           }else if (i == 3)
           {
               cout <<"Enter your Passcode : \n";
               std::cin >> create.password;
           }else
           {
               cout <<"Enter your timezone : \n";
               std::cin >>create.timezone;
           }

        }
        return create;

}
configStruct edit_config(string f , string choice) {
    configStruct edit;
    fstream file(f);
    string selection = "";
    cout <<"edit Config\n";
    if(file.is_open()){
    if(choice == "Edit")
    {
        cout <<"What would you like to Edit: \n";
        std::cin >>selection;
        while (selection != "Done") {
        if (selection == "First Name")
        {
            cout <<"Enter your first name : \n";
            std::cin >>edit.first_name;
        }else if (selection == "Last Name")
        {
            cout <<"Enter your Last name : \n";
            std::cin >> edit.last_name;
        }else if (selection == "Email")
        {
            cout <<"Enter your Email : \n";
            std::cin >> edit.email;
        }else if (selection == "Passcode")
        {
            cout <<"Enter your Passcode : \n";
            std::cin >> edit.password;
        }else if (selection == "Timezone")
        {
            cout <<"Enter your timezone : \n";
            std::cin >>edit.timezone;
        }

    }
    }
    }
    return edit;

}

bool writeConfig(string path , configStruct data)
{
    fstream file(path);
    if(!file)
    {
        cout <<"File Didn't Work\n";
        return false;
    }else{
        cout <<"Struct Output to file\n";
        file << data.first_name << '\n' << data.last_name << '\n' << data.email << '\n' << data.password << '\n' << data.timezone;
        file.close();
        return true;

    }
}

