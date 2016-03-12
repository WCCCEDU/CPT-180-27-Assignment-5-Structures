namespace config {
    using std::string;


    struct config_settings {
        string name;
        string email_address;
        string cypher;
        string timezone;
        string known_recipients;
    };

    bool write_config(config_settings &settings, string config_file_path);

    config_settings read_config(string config_file_path);

    int linecount(string input_file_path);
}