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
    cout << "made a dead state " << w << 'x' << h << endl;
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
    cout << "made a random state " << w << 'x' << h << endl;
    return st;

}

int main() {
    vector <vector <int>> st = deadState(5,5);

    for (int height = 0; height < st.size(); ++height) {
        for (int width = 0; width < st[0].size(); ++width)
            cout << st[width][height] << ' ';
        cout << endl;
    }

    vector <vector <int>> stRand = randomState(5,5);
    for (int height = 0; height < stRand.size(); ++height) {
        for (int width = 0; width < stRand[0].size(); ++width)
            cout << stRand[width][height] << ' ';
        cout << endl;
    }
    return 0;
}