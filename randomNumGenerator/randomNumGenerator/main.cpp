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
#include <unordered_set>
using namespace std;

int main() {
    srand((unsigned)time(NULL));
    /* Basic array generator */
//    int m = 5;
//    int n = 20000;
//    while (m--) {
//        cout<<"[";
//        for (int i=0; i<n; ++i) {
//            int temp = rand() % 9999 - rand() % 9999;
//            cout << temp;
//            if (i != n-1)
//                cout << ',';
//        }
//        cout << "]" << endl;
//    }
//    
    
    /* 2d matrix generator - n*n */
    /* test cases number - m */
    int m = 1;
    int n = 100;
    int k = 100;
    while (m--) {
        cout << "[";
        for (int i=0; i<n; ++i) {
            cout<<"[";
            for (int j=0; j<n; ++j) {
                int v;
                v = rand() % 11;
                
                if (v <= 9) v = 0;
                else v = 1;
                
                if (i == j) v = 0;
                
                v = 0;
                
                if (j != n-1)
                    cout << v <<",";
                else
                    cout << v;
            }
            if (i != n-1)
                cout << "],";
            else
                cout << "]";
        }
        cout << "]" << endl;
        
        cout << "[";
        for (int i=0; i<n; ++i) {
            cout<<"[";
            for (int j=0; j<k; ++j) {
                int v = 1;
                if (j != k-1)
                    cout << v <<",";
                else
                    cout << v;
            }
            if (i != n-1)
                cout << "],";
            else
                cout << "]";
        }
        cout << "]" << endl;
    }
    
    
    
    
    
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
    
    /*
    //for (int j=1; j<=50; ++j) {
        cout<<"[";
        for (int i=1; i<=15; ++i) {
            if (i != 15)
                cout << 8 * i<< ",";
            else
                cout << 4 * i;
        }
        cout << "]" << endl;
    //}
    */
    
    //unordered_set<int> s;
    //for (int i=0; i<1000; ++i)
    //    s.insert(rand() % 1200);
    
    
    return 0;
}
