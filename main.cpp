#include "gameOfLife.h"
#include <unistd.h>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector <vector <int>> state = randomState(40,30);
    int generation = 1;
    while(true) {
        cout << "Generation " << generation << endl;
        render(state);
        state = newState(state);
        ++generation;
        sleep(1);
    }
    return 0;
}