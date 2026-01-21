#include <iostream>
#include <fstream>
#include <mutex>

enum class LogLevel {
    INFO,
    WARNING,
    ERROR
};

class Logger {
    std::ofstream file;
    std::mutex mtx;

    Logger() {
        file.open("app.log", std::ios::app);
    }

public:
    static Logger& instance() {
        static Logger logger;
        return logger;
    }

    void log(LogLevel level, const std::string& msg) {
        std::lock_guard<std::mutex> lock(mtx);

        std::string prefix;
        switch (level) {
            case LogLevel::INFO: prefix = "[INFO] "; break;
            case LogLevel::WARNING: prefix = "[WARN] "; break;
            case LogLevel::ERROR: prefix = "[ERROR] "; break;
        }

        file << prefix << msg << std::endl;
        std::cout << prefix << msg << std::endl;
    }
};

int main() {
    Logger::instance().log(LogLevel::INFO, "Application started");
    Logger::instance().log(LogLevel::WARNING, "Low memory");
    Logger::instance().log(LogLevel::ERROR, "Fatal error");
}
