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

void render(vector <vector <int>> st) {
    for (int height = 0; height < st.size(); ++height) {
        for (int width = 0; width < st[0].size(); ++width)
            if (st[height][width] == 1)
                cout << 'o' << ' ';
            else
                cout << '.' << ' ';
        cout << endl;
    }
}

int main() {
    vector <vector <int>> st = deadState(10,20);
    render(st);

    vector <vector <int>> stRand = randomState(20,10);
    render(stRand);

    return 0;
}