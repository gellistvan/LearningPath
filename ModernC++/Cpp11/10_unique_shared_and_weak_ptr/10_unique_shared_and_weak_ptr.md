In C++11, the memory model was enriched with smart pointers which are part of the `<memory>` header. These smart pointers (`std::unique_ptr`, `std::shared_ptr`, and `std::weak_ptr`) help manage dynamic memory automatically, avoiding manual memory management and reducing the risks of memory leaks and dangling pointers. Here's an overview of each, along with their casting mechanisms:

### `std::unique_ptr`
- **Description**: Manages a single object and ensures unique ownership of the object. When a `std::unique_ptr` goes out of scope, it automatically destroys the managed object.
- **Casting**: Uses `std::move` to transfer ownership, as `std::unique_ptr` cannot be copied.

### `std::shared_ptr`
- **Description**: Manages an object through reference counting. Multiple `std::shared_ptr` instances can own the same object; the object is destroyed when the last `shared_ptr` owning it is destroyed or reset.
- **Casting**: Can be copied directly, and also provides utilities like `std::static_pointer_cast`, `std::dynamic_pointer_cast`, and `std::const_pointer_cast` for safe type conversions.

### `std::weak_ptr`
- **Description**: Provides a non-owning but safe reference to an object managed by `std::shared_ptr`. It is used to break cyclic dependencies between `std::shared_ptr` instances.
- **Casting**: There’s no direct casting provided for `std::weak_ptr`, but it can be converted to `std::shared_ptr` to perform safe operations.

### Example: Simple Office Document Editor Using Smart Pointers

This example demonstrates a scenario in an office document editor where smart pointers manage components like documents, and user permissions. It also includes casting smart pointers.

```cpp
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
```

### Explanation:

1. **Classes and Members**:
   - `User`: Represents a user with a name.
   - `Document`: Contains a document's content and a list of viewers using `std::weak_ptr` to reference `User` instances safely.

2. **Smart Pointers Usage**:
   - `user1` and `user2` are managed by `std::shared_ptr` indicating shared ownership.
   - `doc` is a `std::unique_ptr`, ensuring unique ownership of the `Document` object. Ownership is transferred to `doc2` using `std::move`.

3. **Viewers Management**:
   - Viewers of a document are added as `std::weak_ptr` to prevent strong reference cycles and allow the `User` objects to be deallocated independently when their `std::shared_ptr` goes out of scope outside the document.

4. **Ownership Transfer**:
   - Demonstrates transferring ownership of a `std::unique_ptr` to another `std::unique_ptr`.

This example showcases how smart pointers can be used in a practical application to manage memory, share resources, and handle ownership with mechanisms that are both safer and more expressive than raw pointers. The use of casting was not explicitly necessary here, but in more complex class hierarchies, dynamic casting of shared pointers is common to safely convert pointer types.