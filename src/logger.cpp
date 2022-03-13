#include <iostream>
#include <string>

class Logger
{
public:
    static void log(const std::string& msg)
    {
        std::cout << msg << std::endl;
    }

private:

};

int main() 
{
    Logger::log("it is working, as intended");

    return 0;
}