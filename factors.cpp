#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

std::vector<std::pair<int, int>> factorizeNumber(int n) {
    std::vector<std::pair<int, int>> factors;
    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            factors.push_back(std::make_pair(i, n / i));
        }
    }
    return factors;
}

void factorizeFile(const std::string& file_path) {
    std::ifstream file(file_path);
    std::string line;
    while (std::getline(file, line)) {
        int number = std::stoi(line);
        std::vector<std::pair<int, int>> factorizations = factorizeNumber(number);
        for (const auto& factorization : factorizations) {
            int p = factorization.first;
            int q = factorization.second;
            std::cout << number << "=" << p << "*" << q << std::endl;
        }
    }
    file.close();
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "Usage: factors <file>" << std::endl;
    } else {
        std::string file_path(argv[1]);
        factorizeFile(file_path);
    }
    return 0;
}
