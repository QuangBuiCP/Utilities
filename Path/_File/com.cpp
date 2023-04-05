#include <iostream>
#include <windows.h>
using namespace std;

#include "_color.hpp"
using namespace colorwin;

template <class T>
int szer(const T& s) {
	return (int) s.size();
}

void tutor() {
	cout << color(green) << "Usage: ";
	cout << "com <filename without extension '.cpp'>\n";
	cout << color(yellow) << "Example: ";
	cout << "com main.cpp";
}

int32_t main(int argc, char* argv[]) {
	if (argc == 1 || argc > 2) {
		tutor();
		if (argc > 2) {
			cout << color(red) << "\nThe program only take 2 arguments!!! (Arguments count: " << argc << ")"; 
		}
		return 1;
	}

	string filename = string(argv[1]);
	string basename = filename;
	for (int rep = 0; szer(basename) && rep < 4; ++rep) {
		basename.pop_back();
	}
	if (basename.empty()) {
		cout << color(red) << "Not a valid filename!!";
		cout << color(yellow) << " (Don't use \".cpp\")\n";
		tutor();
		return 1;
	}
	if (basename + ".cpp" != filename) {
		cout << color(red) << "File extension is not valid (\".cpp\" is required)\n";
		tutor();
		return 1;
	}

	string tdmgcc = string("g++ -std=c++17 -DLOCAL -ggdb3 -Wall -Wextra -Wunused-variable -pedantic -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 -D_GLIBCXX_ASSERTIONS -fno-sanitize-recover -fstack-protector -o ") + basename + string(".exe ") + filename;

	string command = tdmgcc;
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