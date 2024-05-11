#include <iostream>
#include <vector>
#include <numeric> // For std::iota
#include <iomanip> // For std::setw and std::setfill

class Date {
public:
    int year, month, day;

    Date() : year(1900), month(01), day(01) {}
    Date(int y, int m, int d) : year(y), month(m), day(d) {}

    // Function to increment the date
    Date& operator++() {
        ++day; // Simplified: does not handle month or year end.
        return *this;
    }

    // Overload ++ for the post-increment
    Date operator++(int) {
        Date temp = *this;
        ++*this;
        return temp;
    }

    // Overload << to output the date
    friend std::ostream& operator<<(std::ostream& os, const Date& date) {
        os << std::setw(4) << std::setfill('0') << date.year << '-'
           << std::setw(2) << std::setfill('0') << date.month << '-'
           << std::setw(2) << std::setfill('0') << date.day;
        return os;
    }
};

int main() {
    std::vector<Date> dates(30); // Assume the month has 30 days

    // Start from May 1, 2024
    Date start_date(2024, 5, 1);

    // Fill the vector with dates of May
    std::iota(dates.begin(), dates.end(), start_date);

    // Print the dates
    for (const auto &date: dates) {
        std::cout << date << std::endl;
    }

    return 0;
}
