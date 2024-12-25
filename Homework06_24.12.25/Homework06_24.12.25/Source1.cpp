#include "Header.h"
#include <iostream>

int main(int argc, char* argv[]) {
    try {
        Dataset dataset("data.csv", true);

        std::cout << "First 5 rows:" << std::endl;
        dataset.Head();

        std::cout << "Last 5 rows:" << std::endl;
        dataset.Tail();

        std::vector<std::string> newRow = { "6", "new_value_1", "new_value_2" };
        dataset.Insert(2, newRow);
        std::cout << "After inserting a new row:" << std::endl;
        dataset.Head(10);

        dataset.Remove(2);
        std::cout << "After removing the inserted row:" << std::endl;
        dataset.Head(10);

        std::cout << "Statistics for column 'column_name':" << std::endl;
        dataset.Describe("column_name");

    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return EXIT_SUCCESS;
}
