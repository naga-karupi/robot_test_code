#include<matplotlib-cpp/matplotlibcpp.h>
#include<vector>
#include<cmath>

namespace plt = matplotlibcpp;

int main(){
    std::vector<int> x(100), y(100);

    for(int i = 0; i < x.size(); i++){
        x.at(i) = i;
        y.at(i) = x.at(i)*x.at(i);
    }

    plt::plot(x, y);
    plt::show();

    return 0;
}