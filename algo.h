#ifndef SUP_PER
#define SUP_PER
#include <vector>
//int permutation;
std::vector<int> superPer(std::vector<int> &x, int checkIndex, const int &permutation);
void createVec(std::vector<int> &x, int num);
bool check(std::vector<int> &x, std::vector<int> &check, const int &permutation);
#endif
