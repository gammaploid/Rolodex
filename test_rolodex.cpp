
#include "Rolodex.h"
#include <iostream>

int main() {
    Rolodex rolodex;

    // Insert some cards
    rolodex.insertAfterCurrent("Alice");
    rolodex.insertAfterCurrent("Bob");
    rolodex.insertBeforeCurrent("Aaron"); // Should insert before Bob

    // Move to the first card
    while (!rolodex.isBeforeFirst()) {
        rolodex.rotateBackward();
    }
    rolodex.rotateForward(); // Now at "Aaron"

    // Print all cards
    while (!rolodex.isAfterLast()) {
        std::cout << rolodex.currentValue() << std::endl;
        rolodex.rotateForward();
    }

    return 0;
}
