#include "gameOfLife.h"
#include <iostream>
#include <vector>

using namespace std;

vector <vector <int>> deadState(int w, int h) {
    vector <vector <int>> st;
    for (int height = 0; height < h; ++height) {
        vector <int> row;
        for (int width = 0; width < w; ++width)
            row.push_back(0);
        st.push_back(row);
    }
    cout << "made a dead state " << st[0].size() << 'x' << st.size() << endl;
    return st;
}
vector <vector <int>> randomState(int w, int h) {
    vector <vector <int>> st;
    for (int height = 0; height < h; ++height) {
        vector <int> row;
        for (int width = 0; width < w; ++width)
            row.push_back(rand() % 2);
        st.push_back(row);
    }
    cout << "made a random state " << st[0].size() << 'x' << st.size() << endl;
    return st;

}

int neighbors(vector <vector <int>> st, int r, int c) {
    // think about borders
    int nbrs = 0;
    for(int row = r - 1; row <= r + 1; ++row) {
        if (row < 0 || row >= st.size())
            continue;
        for (int column = c - 1; column <= c + 1; ++column) {
            if (column < 0 || column >= st[0].size())
                continue;
            nbrs += st[row][column];
        }
    }
    return nbrs - st[r][c];
}

std::vector <std::vector <int>> newState(vector <vector <int>> st) {
    std::vector <std::vector <int>> newSt = deadState(st[0].size(), st.size()); 
    for (int height = 0; height < st.size(); ++height) {
        for (int width = 0; width < st[0].size(); ++width) {
            if (st[height][width] == 1) {          // if cell is alive
                if (neighbors(st, height, width) < 2) // if number of neighbours is 0 or 1
                    newSt[height][width] = 0;
                if (neighbors(st, height, width) > 3) // if number of neigbours is 4 or more
                    newSt[height][width] = 0;
            }
            else if (neighbors(st, height, width) == 3) // if cell is dead
                newSt[height][width] = 1;
        }
    }             // TO DO -- I need to make a new state, modify it using old state, and return new state
    cout << "made a new state" << endl;
    return newSt;
}

void render(vector <vector <int>> &st) {
    for (int height = 0; height < st.size(); ++height) {
        for (int width = 0; width < st[0].size(); ++width)
            if (st[height][width] == 1)
                cout << 'o' << ' ';
            else
                cout << '.' << ' ';
        cout << endl;
    }
}