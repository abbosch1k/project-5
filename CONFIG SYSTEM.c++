#include <iostream>
#include <map>

int main() {
    std::map<std::string, std::string> cfg;
    cfg["PORT"] = "8080";

    std::string port = cfg.count("PORT") ? cfg["PORT"] : "3000";
    std::cout << "Port: " << port << std::endl;
}
