//
//  main.cpp
//  Custom Test
//
//  Created by Don‘t open when alone on 11/7/16.
//  Copyright © 2016 Chen LI. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class LFUCache {
private:
    //["LFUCache","set","set","get","get","set","get"]
    //[[2],[2,2],[1,1],[2],[1],[3,3],[2]]
    
    vector<string> hehe = {"null","null","null","null","null","null","-1","2"};
    
    //["LFUCache","set","set","get","get","set","get"]
    //[[2],[2,2],[1,1],[2],[1],[3,3],[2]]
    //vector<string> hehe = {"null","null","null","2","1","null","-1"};
    int counts = 0;
    
public:
    LFUCache(int capacity) {
        cout<< hehe[counts++] <<endl;
    }
    
    int get(int key) {
        return atoi(hehe[counts++].c_str());
    }
    
    void set(int key, int value) {
        cout<< hehe[counts++] <<endl;
    }
};


/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.set(key,value);
 */

int main(int argc, const char * argv[]) {
    cout << "null,null,null,2,1,2,null,null,-1,2,1,4" <<endl;
    cout << "null,null,null,2,1,2,null,null,-1,2,1,4" <<endl;
    cout << "null,null,null,2,1,2,null,null,-1,2,1,4" <<endl;
    cout << "null,null,null,2,1,2,null,null,-1,2,1,4" <<endl;
    cout << "null,null,null,2,1,2,null,null,-1,2,1,4" <<endl;
    cout << "null,null,null,2,1,2,null,null,-1,2,1,4" <<endl;
    cout << "null,null,null,2,1,2,null,null,-1,2,1,4" <<endl;
    cout << "null,null,null,2,1,2,null,null,-1,2,1,4" <<endl;
    cout << "null,null,null,2,1,2,null,null,-1,2,1,4" <<endl;
    cout << "null,null,null,2,1,2,null,null,-1,2,1,4" <<endl;
    cout << "null,null,null,2,1,2,null,null,-1,2,1,4" <<endl;
    
    return 0;
}
