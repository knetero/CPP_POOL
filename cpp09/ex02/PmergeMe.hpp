#ifndef PMERGEME_HPP
#define PMERGEME_HPP


#include <algorithm>
#include <iostream>
#include <iomanip>
#include <iterator>
#include <fstream>
#include <sstream>
#include <cstddef>
#include <vector>
#include <string>
#include <deque>
#include <utility>
#include <exception>


class PmergeMe
{
    private:
        std::vector<int> elements;
        std::deque<int> elements_d;
        std::vector<std::pair<int, int> > pairs;
        std::deque<std::pair<int, int> > pairs_d;
        std::vector<int> first;
        std::vector<int> second;

        int tmp;
        int tmp_d;
        bool is_removed_v;
        bool is_removed_d;
        char **args;
    public:
        PmergeMe();
        PmergeMe(char **av);
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &other);
        ~PmergeMe();

        //**** Vector container ****
        void merge();
        void merge_insert_sort_v();
        void insert_elements_v();
        void to_pairs_v();
        void creat_mchain_v(std::vector<std::pair<int, int> > pairs);
        void print_elements_v();

        //**** Deque container ****
        void merge_insert_sort_d();
        void insert_elements_d(std::deque<int> &first, std::deque<int> &second);
        void to_pairs_d();
        void creat_mchain_d(std::deque<std::pair<int, int> > pairs);
        void print_elements_d();

    
        void parse_input(char **av);
};

bool   is_number(const std::string &s);


#endif
