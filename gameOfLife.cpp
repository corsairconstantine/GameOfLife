#include "gameOfLife.h"
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

vector <vector <int>> deadState(int w, int h) {
    vector <vector <int>> st;
    for (int height = 0; height < h; ++height) {
        vector <int> row;
        for (int width = 0; width < w; ++width)
            row.push_back(0);
        st.push_back(row);
    }
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
                if (neighbors(st, height, width) == 2 || neighbors(st, height, width) == 3)
                    newSt[height][width] = 1;
                if (neighbors(st, height, width) > 3) // if number of neigbours is 4 or more
                    newSt[height][width] = 0;
            }
            else if (neighbors(st, height, width) == 3) // if cell is dead
                newSt[height][width] = 1;
        }
    }             
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

bool isDead(std::vector <std::vector <int>> &st) {
    int sum = 0;
    for (int row = 0; row < st.size(); ++row)
        sum += accumulate(st[row].begin(), st[row].end(), 0);
    if (sum == 0)
        return true;
    return false;
}