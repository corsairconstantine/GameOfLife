#include "gameOfLife.h"
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector <vector <int>> state = randomState(20,10);
    while(true) {
        render(state);
        system("read");
        state = newState(state);
    }
    return 0;
}