#include <iostream>
#include <string>

int main()
{
    long long n;
    std::cin >> n;
    std::string ans = "";

    while (n>1)
    {
        ans += std::to_string(n) + " ";
        if (n%2)
            n = n*3+1;
        else
            n /= 2;
    }
    ans += "1";
    std::cout << ans << std::endl;

    return 0;
}
