#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream infile("example.txt", std::ios::in);
    
    if (!infile) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }

    std::string line;
    while (getline(infile, line)) {
        size_t pos = line.find("target");
        if (pos != std::string::npos) {
            std::cout << "'target' found at position " << pos << std::endl;
            std::cout << "Extracted: " << line.substr(pos, 6) << std::endl;
        }

        size_t startPos = line.find("start");
        if (startPos != std::string::npos) {
            std::cout << "Extracted portion after 'start': " << line.substr(startPos + 6, 10) << std::endl;
        }
    }

    infile.close();
    return 0;
}
