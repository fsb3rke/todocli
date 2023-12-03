#include <iostream>
#include <fstream>
#include "../lib/json.hpp"
#include "fs.h"

using json = nlohmann::json;

void checkInitFile();

int main(int argc, char const *argv[])
{
	std::ifstream f(argv[1]);
	json data = json::parse(f);
	std::cout << data.dump(4) << std::endl;
	return 0;
}

void checkInitFile() {

}