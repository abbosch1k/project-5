#include <iostream>
#include <map>
#include <functional>

int main() {
    std::map<std::string, std::function<void()>> cmds;

    cmds["start"] = []{ std::cout << "Started\n"; };
    cmds["stop"]  = []{ std::cout << "Stopped\n"; };

    std::string cmd;
    std::cin >> cmd;

    if (cmds.count(cmd)) cmds[cmd]();
    else std::cout << "Unknown command\n";
}
