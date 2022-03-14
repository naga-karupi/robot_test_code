/* 
 * こんたくんのためにstd::vectorを解説
 *
 * 簡単言うと可変長配列
 * 配列と同じような操作が可能
 * vecというvectorがあったら
 * vec.at(x);でx番目の要素にアクセス、配列でいうarr[x];みたいに扱える
 * ちなみにvec[x];とも書ける
 * vec.size();で配列の大きさを取れる sizeofなんて時代遅れだ
 * 
 */

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