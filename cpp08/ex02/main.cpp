#include "MutantStack.hpp"

int main()
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << "top: " << mstack.top() << std::endl;
    std::cout << "size Befor: " << mstack.size() << std::endl;
    mstack.pop();
    std::cout << "size after: " << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    std::cout << "stack: ";
    while (it != ite)
    {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;
    std::stack<int> s(mstack);
    std::cout << "top: " << s.top() << std::endl;
    return 0;
}

// int main()
// {
//     std::list<int> mstack;
//     mstack.push_back(5);
//     mstack.push_back(17);
//     std::cout << "top: " << mstack.back() << std::endl;
//     std::cout << "size Befor: " << mstack.size() << std::endl;
//     mstack.pop_back();
//     std::cout << "size after: " << mstack.size() << std::endl;
//     mstack.push_back(3);
//     mstack.push_back(5);
//     mstack.push_back(737);
//     mstack.push_back(0);

//     std::list<int>::iterator it = mstack.begin();
//     std::list<int>::iterator ite = mstack.end();
//     ++it;
//     --it;
//     std::cout << "stack: ";
//     while (it != ite)
//     {
//         std::cout << *it << " ";
//         ++it;
//     }
//     std::cout << std::endl;
//     std::list<int> s(mstack);
//     std::cout << "top: " << s.back() << std::endl;
//     return 0;
// }