#include <iostream>

int main() {

    int n;
    std::cin >> n;

    int *mas = new int [n];

    for (int i = 0; i < n; i++) {
        std::cin >> mas[i];

        if ((i > 0) and (mas[i] < mas[i - 1])) {
            std::cout << -1;
            return 0;
        }
    }

    std::cout << (mas[n-1] - mas[0]);

    delete [] mas;
    return 0;
}
