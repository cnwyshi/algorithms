#include <iomanip>
#include <iostream>
int main() {
    int n;
    std::cin >> n;
    int x = 1;
    for (int r = 0; r < n; r++) {
        for (int c = 0; c <= r; c++) {
            std::cout << std::setw(4) << x;
            x++;
        }
        std::cout << std::endl;
    }
}