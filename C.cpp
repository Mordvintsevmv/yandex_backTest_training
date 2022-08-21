#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

int main() {

    int n, k;
    std::cin >> n >> k;

    int *a = new int [n];

    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::vector<int> a_sorted(a, a+n);
    std::sort(a_sorted.begin(), a_sorted.end());

    int res;
    std::vector<int>::iterator it;
    long left;
    long right;

    if (n-k==1){
        for (int i = 0; i < n; i++){
            res = 0;

            for (int j = 0; j < n; j++){
                if (j==i) continue;
                res += abs(a[i] - a[j]);
            }

            std::cout << res << " ";
        }
    }
    else {
        for (int i = 0; i < n; i++) {

            res = 0;

            it = std::find(a_sorted.begin(), a_sorted.end(), a[i]);

            left = (it - a_sorted.begin()) - 1;
            right = (it - a_sorted.begin()) + 1;

            for (int m = 0; m < k; m++) {

                if ((left >= 0) and (right < n)) {
                    if (abs(a[i] - a_sorted[left]) < abs(a[i] - a_sorted[right])) {
                        res += abs(a[i] - a_sorted[left]);
                        left--;
                    } else {
                        res += abs(a[i] - a_sorted[right]);
                        right++;
                    }
                } else if (left >= 0) {
                    res += abs(a[i] - a_sorted[left]);
                    left--;
                } else {
                    res += abs(a[i] - a_sorted[right]);
                    right++;
                }
            }
            std::cout << res << " ";
        }
    }

    delete [] a;
    return 0;
}


