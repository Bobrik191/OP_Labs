#include "util.h"
#include <iostream>

using namespace std;

int set_mode(int argc, char** argv) {
	if (argc != 3) return -1;

	std::string flag{ argv[1] },
		mode{ argv[2] };

	if (flag != "-mode") return -1;

	if (mode == "FilePointer") return 1;
	if (mode == "FileStream") return 2;

	return -1;
}
