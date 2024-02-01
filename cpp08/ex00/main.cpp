#include "easyfind.hpp"
#include <vector>

int main()
{
    std::vector<int> myvector;

    myvector.push_back(10);
    myvector.push_back(1);
    myvector.push_back(25);
    myvector.push_back(18);
    myvector.push_back(30);
    myvector.pop_back();

    std::vector<int>::iterator it;
    try{
        
        for (it = myvector.begin(); it != myvector.end(); ++it) {
            std::cout << "Element : "<< *it << std::endl;
        }

        // std::cout << *easyfind(myvector, 35) << std::endl;
        std::cout << *easyfind(myvector, 10) << std::endl;
    }
    catch(const char *e){
        std::cout << e << std::endl;
    }
}