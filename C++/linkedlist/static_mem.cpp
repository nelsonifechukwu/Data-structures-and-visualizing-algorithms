#include <iostream>

class Dogs {
public:
    static int count;  // Declaration of static member variable

    Dogs() {
        // Increment the count each time a new object is created
        count++;
    }

    ~Dogs() {
        // Decrement the count each time an object is destroyed
        count--;
    }

    // A static member function to access count
    static int getCount() {
        return count;
    }
};

// Definition and initialization of static member variable

int Dogs::count = 1;

int main() {
    Dogs thy;
thy.count = 0 ;
    std::cout << "Initial count: " << Dogs::count << std::endl;

    Dogs dog1;
    std::cout << "Count after creating dog1: " << Dogs::count << std::endl;

    Dogs dog2;
    std::cout << "Count after creating dog2: " << Dogs::count << std::endl;

    {
        Dogs dog3;
        std::cout << "Count after creating dog3: " << Dogs::count << std::endl;
    }  // dog3 goes out of scope and is destroyed here

    std::cout << "Count after destroying dog3: " << Dogs::count << std::endl;

    // Accessing and modifying the static member variable using the class name
    Dogs::count += 1;
    std::cout << "Count after incrementing by 1: " << Dogs::count << std::endl;

    return 0;
}
