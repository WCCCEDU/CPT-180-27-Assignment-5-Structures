#ifndef LIBRARIES_READER_H
#define LIBRARIES_READER_H
#include <string>

namespace config_lib {
   using namespace std;

    struct config{

        std::string name = "";
        std::string email = "";
        std::string timezone_offset = "";
        std::string cypher = "";
        std::string file_path = "";
    };

    static config read_config(string config_file_path);
    static bool write_config(string config_file_path, config write);



}
#endif //LIBRARIES_READER_H
