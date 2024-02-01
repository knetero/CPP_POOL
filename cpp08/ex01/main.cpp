#include "Span.hpp"
#include <algorithm>
#include <vector>


int main()
{

    Span sp = Span(5);

    try{
        
        sp.addNumber(5);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "without Iter: " << sp.longestSpan() << std::endl;
        std::cout << "without Iter: " << sp.shortestSpan() << std::endl;
        // sp.addNumber(11);
        // sp.addNumber(11);

        std::vector<int> vec(10000);

        std::srand(time (NULL));
        std::generate(vec.begin(), vec.end(), std::rand);

        Span sp2 = Span(vec.size());

        sp2.addNumber(vec.begin(), vec.end());

        std::cout << "with Iter: " << sp2.longestSpan() << std::endl;
        std::cout << "with Iter: " << sp2.shortestSpan() << std::endl;
    }
    catch(std::exception &e){
        std::cout << e.what() << std::endl;
    }

}