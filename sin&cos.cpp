#include <iostream>
#include <math.h>
#include <ctime>

int main()
{
    while(1){
        double angle;
        std::cin >> angle;
        time_t start, end;
        start = time(NULL);
        bool done = false;
        double x = 1, y;
        const double distance = (2 * 3.14159265359) / pow(10, 12);
        double lastVertex_x = 1, lastVertex_y = 0;
        double currentAngle = 0;
        while(!done){
            y = sqrt(1 - x * x);
            if(hypot(x - lastVertex_x, y - lastVertex_y) >= distance){
                lastVertex_x = x;
                lastVertex_y = y;
                currentAngle += distance;
                std::cout << currentAngle << std::endl;
                
                if(currentAngle >= angle){
                    end = time(NULL);
                    std::cout << "----------------" << std::endl;
                    std::cout << "angle: " << angle << std::endl;
                    std::cout << "cos: " << x << std::endl;
                    std::cout << "sin: " << y << std::endl;
                    std::cout << "real cos: " << cos(angle) << std::endl;
                    std::cout << "real sin: " << sin(angle) << std::endl;
                    std::cout << "time elapsed: " << difftime(end, start) << " s" << std::endl;
                    done = true;
                }
            }
            x -= pow(10, -12);
        }
    }
    return 0;
}
