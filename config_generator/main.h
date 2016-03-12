#include <string>
#include "./lib/config.h"

using config::config_settings;

using std::string;
int initialize_config(string config_file_path);
void prompt_for_values(config_settings &settings, bool edit_mode, string edit_setting = "none");