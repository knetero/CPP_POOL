#ifndef EASYFIND_HPP
#define EASYFIND_HPP


#include <algorithm>
#include <iostream>
#include <iomanip>
#include <iterator>


template <typename T>
typename T::iterator easyfind(T &container, int n){
    typename T::iterator it = std::find(container.begin(), container.end(), n);
    if(it != container.end()){
        return it;
    }
    else {
        throw "Element not found !";
    }
}
#endif
