// TLE solution
class Solution {
private:
    bool isAllZero(vector<int> a) {
        int size = (int)a.size();
        for (int i=size-1; i>=0; --i) {
            if (a[i] > 0) return false;
        }
        return true;
    }
public:
    void divide(vector<int>& a, int b) {
        int temp = 0, size = (int)a.size();
        for (int i=0; i<size; ++i) {
            a[i] += temp * 10;
            temp = a[i] % b;
            a[i] /= b;
        }
    }
    int superPow(int a, vector<int>& b) {
        if (isAllZero(b)) return 1;
        a = a % 1337;
        bool isVectorEven = false;
        if (b[(int)b.size()-1] % 2 == 0) isVectorEven = true;
        divide(b, 2);
        int subResult = superPow(a, b) % 1337;
        int result = (subResult * subResult) % 1337;
        if (!isVectorEven) {
            result = (result * a) % 1337;
        }
        return result;
    }
};

// AC loop
class Solution {
private:
    bool isAllZero(vector<int>& a) {
        while((int)a.size() > 0 && 0 == a[0])
            a.erase(a.begin());
        if (a.empty()) return true;
        return false;
    }
public:
    void divide(vector<int>& a, int b, int& remain) {
        int temp = 0, size = (int)a.size();
        for (int i=0; i<size; ++i) {
            a[i] += temp * 10;
            temp = a[i] % b;
            a[i] /= b;
        }
        remain = temp;
    }
    int superPow(int a, vector<int>& b) {
        int result = 1;
        a = a % 1337;
        while (!isAllZero(b)) {
            int remain = 0;
            divide(b, 2, remain);
            if (remain) 
                result = (result * a) % 1337;
            a = (a * a) % 1337;
        }
        return result;
    }
};

// Digit by Digit
class Solution {
private:
    const int base = 1337;
    int modPow(int a, int b) {
        int result = 1;
        a %= base;
        for (int i=0; i<b; ++i)
            result = result * a % base;
        return result;
    }
public:
    int superPow(int a, vector<int>& b) {
        if (b.empty()) return 1;
        int lastDigit = b.back();
        b.pop_back();
        return modPow(superPow(a, b), 10) * modPow(a, lastDigit) % base;
    }
};