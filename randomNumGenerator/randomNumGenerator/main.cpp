//
//  main.cpp
//  randomNumGenerator
//
//  Created by Don‘t open when alone on 10/21/16.
//  Copyright © 2016 Chen LI. All rights reserved.
//

#include <iostream>
#include <random>
#include <ctime>
using namespace std;

int main() {
    cout<<"[";
    srand((unsigned)time(NULL));
    for (int i=-1e4+3326; i<1e3+8526; ++i) {
        cout<<"["<<i<<","<<i+15126+rand()%15256<<"],";
    }
    cout<<"]";
    return 0;
}
