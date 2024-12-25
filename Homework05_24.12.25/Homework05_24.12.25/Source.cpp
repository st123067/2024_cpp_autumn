#include<iostream>
#include <ctime>
#include "Header.h"

int main(int argc, char* argv[]) {
    int m[N];

    srand(static_cast<unsigned>(time(nullptr)));

    for (int i = 0; i < N; ++i) {
        m[i] = std::rand() % 100;
    }

    Array<int> mm(m);

    mm.Show();

    std::cout << "Minimum value: " << mm.Minimum() << std::endl;

    return EXIT_SUCCESS;
}
