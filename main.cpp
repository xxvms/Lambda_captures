#include <iostream>
#include <algorithm>
#include <vector>

int main() {

    std::vector<int> vector;

    for (size_t i = 0; i < 10; ++i)
    {
        vector.push_back(i);
    }

    // capturing by value explicitly [x,y]
    int x = 3;
    int y = 7;
    std::cout << "printing elements between " << x << " and " << y << " inclusive: ";
    std::for_each(vector.begin(), vector.end(),[x,y](int n){
        if (n >= x && n <= y )
            std::cout << n << ", ";
    });
    std::cout << "\n********************" << '\n';

    std::cout << '\n';
    std::for_each(vector.begin(), vector.end(), [](int n){std::cout << n << " ";});
    std::cout << '\n';

    std::cout << "\n********************" << '\n';
    // capturing by value implicitly [=]
    x = 2;
    y = 5;

    std::cout << "printing elements between " << x << " and " << y << " inclusive: ";
    std::for_each(vector.begin(), vector.end(),[=](int n){
        if (n >= x && n <= y )
            std::cout << n << ", ";
    });

    std::cout << "\n********************" << '\n';
    // capturing by value and changing localy [=] mutable
    x = 1;
    y = 1;

    std::for_each(vector.begin(), vector.end(), [=](int& r) mutable{
        const int old = r;
        r *= 2;
        x = y;
        y = old;
    } );

    std::cout << "Doubling" << '\n';
    std::for_each(vector.begin(), vector.end(),[](int n) {
        std::cout << n << " "; });
    std::cout << "\n x, y: " << x << ", " << y;


    std::cout << "\n********************" << '\n';

    // capturing by reference [&x, &y] - also changing the parameter to (int&)

    vector.clear(); // removes all elements from vector

    for (size_t i = 0; i < 10; ++i) { vector.push_back(i);}
    std::for_each(vector.begin(), vector.end(), [&x, &y] (int& r) {
        const int old = r;
        r *= 2;
        x = y;
        y = old;
    });

    std::for_each(vector.begin(), vector.end(), [=](int i) {
      std::cout << i << " ";
    });

    std::cout << "\nx,y: " << x << "," << y;

    std::cout << "\n********************" << '\n';
    // capturing whole stack by reference (and a neat way to keep initializing  vector?

    vector.clear();
    int i = 0;
    std::generate_n(std::back_inserter(vector), 10, [&]{ return i++;}); // [&]() { return i++;}
    std::cout << "initializing" << '\n';
    std::for_each(vector.begin(), vector.end(), [](int i){std::cout << i << " ";});
    std::cout << "\n i: " << i << '\n';


    return 0;
}