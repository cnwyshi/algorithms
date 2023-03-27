#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

namespace NUMS {
    enum {
        START = 0,
        ZERO = 0,
        ONE,
        TWO,
        GAP = 2,
        THREE,
        FOUR
    };
}


int main() {
    cout << NUMS::START << endl;
    cout << NUMS::ZERO << endl;
    cout << NUMS::ONE << endl;
    cout << NUMS::TWO << endl;
    cout << NUMS::GAP << endl;
    cout << NUMS::THREE << endl;
    cout << NUMS::FOUR << endl;
}