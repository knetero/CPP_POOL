#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP


#include <algorithm>
#include <iostream>
#include <iomanip>
#include <iterator>
#include <vector>
#include <list>
#include <stack>


template <typename T>
class MutantStack : public std::stack<T>
{
    public:
        MutantStack(){}
        MutantStack(const MutantStack<T> &copy)
        {
            iterator it = copy.begin();
            for (; it != copy.end(); it++){
                this->push(*it);
            }
        }

        MutantStack<T> &operator=(const MutantStack<T> &other)
        {
            iterator it = other.begin();
            if (this != &other)
            {
                this->clear();
                for (; it != other.end(); it++){
                    this->push(*it);
                }
            }
            return (*this);
        }
        virtual ~MutantStack() {}

        typedef typename std::stack<T>::container_type::iterator iterator;
        typedef typename std::stack<T>::container_type::const_iterator const_iterator;

        iterator begin(){
            return (std::stack<T>::c.begin());
        }
        iterator end(){
            return (std::stack<T>::c.end());
        }


        const_iterator begin() const{
            return (std::stack<T>::c.begin());
        }
        const_iterator end() const{
            return (std::stack<T>::c.end());
        }
};

#endif
