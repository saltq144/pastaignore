#include <string>
#include <iostream>
#include <filesystem>
#include <regex>
#include <vector>

using recursive_directory_iterator = std::filesystem::recursive_directory_iterator;

/*std::vector<std::string>*/ void parseLine(std::string input);

int main() {
	for (const auto& dirEntry : recursive_directory_iterator("."))
		if(std::regex_match(dirEntry.path().string(), std::regex(".*\\.o")))
			std::cout << dirEntry << "\n";
	parseLine("\"testing!\" not \"testing 2!\"");
}


/*std::vector<std::string>*/ void parseLine(std::string input) {
	std::vector<std::string> ret;
	int j = 0;
	int startIndex = -1;
	int endIndex   = -1;
	for (int i = 0; i < input.size(); i++) {
		if (input[i] == '\"') {
			if (i == 0) {
				startIndex = 0;
				i++;
				continue;
			} else {
				if (input[i - 1] == '\\') {
					i++;
					continue;
				} else {
					endIndex = i;
					j = i;
					break;
				}
			}
		}
	}
	ret.push_back(input.substr(startIndex + 1, endIndex - startIndex - 1));
	std::cout << input.substr(startIndex + 1, endIndex - startIndex - 1) << "\n";

	std::string midToken = "";
	for (int i = j; i < input.size(); i++) {
		if ((input[i] != ' ') && (input[i] != '\n') && (input[i] != '\r') && (input[i] != '\"')) midToken += input[i];
		if (midToken == "not") { ret.push_back(midToken); j = i; break;}
		j = i;
	}
	std::cout << midToken << "\n";
	//std::cout << input.substr(j, input.size() - j - 2);
	startIndex = j;
        endIndex   = -1;
	//std::cout << input << "\n";
	//std::cout << j << "\n";
	bool inside = false;
	std::string endToken = "";
        for (int i = j; i < input.size(); i++) {
		if (inside) endToken += input[i];
                if (input[i] == '\"' && input[i-1] != '\\') {
                        /*if (i == 0) {
                                startIndex = 0;
                                i++;
                                continue;
                        } else if (inside) {
                                if (input[i - 1] == '\\') {
                                        i++;
                                        continue;
                                } else {
                                        endIndex = i;
                                        j = i;
                                        break;
                                }
                        } else if (!inside) { inside = true; std::cout << "INSIDE ENABLED!" << input[i];}*/
		inside = !inside;
                }
        }
	endToken = endToken.substr(0, endToken.size() - 1);
	std::cout << endToken;
	//std::cout << input.substr(startIndex + 1, endIndex - startIndex - 1);
}

