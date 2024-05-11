#include <iostream>
#include <memory>
#include <vector>
#include <string>

class User {
public:
    std::string name;
    explicit User(const std::string& name) : name(name) {}
};

class Document {
public:
    std::string content;
    std::vector<std::weak_ptr<User>> viewers;

    void addViewer(const std::shared_ptr<User>& user) {
        viewers.push_back(std::weak_ptr<User>(user));
    }

    void showViewers() const {
        std::cout << "Current viewers of the document:\n";
        for (auto viewer : viewers) {
            if (auto sp = viewer.lock()) {
                std::cout << sp->name << std::endl;
            } else {
                std::cout << "Viewer is no longer active.\n";
            }
        }
    }
};

int main() {
    auto user1 = std::make_shared<User>("Alice");
    auto user2 = std::make_shared<User>("Bob");

    std::unique_ptr<Document> doc = std::make_unique<Document>();
    doc->content = "Important confidential document.";

    doc->addViewer(user1);
    doc->addViewer(user2);

    // Showing the document viewers
    doc->showViewers();

    // Suppose we need to transfer ownership of the document to another pointer
    std::unique_ptr<Document> doc2 = std::move(doc); // Transfer ownership from doc to doc2

    if (!doc) {
        std::cout << "doc is now empty, and doc2 owns the document.\n";
    }

    // Output viewers using the new owner
    doc2->showViewers();

    return 0;
}
