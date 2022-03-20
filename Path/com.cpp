#include <iostream>
#include <windows.h>
using namespace std;

#include "_color.hpp"
using namespace colorwin;

int32_t main(int argc, char* argv[]) {
  if (argc == 1 || argc > 3) {

    cout << color(green) << "Usage: ";
    cout << "com <filename without extension '.cpp'>\n";
    
    cout << color(magenta) << "Use -clang in 3rd arguments for MSVS's Clang compiler with sanitizer! ";
    cout << color(red) << "(Slow compile & run time)\n";

    cout << color(yellow) << "Example: ";
    cout << "com main ";
    cout << color(yellow) << "(for file 'main.cpp')";

    if (argc > 3) {
      cout << color(red) << "\nThe program only take 2-3 arguments!!! (Arguments count: " << argc << ")"; 
    }

    return 1;
  }

  if (argc == 3 && strcmp(argv[2],"-clang") != 0) {
    cout << color(red) << "3rd argument only take -clang!!! (3rd argument detected: \"" << argv[2] << "\")";
    return 1;
  }
  string clang = string("clang++ -std=c++17 -DLOCAL -ggdb3 -Wall -Wextra -Wunused-variable -pedantic -Wshadow -Wformat=2 -Wfloat-equal -Wconversion  -Wlong-long -Wshift-overflow -Wcast-qual -Wcast-align -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 -D_GLIBCXX_ASSERTIONS -fno-sanitize-recover -fstack-protector -fno-sanitize-recover -fstack-protector -fsanitize=address,undefined -o ") + argv[1] + string(".exe ") + argv[1] + string(".cpp");

  string tdmgcc = string("g++ -std=c++17 -DLOCAL -ggdb3 -Wall -Wextra -Wunused-variable -pedantic -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 -D_GLIBCXX_ASSERTIONS -fno-sanitize-recover -fstack-protector -o ") + argv[1] + string(".exe ") + argv[1] + string(".cpp");

  string command = (argc == 3 ? clang : tdmgcc);
  cout << command << "\n\n";
  int ret = system(command.c_str());
  if (!ret) {
    cout << color(green) << "Compilation finished successfully!";
    return 0;
  }
  else {
    cout << color(red) << "Compilation failed! (Exit code " << ret << ")";
    return 1;
  }
}

