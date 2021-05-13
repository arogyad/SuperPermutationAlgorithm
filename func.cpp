#include "algo.h"
#include <deque>
#include <iostream>
#include <algorithm>

std::vector<int> superPer(std::vector<int> &x, int checkIndex, const int& permutation) {
    std::vector<int>::const_iterator start = x.end() - permutation;
    std::vector<int>::const_iterator end = x.end();
    std::deque<int> temp;
    for ( int i = 1 ; i != permutation; ++i ) {
        std::vector<int> fVec ( start, end );
        if ( ( checkIndex + i ) < permutation )  {
            std::iter_swap( fVec.begin() + checkIndex, fVec.begin() + ( checkIndex + i ) );
            if ( std::search( x.begin(), x.end(), fVec.begin(), fVec.end() ) == x.end() ) {
                std::deque<int>::reverse_iterator rvr = temp.rbegin();
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
             if ( std::search( x.begin(), x.end(), fVec.begin(), fVec.end() ) == x.end() ) {
                std::iter_swap ( fVec.begin() + checkIndex, fVec.begin() + posi );
                std::vector<int> front;
                for ( std::vector<int>::iterator j = fVec.begin(); j != fVec.begin() + checkIndex; ++j ) {
                   front.push_back( *j );
                }
                temp.push_back( *( fVec.begin() + posi ) );
                temp.push_front( permutation );
                for ( std::deque<int>::reverse_iterator j = temp.rbegin(); j != temp.rend(); ++j ) { 
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

void createVec(std::vector<int> &x, int num) {
    for (int i = 1; i != (num + 1); ++i) {
        x.push_back( i );
    }
}
