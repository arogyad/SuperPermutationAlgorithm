#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include "algo.h"

int main(int argc, char* argv[]) {
    std::time_t start, end;
    time(&start);
    std::ios_base::sync_with_stdio(false);

    std::vector<int> main;
    int permutation = *argv[1] - '0';
    createVec(main, permutation);
    std::vector<int> is = superPer( main, permutation - 1, permutation );
    while ( true ) {
        is = superPer( main, is[1], permutation );
        if (is[0]) break;
    }
	for ( int i = (main.back() - 1); i != 0; --i ) {
		main.push_back( i );
	}
    for ( int &h : main ) {
        std::cout << h;
    }
    std::cout << std::endl;
	time(&end);
	double time_taken = double( end-start );
	std::cout << "[ Finished in: " << std::fixed << time_taken << std::setprecision(5);
	std::cout << "sec ]" << std::endl;
    return 0; 
}
