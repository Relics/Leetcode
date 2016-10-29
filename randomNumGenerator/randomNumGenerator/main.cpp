//
//  main.cpp
//  randomNumGenerator
//
//  Created by Don‘t open when alone on 10/21/16.
//  Copyright © 2016 Chen LI. All rights reserved.
//

#include <iostream>
#include <random>
using namespace std;

int main() {
    cout<<"[";
    for (int i=-100; i<100; ++i) {
        cout<<"["<<i<<","<<i+2<<"],";
    }
    cout<<"]";
    return 0;
}
