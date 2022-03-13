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

    static void log(const std::string& msg, Logger::Level level)
    {
        switch(level)
        {
            case Level::INFO:
                std::cout << "\033[1;37m"
                << "[Info] "
                << msg
                << "\033[0m"
                << std::endl;
                break;
        
            case Level::WARNING:
                std::cout << "\033[1;33m"
                << "[Info] "
                << msg
                << "\033[0m"
                << std::endl;
                break;
            
            case Level::ERROR:
                std::cout << "\033[1;31m"
                << "[Info] "
                << msg
                << "\033[0m"
                << std::endl;
                break;
            default:
                break;
        }

    }
    // static void logInfo(const std::string& msg)
    // {
    //     if (logLevel >= Level::INFO)
    //     {
    //         std::cout << "\033[1;37m"
    //             << "[Info] "
    //             << msg
    //             << "\033[0m"
    //             << std::endl;
    //     }
    // }

    // static void logWarning(const std::string& msg)
    // {
    //     if (logLevel >= Level::WARNING)
    //     {
    //         std::cout << "\033[1;33m"
    //             << "[Warning] "
    //             << msg
    //             << "\033[0m"
    //             << std::endl;
    //     }
    // }

    // static void logError(const std::string& msg)
    // {
    //     if (logLevel >= Level::ERROR)
    //     {
    //         std::cout << "\033[1;31m"
    //             << "[Error] "
    //             << msg
    //             << "\033[0m"
    //             << std::endl;
    //     }
    // }

    static void setLevel(Level level)
    {
        logLevel = level;
    }

private:
    static Level logLevel;
};

Logger::Level Logger::logLevel = Logger::Level::INFO;

int main()
{
    Logger::setLevel(Logger::Level::ERROR);
    //Logger::setLevel(Logger::Level::WARNING);
    //Logger::setLevel(Logger::Level::INFO);
    // Logger::logInfo("info");
    // Logger::logWarning("warning");
    // Logger::logError("error");
    Logger::log("cokolwiek", Logger::Level::ERROR);



    return 0;
}