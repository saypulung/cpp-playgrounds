#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    static std::string integerToRoman(int num) {
        vector<string> romanSymbols = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
        vector<int> values = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
        string roman;
        for (int i = 0; num != 0; i++) {
            while (num >= values[i]) {
                num -= values[i];
                roman += romanSymbols[i];
            }
        }
        return roman;
    }
};

int main()
{
    std::cout<<"Meong"<<std::endl;
    std::cout<<Solution::integerToRoman(1999)<<std::endl;
    int x = 100;
    std::cout<<"X = "<<x<<"\n";
    int y = x++;
    std::cout<<"Y = "<< y << "\n";
    std::cout<<"X = "<<x<<"\n";

    return 1;
}
