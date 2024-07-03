#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>

#if _WIN32
#include "_color.hpp"
using namespace colorwin;
#else
#define color(...) ""
#endif

#include <filesystem>
using namespace std;
namespace fs = filesystem;

void Manual(const string& filename) {
  cout << color(yellow) << "[?] Usage: ";
  cout << filename << " [workspace folder] [output folder]\n";
  cout << "\t+) Task folder to generate must be in workspace folder (for "
          "example: Workspace/TASK/)\n";
#if _WIN32
  cout << "\t+) Solution binary file must be saved as: solution.exe\n";
  cout << "\t+) Generator binary file must be saved as: generator.exe\n";
#else
  cout << "\t+) Solution binary file must be saved as: ./solution\n";
  cout << "\t+) Generator binary file must be saved as: ./generator\n";
#endif
}

void Green() {
  cout << color(green) << "[+] ";
}

void Blue() {
  cout << color(blue) << "[*] ";
}

void execute(const string& s) {
  cout << "[ ] Executing: '";
  cout << color(yellow) << s;
  cout << "'...";
  int ret = system(s.c_str());
  if (ret) {
    cout << color(red) << "\n[-] Error occured! (Return code: " << ret << ")\n";
    exit(ret);
  }
  cout << color(green) << " Done!\n";
}

int main(int argc, char** argv) {
  if (argc == 1) {
    Manual(string(argv[0]));
    return EINVAL;
  }
  if (argc != 3) {
    cout << color(red) << "[-] Only accept 2 argument only!!!";
    cout << " (Argument count: " << argc << ")\n";
    Manual(string(argv[0]));
    return EINVAL;
  }

  vector<string> skipped;
  vector<string> success;

  try {
    string workspace_folder = string(argv[1]);
    if (!fs::exists(workspace_folder) || !fs::is_directory(workspace_folder)) {
      cout << color(red) << "[-] No workspace folder found!\n";
      return ENOENT;
    }
    const fs::path original_workspace{workspace_folder};

    for (auto const& entry : fs::directory_iterator{original_workspace}) {
      if (!fs::is_directory(entry))
        continue;
      string task_name = "";
      {
        string tmp{entry.path().u8string()};
#if _WIN32
        while (tmp.back() != '\\') {
#else
        while (tmp.back() != '/') {
#endif
          task_name += tmp.back();
          tmp.pop_back();
        }
      }
      reverse(task_name.begin(), task_name.end());

      cout << color(blue) << "[*] Parsed task name: ";
      cout << color(yellow) << task_name << '\n';
      string task_folder = string(argv[2]) + "/" + task_name;
      string workspace = original_workspace.string() + "/" + task_name;
      int test_cases = 20;

#if _WIN32
      if (!fs::exists(workspace + "/solution.exe")) {
#else
      if (!fs::exists(workspace + "/solution")) {
#endif
        cout << color(red)
             << "[-] Solution binary file (solution.exe) not found! Skipped "
                "task\n";
        skipped.push_back(task_name);
        continue;
      }
      Green();
      cout << "Solution binary file found!\n";
#if _WIN32
      if (!fs::exists(workspace + "/generator.exe")) {
#else
      if (!fs::exists(workspace + "/generator")) {
#endif
        cout << color(red)
             << "[-] Generator binary file (generator.exe) not found! Skipped "
                "task\n";
        skipped.push_back(task_name);
        continue;
      }
      Green();
      cout << "Generator binary file found!\n";

      cout << "[ ] Checking for '";
      cout << color(yellow) << task_folder;
      cout << "' directory...\n";
      if (fs::exists(task_folder) && fs::is_directory(task_folder)) {
        cout << "[ ] Directory '";
        cout << color(yellow) << task_folder;
        cout << "' found!\n";
        cout << "[ ] Attemping delete...\n";  // bro this is unsafe as fuck
        int files = fs::remove_all(task_folder);
        Green();
        cout << "Successfully deleted " << files << " files!\n";
      } else {
        Green();
        cout << "No directory found!\n";
      }
      cout << "[ ] Creating '";
      cout << color(yellow) << task_folder;
      cout << "' directory!\n";
      fs::create_directories(task_folder);
      Green();
      cout << "Directory created!\n";

      int test_size = to_string(test_cases).size();
      for (int test = 1; test <= test_cases; ++test) {
        string teststr = to_string(test);
        while ((int)teststr.size() != test_size) {
          teststr = "0" + teststr;
        }
        string folder = task_folder + "/Test" + teststr;
        cout << color(blue) << "[*] Creating test case: " << teststr << '\n';
        fs::create_directory(folder);
        Green();
        cout << "Folder '";
        cout << color(yellow) << task_folder << "/Test" << teststr;
        cout << "' created!\n";
        cout << "[ ] Generating input...\n";
#if _WIN32
        string workspace_wins = "";
        for (char c : workspace) {
          if (c == '/') {
            workspace_wins += "\\\\";
          } else {
            workspace_wins += c;
          }
        }
        execute(workspace_wins + "\\\\generator.exe " + to_string(test) +
                " > " + folder + "/" + task_name + ".INP");
        cout << "[ ] Generating output...\n";
        execute(workspace_wins + "\\\\solution.exe < " + folder + "/" +
                task_name + ".INP" + " > " + folder + "/" + task_name + ".OUT");
#else
        execute(workspace + "/generator " + to_string(test) + " > " + folder +
                "/" + task_name + ".INP");
        cout << "[ ] Generating output...\n";
        execute(workspace + "/solution < " + folder + "/" + task_name + ".INP" +
                " > " + folder + "/" + task_name + ".OUT");
#endif  // LOCAL
      }
      cout << color(blue) << "[*] All test case generated for task '";
      cout << color(yellow) << task_name;
      cout << color(blue) << "'!\n\n";
      success.push_back(task_name);
    }
  } catch (fs::filesystem_error& er) {
    cout << color(red) << "\n[-] Error occured: " << er.what();
    exit(EXIT_FAILURE);
  }
  if (success.size()) {
    cout << color(green) << "\n[+] " << success.size()
         << " task(s) generated:\n";
    for (const auto& x : success) {
      cout << color(green) << "  +) " << x << '\n';
    }
  }
  if (skipped.size()) {
    cout << color(red) << "\n[-] " << skipped.size() << " task(s) skipped:\n";
    for (const auto& x : skipped) {
      cout << color(red) << "  +) " << x << '\n';
    }
  }
  if (!success.size() && !skipped.size()) {
    cout << color(red) << "[-] No task found or can't be generated!\n";
  }
  cout << "\nBatch completed in " << (double)clock() / CLOCKS_PER_SEC
       << " seconds.\n";

  return 0;
}