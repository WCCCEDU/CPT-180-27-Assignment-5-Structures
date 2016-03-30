#include <fstream>
#include <iostream>
#include <fstream>

namespace configio {
  using std::string;
  using std::cout;
  using std::ifstream;
  using std::ofstream;
  using std::endl;

  struct ConfigFile {
    string first_name;
    string email;
    string cypher;
    string timezone;
    string filepath;
  };

  ConfigFile* read_config(string config_file_path);

  bool write_config(string path, ConfigFile Config);

  int line_count(string file_path);
}





