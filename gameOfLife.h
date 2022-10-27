#include <vector>

std::vector <std::vector <int>> deadState(int w, int h);
std::vector <std::vector <int>> randomState(int w, int h);
int neighbors(std::vector <std::vector <int>> st, int r, int c);
std::vector <std::vector <int>> newState(std::vector <std::vector <int>> st);
void render(std::vector <std::vector <int>> &st);

bool isDead(std::vector <std::vector <int>> &st); 