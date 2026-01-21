#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

long long maxi = LLONG_MIN; 
void permute(vector<int>& arr, int l, int r) {
    if (l == r) {
        string no = "";
        for (int x : arr) {
            no += to_string(x);
        }
        long long val = stoll(no);
        maxi = max(maxi, val);
        return;
    }
    for (int i = l; i <= r; ++i) {
        swap(arr[l], arr[i]);
        permute(arr, l + 1, r);
        swap(arr[l], arr[i]);
    }
}

int main() {
    vector<int> arr = {34, 5, 30, 4, 9, 12};
    permute(arr, 0, arr.size() - 1);
    cout << "Maximum value formed: " << maxi << endl;
    return 0;
}
