#include <iostream>
#include <type_traits>

struct TrivialType {
    int x;
    float y;
};

struct StandardLayoutType {
private:
    int x;
public:
    float y;
};

struct NonTrivialType {
    NonTrivialType() : x(0), y(0) {}  // User-defined constructor makes this non-trivial
    int x;
    float y;
};

struct PODType {
    int x;
    float y;
};

int main() {
    std::cout << std::boolalpha;
    std::cout << "Is TrivialType trivial? " << std::is_trivial<TrivialType>::value << std::endl;
    std::cout << "Is StandardLayoutType standard-layout? " << std::is_standard_layout<StandardLayoutType>::value << std::endl;
    std::cout << "Is NonTrivialType trivial? " << std::is_trivial<NonTrivialType>::value << std::endl;
    std::cout << "Is PODType a POD type? " << std::is_pod<PODType>::value << std::endl;

    return 0;
}
