#include <iostream>
#include <algorithm>
#include <cmath>


double dist(double a_x, double a_y, double p_x, double p_y, double r){
    double d = sqrt((a_x - p_x) * (a_x - p_x) + (a_y - p_y) * (a_y - p_y));
    // d = (distance from point to circle)
    if (d <= r) return 0;
    return d - r;
}


int main(){
    double a_x, a_y, b_x, b_y, p_x, p_y, r;
    std::cin >> a_x >> a_y >> b_x >> b_y >> p_x >> p_y >> r;

    double ans = sqrt((a_x - b_x) * (a_x - b_x) + (a_y - b_y) * (a_y - b_y));
    ans = std::min(ans, dist(a_x, a_y, p_x, p_y, r) + dist(b_x, b_y, p_x, p_y, r));

    std::cout.precision(13);
    std::cout << ans << '\n';

}

