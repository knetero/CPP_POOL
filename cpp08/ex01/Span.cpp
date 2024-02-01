#include "Span.hpp"
#include <algorithm>
#include <cstddef>


Span::Span() : _n(0){
}

Span::Span(unsigned int n) : _n(n){
}

Span::Span(const Span &copy){
    *this = copy;
}

Span &Span::operator=(const Span &copy){
    if(this != &copy){
        _n = copy._n;
        _container = copy._container;
    }
    return *this;
}

void Span::addNumber(int n){
    if(_container.size() < _n)
        _container.push_back(n);
    else
        throw FullContainerException();
}

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end){
    if(_container.size() + std::distance(begin, end) <= _n)
        _container.insert(_container.end(), begin, end);
    else
        throw FullContainerException();
}

int Span::shortestSpan(){
    if(_container.size() < 2)
        throw NotEnoughElementsException();
    
    std::vector<int> diff;

    std::vector<int> sorted = _container;
    std::sort(sorted.begin(), sorted.end());

    for (size_t i  = 1 ; i < sorted.size(); i++) {
        diff.push_back(sorted[i] - sorted[i - 1]);
    }
    int shortest = *std::min_element(diff.begin(), diff.end());
    return (shortest);
}

int Span::longestSpan(){
    if(_container.size() < 2)
        throw NotEnoughElementsException();


    std::vector<int> sorted = _container;
    std::sort(sorted.begin(), sorted.end());


    int longest = sorted[sorted.size() - 1] - sorted[0];
    return longest;
}

const char* Span::NotEnoughElementsException::what() const throw(){
    return "Not Enough Element !!";
}

const char* Span::FullContainerException::what() const throw(){
    return "there are already N elements stored !!";
}



Span::~Span(){}