#ifndef SPAN_HPP
#define SPAN_HPP


#include <algorithm>
#include <iostream>
#include <iomanip>
#include <iterator>
#include <vector>


class Span{
    private:
        unsigned int _n;
        std::vector<int> _container;
    public:
        Span();
        Span(unsigned int n);
        Span(const Span &copy);
        Span &operator=(const Span &copy);
        ~Span();

        void addNumber(int n);
        void addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
        int shortestSpan();
        int longestSpan();
        
        class FullContainerException : public std::exception{
            virtual const char *what() const throw();
        };
        class NotEnoughElementsException : public std::exception{
            virtual const char *what() const throw();
        };
};
#endif
