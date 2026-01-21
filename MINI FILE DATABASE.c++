#include <iostream>
#include <fstream>
#include <unordered_map>

int main() {
    std::unordered_map<std::string, std::string> db;
    db["user"] = "admin";

    std::ofstream out("db.txt");
    for (auto& [k, v] : db)
        out << k << "=" << v << "\n";

    std::ifstream in("db.txt");
    std::string line;
    while (getline(in, line))
        std::cout << line << std::endl;
}
