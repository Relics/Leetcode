// First Edition
class Solution {
public:
    int hIndex(vector<int>& citations) {
        if ((int)citations.size() == 0) return 0;
        int size = (int)citations.size();
        int l = 0;
        int r = size - 1;
        while (l < r-1) {
            int mid = l + (r - l) / 2;
            if (citations[mid] >= size-mid) r = mid;
            else l = mid + 1;
        }
        if (citations[l] >= size - l) return size-l;
        else if (citations[r] >= size - r) return size-r;
        return 0;
    }
};

// We can also write like this
class Solution {
public:
    int hIndex(vector<int>& citations) {
        if ((int)citations.size() == 0) return 0;
        int size = (int)citations.size();
        int l = 0;
        int r = size - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (citations[mid] >= size-mid) r = mid;
            else l = mid + 1;
        }
        if (citations[r] != 0)
            return size-r;
        return 0;
    }
};