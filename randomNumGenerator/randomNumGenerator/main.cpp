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
    srand((unsigned)time(NULL));
    // interval generator
    //for (int i=-1e4+3326; i<1e3+8526; ++i) {
    //    cout<<"["<<i<<","<<i+15126+rand()%15256<<"],";
    //}
    //cout<<"]";
    
    
    // question 1
    /*
    int n = rand() % 11526;
    int m = rand() % 11526;
    cout << n <<endl;
    cout << m <<endl;
    cout<<"[";
    for (int i=0; i<n; ++i) {
        int temp = rand() % 1526 + 26;
        cout << temp;
        if (i != n-1)
            cout << ',';
    }
    cout << "]" << endl;
    cout<<"[";
    for (int i=0; i<m; ++i) {
        int temp = rand() % 526 + 26;
        cout << temp;
        if (i != m-1)
            cout << ',';
    }
    cout << "]" << endl;
    */
    
    cout << INT_MAX << endl;
    int n = 0;
    cout<<"[";
    for (int i=1; i<=n; ++i) {
        cout << "\"" << i%2 << 1 << "01\",";
    }
    cout << "]" << endl;

    return 0;
}
