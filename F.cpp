#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

int main() {

    int n;
    std::cin >> n;

    int *x1 = new int[n];
    int *x2 = new int[n];
    int *y1 = new int[n];
    int *y2 = new int[n];


    int *q1x1 = new int[n];
    int *q1x2 = new int[n];
    int *q1y1 = new int[n];
    int *q1y2 = new int[n];

    int *q2x1 = new int[n];
    int *q2x2 = new int[n];
    int *q2y1 = new int[n];
    int *q2y2 = new int[n];

    int *q3x1 = new int[n];
    int *q3x2 = new int[n];
    int *q3y1 = new int[n];
    int *q3y2 = new int[n];

    int *q4x1 = new int[n];
    int *q4x2 = new int[n];
    int *q4y1 = new int[n];
    int *q4y2 = new int[n];

    int *q1sq = new int[n];
    int *q2sq = new int[n];
    int *q3sq = new int[n];
    int *q4sq = new int[n];

    for (int i = 0; i<n; i++){
        std::cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];

        q1x1[i] = 0;
        q1y1[i] = 0;
        q1x2[i] = x2[i];
        q1y2[i] = y2[i];

        q2x1[i] = x1[i];
        q2y1[i] = 0;
        q2x2[i] = 0;
        q2y2[i] = y2[i];

        q3x1[i] = x1[i];
        q3y1[i] = y1[i];
        q3x2[i] = 0;
        q3y2[i] = 0;

        q4x1[i] = 0;
        q4y1[i] = y1[i];
        q4x2[i] = x2[i];
        q4y2[i] = 0;

        q1sq[i] = q1x2[i]*q1y2[i];
        q2sq[i] = -q2x1[i]*q2y2[i];
        q3sq[i] = q3x1[i]*q3y1[i];
        q4sq[i] = -q4x2[i]*q4y1[i];

    }


//    for (int i = 0; i<n; i++){
//        std::cout << i << std::endl;
//        std::cout << "1 четверть: " << q1sq[i] << std::endl;
//        std::cout << "2 четверть: " << q2sq[i] << std::endl;
//        std::cout << "3 четверть: " << q3sq[i] << std::endl;
//        std::cout << "4 четверть: " << q4sq[i] << std::endl << std::endl;
//    }

    for (int i = 0; i<n-1; i++){

        for (int j=i+1; j<n; j++){

            if(q1sq[i]==0 and q2sq[i]==0 and q3sq[i]==0 and q4sq[i]==0){
                break;
            }

            if ((q1x2[j]>=q1x2[i]) and (q1y2[j]>=q1y2[i])){
                q1sq[i] = 0;
            }
            if ((q2x1[j]<=q2x1[i]) and (q2y2[j]>=q2y2[i])){
                q2sq[i] = 0;
            }
            if ((q3x1[j]<=q3x1[i]) and (q3y1[j]<=q3y1[i])){
                q3sq[i] = 0;
            }
            if ((q4x2[j]>=q4x2[i]) and (q4y1[j]<=q4y1[i])){
                q4sq[i] = 0;
            }


            if ((q1x2[j]>=q1x2[i]) and (q1y2[j]<q1y2[i])){
                q1y1[i] = q1y2[j];
                q1sq[i] -= q1y2[j]*q1x2[i];
            }
            if ((q1x2[j]<q1x2[i]) and (q1y2[j]>=q1y2[i])){
                q1x1[i] = q1x2[j];
                q1sq[i] -= q1x2[j]*q1y2[i];
            }

            if ((q2x1[j]<=q2x1[i]) and (q2y2[j]<q2y2[i])){
                q2y1[i] = q2y2[j];
                q2sq[i] += q2x1[i]*q2y2[j];
            }
            if ((q2x1[j]>q2x1[i]) and (q2y2[j]>=q2y2[i])){
                q2x2[i] = q2x1[j];
                q2sq[i] += q2x1[j]*q2y2[i];
            }

            if ((q3x1[j]<=q3x1[i]) and (q3y1[j]>q3y1[i])){
                q3y2[i] = q3y1[j];
                q3sq[i] -= q3x1[i]*q3y1[j];
            }
            if ((q3x1[j]>q3x1[i]) and (q3y1[j]<=q3y1[i])){
                q3x2[i] = q3x1[j];
                q3sq[i] -= q3y1[i]*q3x1[j];
            }

            if ((q4x2[j]>=q4x2[i]) and (q4y1[j]>q4y1[i])){
                q4y2[i] = q4y1[j];
                q4sq[i] += q4x2[i]*q4y1[j];
            }
            if ((q4x2[j]<q4x2[i]) and (q4y1[j]<=q4y1[i])){
                q4x1[i] = q4x2[j];
                q4sq[i] += q4y1[i]*q4x2[j];
            }

        }

    }
//
//    std::cout << "NEW" << std::endl;
//    for (int i = 0; i<n; i++){
//        std::cout << i << std::endl;
//        std::cout << "1 четверть: " << q1sq[i] << std::endl;
//        std::cout << "2 четверть: " << q2sq[i] << std::endl;
//        std::cout << "3 четверть: " << q3sq[i] << std::endl;
//        std::cout << "4 четверть: " << q4sq[i] << std::endl << std::endl;
//    }

    for (int i = 0; i<n; i++){
        std::cout << q1sq[i]+q2sq[i]+q3sq[i]+q4sq[i] << std::endl;
    }






}


