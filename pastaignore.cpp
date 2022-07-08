#include <string>
#include <iostream>
#include <filesystem>
#include <fstream>
#include <regex>
#include <vector>

#include "./argparse/include/argparse/argparse.hpp"

using recursive_directory_iterator = std::filesystem::recursive_directory_iterator;

std::vector<std::string>parseLine(std::string input);

int main(int argc, char* argv[]) {
	argparse::ArgumentParser program("pastaignore", "dev");
	program.add_argument("-i", "--input")
		.required()
		.help("specify the input file");
	program.add_argument("-o", "--output")
		.required()
		.help("specify the output file");
	program.add_argument("-vb", "--verbose")
		.help("increase output verbosity")
		.default_value(false)
		.implicit_value(true);
	try {
		program.parse_args(argc, argv);
	} catch (const std::runtime_error& err) {
		std::cerr << err.what() << std::endl;
		std::cerr << program;
		std::exit(1);
	}

	auto inputFile   = program.get<std::string>("-i");
	auto outputFile  = program.get<std::string>("-o");
	auto verboseFlag = program.get<bool>(      "-vb");

	std::string line = "";
	std::fstream fInput(inputFile);

        std::vector<std::string> gPool;
	std::vector<std::string> ePool;
	std::vector<std::string> iPool;
	std::vector<std::string> fList;

        for (const auto& dirEntry : recursive_directory_iterator("."))
		gPool.push_back(dirEntry.path().string());

        if (verboseFlag) {
		std::cout << "GLOBAL POOL OF FILES:\n\n\n";
                for (const auto& str : gPool) {
                        std::cout << str << "\n";
                }
		std::cout << "\n\n";
        }

	std::vector<std::vector<std::string>> parsedLines;

	if (fInput.is_open()) {
		while (std::getline(fInput, line)) {
			parsedLines.push_back(parseLine(line));
		}
	} else {
		std::cout << "Input file not open!";
	}
	fInput.close();

	for (const auto& parsed_line : parsedLines) {
		if (verboseFlag) {
			std::cout << "PARSED LINE OPERATIONS:\n\n\n";
		}
		for(const auto& file : gPool) {
			if (parsed_line[1] == "not") {
				if(std::regex_match(file, std::regex(parsed_line[0]))) {
					if (!(std::regex_match(file, std::regex(parsed_line[2])))) {
						fList.push_back(file);
					} else if (verboseFlag) { std::cout << "File didn't pass second regex. file: " << file << " regex: " << parsed_line[2] << "\n"; }
				} else if (verboseFlag) { std::cout << "File didn't pass first regex. file: " << file << " regex: " << parsed_line[0] << "\n"; }
			} else if (parsed_line[1] == "and") {
				if(std::regex_match(file, std::regex(parsed_line[0]))) {
					if (std::regex_match(file, std::regex(parsed_line[2]))) {
						fList.push_back(file);
					} else if (verboseFlag) { std::cout << "File didn't pass second regex. file: " << file << " regex: " << parsed_line[2] << "\n"; }
				} else if (verboseFlag) { std::cout << "File didn't pass first regex. file: " << file << " regex: " << parsed_line[0] << "\n"; }
			}
			else if (verboseFlag) { std::cout << "Unsupported operand: " << parsed_line[1] << "\n"; }
		}
	}
	if (verboseFlag) {
		std::cout << "\n\nFINALIZED FILE LIST:\n\n\n";
		for (const auto& file : fList) {
			std::cout << file << "\n";
		}
	}
	std::ofstream fOutput (outputFile);
	if (fOutput.is_open()) {
		for (const auto& file : fList) {
			fOutput << file << "\n";
		}
	} else {
		std::cout << "Output file not open!";
	}
	fOutput.close();
}

std::vector<std::string> parseLine(std::string input) {
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

	std::string midToken = "";
	for (int i = j; i < input.size(); i++) {
		if ((input[i] != ' ') && (input[i] != '\n') && (input[i] != '\r') && (input[i] != '\"')) midToken += input[i];
		if (midToken == "not") { ret.push_back(midToken); j = i; break;}
		if (midToken == "and") { ret.push_back(midToken); j = i; break;}
		if (midToken == "or")  { ret.push_back(midToken); j = i; break;}
		if (midToken == "xor") { ret.push_back(midToken); j = i; break;}
		if (midToken == "nand"){ ret.push_back(midToken); j = i; break;}
		if (midToken == "nor") { ret.push_back(midToken); j = i; break;}
		if (midToken == "xnor"){ ret.push_back(midToken); j = i; break;}
		j = i;
	}
	startIndex = j;
        endIndex   = -1;
	bool inside = false;
	std::string endToken = "";
        for (int i = j; i < input.size(); i++) {
		if (inside) endToken += input[i];
                if (input[i] == '\"' && input[i-1] != '\\') {
			inside = !inside;
                }
        }
	endToken = endToken.substr(0, endToken.size() - 1);
	ret.push_back(endToken);
	return ret;
}

