#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>

std::vector<std::vector<int>> get2DVector(int n, std::string filename)
{
    std::vector<std::vector<int>> result(n);

    std::ifstream input(filename);

    std::string s;
    for (int i = 0; i < n; i++)
    {
        std::getline(input, s);
        std::istringstream iss(s);

        std::string num;
        while (std::getline(iss, num, ','))
            result[i].push_back(std::stoi(num));
    }

    return result;
}

int main()
{
    auto vec = get2DVector(9, "test.txt");

    for (auto& v : vec)
    {
        for (int i : v)
            std::cout << i << ' ';
        std::cout << '\n';
    }
}