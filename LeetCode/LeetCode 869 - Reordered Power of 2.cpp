class Solution {
private:
    vector<int> powerOf2List;

public:
    bool reorderedPowerOf2(int n) {
        buildPowerOf2List();
        for (int i = 0; i < powerOf2List.size(); i++) {
            if (isRearrange(n, powerOf2List.at(i))) {
                return true;
            }
        }

        return false;
    }

    void buildPowerOf2List() {
        int n = 1;
        for (int i = 0; i < 30; i++) {
            powerOf2List.push_back(n);
            n *= 2;
        }
    }

    void insertDigitInSet(multiset<int> &set, int num) {
        while (num > 0) {
            set.insert(num % 10);
            num /= 10;
        }
    }

    bool isRearrange(int num, int target) {
        multiset<int> ms;
        insertDigitInSet(ms, num);
        while (target > 0) {
            int d = target % 10;
            multiset<int>::iterator it = ms.find(d);
            if (it == ms.end()) { // can't find element
                return false;
            }

            ms.erase(it);
            target /= 10;
        }

        return ms.empty();
    }
};