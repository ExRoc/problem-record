#include <bits/stdc++.h>
using namespace std;

int binarySearch(int A[], int size, int x) {
    int low = 0, high = size - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (A[mid] < x) {
            low = mid + 1;
        } else if (A[mid] > x) {
            high = mid - 1;
        } else {
            return mid;
        }
    }

    return -1;
}

int main() {
    ios::sync_with_stdio(false);

    // int n, x;
    // cin >> n >> x;
    // int* A = new int[n];
    // for (int i = 0; i < n; ++i) {
    //     cin >> A[i];
    // }
    // cout << binarySearch(A, n, x) << '\n';
    // delete[] A;

    cout << "5 1" << '\n';
    cout << "5 1 2 3 4" << '\n';

    return 0;
}
