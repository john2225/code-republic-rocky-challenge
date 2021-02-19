#include <iostream>

int findDivisor(int a, int b);

int main()
{
    int first_num = 0;
    int second_num = 0;
    std::cout << "Enter two numbers: \n";
    std::cin >> first_num >> second_num;
    int greatestDivisor = find(first_num, second_num);
    std::cout << "Greatest divisors of two numbers is: " << greatestDivisor << std::endl;
    return 0;
}

int findDivisor(int a, int b)
{
    if(a == 0) {return b;}
    if(b == 0) {return a;}
    //q is integer
    //r is integer between 0 and b - 1
    int q = a / b;
    int r = a - (b * q);
    if(a == (b * q + r)) {
        return findDivisor(b, r);
    }
    return 1;
}
