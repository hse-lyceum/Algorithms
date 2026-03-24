#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;


int binarySearch(const vector<int>& v, int target) {
    int L = 0, R = v.size() - 1;
    while (L <= R) {
        const int mid = L + (R - L) / 2;
        if (v[mid] == target) {
            return mid;
        }
        if (target > v[mid]) {
            L = mid + 1;
        }
        else {
            R = mid - 1;
        }
    }
    return -1;
}


int main() {
    cout << binarySearch({10, 20, 30, 40, 50, 60}, 30) << endl;
    cout << binarySearch({10, 20, 30, 40, 50, 60}, 15) << endl;
    cout << binarySearch({100}, 100) << endl;
    cout << binarySearch({1, 4, 8, 21, 23}, 52) << endl;
}