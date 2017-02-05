#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>
using namespace std;

int main() {
    srand (time(NULL));
    
    int counts = 50;
    while (counts --) {
        string ring = "", key = "";
        for (int i=0; i<25; ++i) {
            ring += rand() % 26 + 'a';
        }
        key = ring + ring + ring + ring;
        random_shuffle(key.begin(), key.end());
        
        cout << "\"" << ring << "\"" << endl;
        cout << "\"" << key << "\"" << endl;
    }
    return 0;
}
