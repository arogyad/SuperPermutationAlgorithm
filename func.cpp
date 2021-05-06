#include "algo.h"
#include <iostream>
#include <algorithm>

std::vector<int> superPer(std::vector<int> &x, int checkIndex, const int& permutation) {
    std::vector<int>::const_iterator start = x.end() - permutation;
    std::vector<int>::const_iterator end = x.end();
    std::vector<int> temp;
    for ( int i = 1 ; i != permutation; ++i ) {
        std::vector<int> fVec ( start, end );
        if ( ( checkIndex + i ) < permutation )  {
            std::iter_swap( fVec.begin() + checkIndex, fVec.begin() + ( checkIndex + i ) );
            if ( !( check( x, fVec, permutation ) ) ) {
                std::vector<int>::reverse_iterator rvr = temp.rbegin();
                for ( int j = checkIndex + 1; j != ( checkIndex + i ); ++j ){
                    fVec[j] = *rvr;
                    ++rvr;
                }
                for ( auto &k : fVec ) {
                    x.push_back( k );
                }
                checkIndex += i;
                std::vector<int> out { false, checkIndex };
                return out;

            } else {
                temp.push_back( *( fVec.begin() + ( checkIndex ) ) );
            }
        } else {
             int posi = ( checkIndex + i ) % permutation;
             std::iter_swap ( fVec.begin() + checkIndex, fVec.begin() + posi );
             if ( !( check(x, fVec, permutation) ) ) {
                std::iter_swap ( fVec.begin() + checkIndex, fVec.begin() + posi );
                std::vector<int> front;
                for ( std::vector<int>::iterator j = fVec.begin(); j != fVec.begin() + checkIndex; ++j ) {
                   front.push_back( *j );
                }
                temp.push_back( *( fVec.begin() + posi ) );
                temp.insert( temp.begin(), permutation );
                for ( std::vector<int>::reverse_iterator j = temp.rbegin(); j != temp.rend(); ++j ) { 
                    front.push_back( *j );
                }
                temp.clear();
                for ( std::vector<int>::iterator j = (front.begin() + posi + 1); j != front.end() - (posi + 1); ++j ) {
                    temp.push_back( *j );
                }
                for ( auto &h: front ) {
                    x.push_back( h );
                }
                for ( auto &h: temp ) {
                    x.push_back( h );
                }
                checkIndex = posi;
                std::vector<int> out { false, posi };
                return out;
             } else {
                temp.push_back ( *( fVec.begin() + checkIndex ) );
             }
        }
    }
    std::vector<int> out { 1, 0 };
    return out;
}

bool check(std::vector<int> &x, std::vector<int> &check, const int& permutation) {
    for (std::vector<int>::iterator i = x.begin(); i != (x.end() - (permutation - 1)); ++i) {
        std::vector<int> tVec ( i, i + permutation );
        if ( tVec == check ) {
            return true;
        }
    }
    return false;
}

void createVec(std::vector<int> &x, int num) {
    for (int i = 1; i != (num + 1); ++i) {
        x.push_back( i );
    }
}
