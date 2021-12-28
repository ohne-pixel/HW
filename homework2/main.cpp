#include <iostream>
#include <fstream>
#include <utility>
#include <vector>
#include <cmath>
/* входной файл:
h0
vx vy
x1 h1
x2 h2
...
xn hn
*/
int main(int argc, char** argv) {
    if (argc == 2) {
        std::ifstream infile(argv[1]); // в argv[1] содержится строка с первым агрументом (имя файла)
        std::vector < std::pair < double, double >> partition;
      
        double h0;
        double x = 0;
        infile >> h0;

        double vx, vy;
        infile >> vx >> vy;

        double g = -9.81;

        int size = 0;
        int interval = 0;

        while (true) {
            int goal = (vx > 0) ? interval : interval - 1;

            if (goal < 0) {
                std::cout << "0" << std::endl;
                return 0;
            }
          
            if (goal > size - 1) {
                double xi, hi;
              
                if (infile >> xi >> hi) {
                    partition.push_back(std::make_pair(xi, hi));
                    size++;
                } else {
                    std::cout << size << std::endl;
                    return 0;
                }
            }
          
            // часть с расчётами
            double t = std::abs((x-partition[goal].first) / vx);

            x = partition[goal].first;
            h0 = h0 + vy*t + 0.5*g*t*t;
            vy = vy + g*t;

            if (h0 <= 0) {
                std::cout << interval << std::endl;
                return 0;
            }
          
            if (h0 > partition[goal].second) {
                (vx > 0) ? interval++ : interval--;
            } else {
                vx = vx*(-1);
            }
        }
    }
}
