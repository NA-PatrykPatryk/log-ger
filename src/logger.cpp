#include <iostream>
#include <string>

class Logger
{
public:
    enum class Level{INFO, WARNING, ERROR};

public:
    static void log(const std::string& msg)
    {
        std::cout << msg << std::endl;
    }

private:
    Level logLevel = Level::INFO;
};

int main() 
{
    Logger::log("it is working, as intended");

    return 0;
}