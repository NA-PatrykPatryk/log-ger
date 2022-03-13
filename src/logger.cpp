#include <iostream>
#include <string>

class Logger
{
public:
    enum class Level
    {
        ERROR,
        WARNING,
        INFO,
        max_level
    };

public:
    static void log(const std::string& msg, Level level)
    {
        switch (level)
        {
        case Level::INFO:
            if (level >= Level::INFO)
                printMsg("[Info] ", msg, "37");
            break;
        case Level::WARNING:
            if (level >= Level::WARNING)
                printMsg("[Info] ", msg, "37");
            break;
        case Level::ERROR:
            if (level >= Level::ERROR)
                printMsg("[Info] ", msg, "37");
            break;
        default:
            break;
        }
    }

    static void setLevel(Level level)
    {
        logLevel = level;
    }

private:
    static void printMsg(const std::string& prefix, const std::string& msg, const std::string& style)
    {
        std::cout << "\033[1;" << style << "m"
            << prefix
            << msg
            << "\033[0m"
            << std::endl;
    }
private:
    static Level logLevel;
};

Logger::Level Logger::logLevel = Logger::Level::INFO;

int main()
{
    Logger::setLevel(Logger::Level::ERROR);

    Logger::log("info", Logger::Level::INFO);
    Logger::log("warning", Logger::Level::WARNING);
    Logger::log("error", Logger::Level::ERROR);

    return 0;
}