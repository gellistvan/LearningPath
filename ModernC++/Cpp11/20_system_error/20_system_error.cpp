#include <iostream>
#include <system_error>
#include <string>

// Define a custom error category
class file_error_category : public std::error_category {
public:
    const char* name() const noexcept override {
        return "file_error";
    }

    std::string message(int ev) const override {
        switch (ev) {
            case 1: return "File not found";
            case 2: return "Permission denied";
            default: return "Unknown file error";
        }
    }
};

// Get a reference to the custom category
const std::error_category& file_category() {
    static file_error_category instance;
    return instance;
}

// Error codes specific to file operations
enum class file_errc {
    success = 0,
    not_found = 1,
    permission_denied = 2
};

// Make error_code from file_errc
std::error_code make_error_code(file_errc e) {
    return {static_cast<int>(e), file_category()};
}

// Register the error code enumeration
namespace std {
    template <>
    struct is_error_code_enum<file_errc> : true_type {};
}

// Function that simulates a file operation and returns an error_code
std::error_code perform_file_operation(bool success) {
    if (!success) {
        return make_error_code(file_errc::not_found);
    }
    return std::error_code{};  // success
}

int main() {
    try {
        // Simulate an operation that fails
        std::error_code ec = perform_file_operation(false);

        if (ec) {
            // Throw system_error if operation failed
            throw std::system_error(ec, "Failed to perform file operation");
        }

        std::cout << "Operation succeeded." << std::endl;
    } catch (const std::system_error& e) {
        std::cout << "Caught system_error: " << e.what() << std::endl;
        std::cout << "Error code: " << e.code() << " (" << e.code().message() << ")" << std::endl;
    }

    return 0;
}
