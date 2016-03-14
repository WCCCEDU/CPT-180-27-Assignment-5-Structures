#include "./config.h"



const string blank = "";

int main(int argc, char *argv[]) {
    config user_config;

    user_config.first_name;
    do {
        std::cout << "Enter Your First Name" << std::endl;
        getline(cin, user_config.first_name);
    } while (user_config.first_name == blank);

    user_config.last_name;
    do { std::cout << "Enter Your Last Name" << std::endl;
        getline(cin, user_config.last_name);
    } while (user_config.last_name == blank);

    user_config.email;
    do {
        std::cout << "Enter Your Email Address" << std::endl;
        getline(cin, user_config.email);
    } while (user_config.email == blank);

    user_config.cypher;
    do {
        std::cout << "Enter Your Cypher" << std::endl;
        getline(cin, user_config.cypher);
    } while (user_config.cypher == blank);

    user_config.timezone;
    do {
        std::cout << "Enter your Timezone " << std::endl;
        getline(cin, user_config.timezone);
    } while (user_config.timezone == blank);

    user_config.file_path;
    do {
        std::cout << "Enter Recipient's File Path" << std::endl;
        getline(cin, user_config.file_path);
    } while (user_config.file_path == blank);

    std::ofstream init_output_file;
    init_output_file.open(user_config.file_path);

    init_output_file << user_config.first_name << endl;
    init_output_file << user_config.last_name << endl;
    init_output_file << user_config.email << endl;
    init_output_file << user_config.cypher << endl;
    init_output_file << user_config.timezone<< endl;
    init_output_file << user_config.file_path << endl;
    init_output_file.close();
}






