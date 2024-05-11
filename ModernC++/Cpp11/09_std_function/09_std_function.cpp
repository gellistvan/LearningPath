#include <iostream>
#include <vector>
#include <functional>
#include <string>

// PluginManager class to manage callbacks
class PluginManager {
public:
    using PluginCallback = std::function<void(const std::string&)>;

    void registerPlugin(const PluginCallback& callback) {
        plugins.push_back(callback);
    }

    void runAll(const std::string& input) {
        for (const auto& plugin : plugins) {
            plugin(input);
        }
    }

private:
    std::vector<PluginCallback> plugins;
};

int main() {
    PluginManager manager;

    // Register a simple echo plugin
    manager.registerPlugin([](const std::string& data) {
        std::cout << "Echo Plugin: " << data << std::endl;
    });

    // Register a transform plugin
    manager.registerPlugin([](const std::string& data) {
        std::string transformed;
        for (char c : data) {
            transformed += std::toupper(c);
        }
        std::cout << "Transform Plugin: " << transformed << std::endl;
    });

    // Run all plugins with input
    std::string input = "Hello, Plugin World!";
    manager.runAll(input);

    return 0;
}
