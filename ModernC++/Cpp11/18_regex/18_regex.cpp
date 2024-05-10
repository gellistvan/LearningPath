#include <iostream>
#include <string>
#include <regex>

int main() {
    // Email validation example
    std::string email = "example@domain.com";
    std::regex emailPattern(R"((\w+)@(\w+)\.com)"); // Simple regex for demonstration
    std::smatch emailMatch;
    if (std::regex_match(email, emailMatch, emailPattern)) {
        std::cout << "The email '" << email << "' is valid." << std::endl;
    } else {
        std::cout << "Invalid email address." << std::endl;
    }

    // Search and parsing in a string
    std::string logEntry = "Error: 404 at index.html on 2024-01-10";
    std::regex searchPattern(R"(Error: (\d+) at (\S+) on (\d{4}-\d{2}-\d{2}))");
    std::smatch logMatch;
    if (std::regex_search(logEntry, logMatch, searchPattern)) {
        std::cout << "Error code: " << logMatch[1] << std::endl;
        std::cout << "File: " << logMatch[2] << std::endl;
        std::cout << "Date: " << logMatch[3] << std::endl;
    }

    // Replace example
    std::string text = "Today is 2024-01-10. We'll have a meeting on 2024-01-11.";
    std::string format = R"(\d{4}-\d{2}-\d{2})";
    std::string replacement = "[date]";
    std::regex datePattern(format);
    std::string replacedText = std::regex_replace(text, datePattern, replacement);
    std::cout << "Replaced text: " << replacedText << std::endl;

    return 0;
}
