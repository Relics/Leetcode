#include <iostream>
#include <random>
#include <ctime>
#include <unordered_set>
using namespace std;

int main() {
    srand((unsigned)time(NULL));
    int testNum = 1;
    while (testNum--) {
        int counts = 10;
        int size = 1000;
        
        cout << "[";
        while (counts--) {
            cout << "[";
            for (int i=0; i<size; ++i) {
                if (i != size-1)
                    cout << rand() % 2 << ",";
                else
                    cout << rand() % 2;
            }
            if (counts == 0)
                cout << "]";
            else
                cout << "],";
        }
        cout << "]" << endl;
    }
    
    return 0;
}
