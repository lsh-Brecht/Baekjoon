#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

vector<int> arr;
class Sorting {
public:
    void quickSort(vector<int>& arr, int left, int right) {
        if (left >= right) return;
        int pv{ partition(arr, left, right) };
        quickSort(arr, left, pv);
        quickSort(arr, pv + 1, right);
    }

private:
    int partition(vector<int>& arr, int left, int right) {
        int pivot = arr[left + (right - left) / 2];
        int i{ left - 1 };
        int j{ right + 1 };
        //내림차순
        while (true) {
            do { i++; } while (arr[i] > pivot);
            do { j--; } while (arr[j] < pivot);
            if (i >= j) return j;
            swap(arr[i], arr[j]);
        }
    }

    void swap(int& a, int& b) {
        int temp{ a };
        a = b;
        b = temp;
    }
};

void solve() {
	int n; cin >> n; arr.resize(n);
    for(int i = 0; i < n; ++i) cin >> arr[i];
    Sorting sorter;
	sorter.quickSort(arr, 0, n - 1);
    for(int i = 0; i < n; ++i) cout<< arr[i] << ' ';

}


int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}