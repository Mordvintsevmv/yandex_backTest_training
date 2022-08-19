#include <iostream>
#include <string>

void printseats(std::string seats[], int n, int row){
    std::cout << "Passengers can take seats:";
    if (seats[row][0] == "X"[0]) std::cout << " " << row+1 << "A";
    if (seats[row][1] == "X"[0]) std::cout << " " << row+1 << "B";
    if (seats[row][2] == "X"[0]) std::cout << " " << row+1 << "C";
    if (seats[row][4] == "X"[0]) std::cout << " " << row+1 << "D";
    if (seats[row][5] == "X"[0]) std::cout << " " << row+1 << "E";
    if (seats[row][6] == "X"[0]) std::cout << " " << row+1 << "F";

    for (int i = 0;  i<n; i++){
        std::cout << std::endl << seats[i];
    }

    std::cout << std::endl;

    if (seats[row][0] == "X"[0]) seats[row][0] = "#"[0];
    if (seats[row][1] == "X"[0]) seats[row][1] = "#"[0];
    if (seats[row][2] == "X"[0]) seats[row][2] = "#"[0];
    if (seats[row][4] == "X"[0]) seats[row][4] = "#"[0];
    if (seats[row][5] == "X"[0]) seats[row][5] = "#"[0];
    if (seats[row][6] == "X"[0]) seats[row][6] = "#"[0];



}

int main() {

    int n;
    std::cin >> n;

    auto *seats = new std::string [n];

    for (int i = 0; i < n; i++) {
        std::cin >> seats[i];
    }

    int m;
    int num;
    std::string side;
    std::string position;

    std::cin >> m;

    for (int i = 0; i < m; i++) {
        std::cin >> num;
        std::cin >> side;
        std::cin >> position;

        for (int j = 0; j<n; j++) {
            if (side == "left") {
                if (position == "aisle") {
                    if (num == 1) {
                        if (seats[j][2] == *".") {
                            seats[j][2] = "X"[0];
                            printseats(seats, n, j);
                            break;
                        }
                    } else if (num == 2) {
                        if (seats[j][2] == "."[0] and seats[j][1] == "."[0]) {
                            seats[j][1] = "X"[0];
                            seats[j][2] = "X"[0];
                            printseats(seats, n, j);
                            break;
                        }
                    } else if (num == 3) {
                        if (seats[j][2] == "."[0] and seats[j][1] == "."[0] and seats[j][0] == "."[0]) {
                            seats[j][0] = "X"[0];
                            seats[j][1] = "X"[0];
                            seats[j][2] = "X"[0];
                            printseats(seats, n, j);
                            break;
                        }
                    }

                } else if (position == "window") {

                    if (num == 1) {
                        if (seats[j][0] == *".") {
                            seats[j][0] = "X"[0];
                            printseats(seats, n, j);
                            break;
                        }
                    } else if (num == 2) {
                        if (seats[j][0] == "."[0] and seats[j][1] == "."[0]) {
                            seats[j][0] = "X"[0];
                            seats[j][1] = "X"[0];
                            printseats(seats, n, j);
                            break;
                        }
                    } else if (num == 3) {
                        if (seats[j][2] == "."[0] and seats[j][1] == "."[0] and seats[j][0] == "."[0]) {
                            seats[j][0] = "X"[0];
                            seats[j][1] = "X"[0];
                            seats[j][2] = "X"[0];
                            printseats(seats, n, j);
                            break;
                        }
                    }

                }

            } else if (side == "right") {
                if (position == "aisle") {
                    if (num == 1) {
                        if (seats[j][4] == *".") {
                            seats[j][4] = "X"[0];
                            printseats(seats, n, j);
                            break;

                        }
                    } else if (num == 2) {
                        if (seats[j][4] == "."[0] and seats[j][5] == "."[0]) {
                            seats[j][4] = "X"[0];
                            seats[j][5] = "X"[0];
                            printseats(seats, n, j);
                            break;

                        }
                    } else if (num == 3) {
                        if (seats[j][4] == "."[0] and seats[j][5] == "."[0] and seats[j][6] == "."[0]) {
                            seats[j][4] = "X"[0];
                            seats[j][5] = "X"[0];
                            seats[j][6] = "X"[0];
                            printseats(seats, n, j);
                            break;

                        }
                    }
                } else if (position == "window") {

                    if (num == 1) {
                        if (seats[j][6] == *".") {
                            seats[j][6] = "X"[0];
                            printseats(seats, n, j);
                            break;

                        }
                    } else if (num == 2) {
                        if (seats[j][5] == "."[0] and seats[j][6] == "."[0]) {
                            seats[j][5] = "X"[0];
                            seats[j][6] = "X"[0];
                            printseats(seats, n, j);
                            break;
                        }
                    } else if (num == 3) {
                        if (seats[j][4] == "."[0] and seats[j][5] == "."[0] and seats[j][6] == "."[0]) {
                            seats[j][4] = "X"[0];
                            seats[j][5] = "X"[0];
                            seats[j][6] = "X"[0];
                            printseats(seats, n, j);
                            break;
                        }
                    }

                }

            }

            if (n-j == 1) std::cout  << "Cannot fulfill passengers requirements" << std::endl;
        }

    }


    delete [] seats;
    return 0;
}
