#include "PmergeMe.hpp"
#include <cstddef>
#include <ctime>

PmergeMe::PmergeMe(){
}

PmergeMe::PmergeMe(char **av)
{
    this->args = av;
    if(!args){
        throw std::exception();
    }
    parse_input(args);
    merge();
}
    
PmergeMe::PmergeMe(const PmergeMe &other){
    *this = other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other){
    for (size_t i = 0; i < other.elements.size(); i++){
        elements.push_back(other.elements[i]);
    }
    return *this;
}

void    PmergeMe::merge()
{
    std::cout << "Before vector : ";
	for(size_t i = 0; i < elements.size(); i++)
		std::cout << elements[i] << " ";
	std::cout << std::endl;

    clock_t start_vector = std::clock();
    is_removed_v = false;
    merge_insert_sort_v();
    clock_t end_vector = std::clock() - start_vector;
    std::cout << "Vector time: " << (float)end_vector / CLOCKS_PER_SEC * 1000 << " ms" << std::endl;
    print_elements_v();

	std::cout << std::endl;

    std::cout << "Before deque : ";
	for(size_t i = 0; i < elements_d.size(); i++)
		std::cout << elements_d[i] << " ";
	std::cout << std::endl;
    clock_t start_deque = std::clock();
    is_removed_d = false;
    merge_insert_sort_d();
    clock_t end_deque = std::clock() - start_deque;
    std::cout << "Deque time: " << (float)end_deque / CLOCKS_PER_SEC * 1000 << " ms" << std::endl;
    print_elements_d();
}

void    PmergeMe::merge_insert_sort_d(){
    to_pairs_d();
    creat_mchain_d(pairs_d);
}

void    PmergeMe::merge_insert_sort_v(){
    to_pairs_v();
    creat_mchain_v(pairs);
}

void   PmergeMe::insert_elements_d(std::deque<int> &first, std::deque<int> &second)
{
    elements_d.clear();
    for (size_t i = 0; i < second.size(); i++){
        std::deque<int>::iterator it = std::lower_bound(first.begin(), first.end(), second[i]);
        first.insert(it, second[i]);
    }
    for (size_t i = 0; i < first.size(); i++){
        elements_d.push_back(first[i]);
    }
}

void   PmergeMe::insert_elements_v()
{
    elements.clear();
    for (size_t i = 0; i < second.size(); i++){
        std::vector<int>::iterator it = std::lower_bound(first.begin(), first.end(), second[i]);
        first.insert(it, second[i]);
    }
    for (size_t i = 0; i < first.size(); i++){
        elements.push_back(first[i]);
    }
}

void    PmergeMe::creat_mchain_d(std::deque<std::pair<int, int> > pairs){
    std::deque<int> first;
    std::deque<int> second;

    for (size_t i = 0; i < pairs.size(); i++){
        first.push_back(pairs[i].first);
        second.push_back(pairs[i].second);
    }
    if(first[0] >= second[0]){
        first.insert(first.begin(), second[0]);
        second.erase(second.begin());
    }
    if(is_removed_d)
        second.push_back(tmp);
    insert_elements_d(first, second);
}

void    PmergeMe::creat_mchain_v(std::vector<std::pair<int, int> > pairs){
    for (size_t i = 0; i < pairs.size(); i++){
        first.push_back(pairs[i].first);
        second.push_back(pairs[i].second);
    }
    if(first[0] >= second[0]){
        first.insert(first.begin(), second[0]);
        second.erase(second.begin());
    }
    if(is_removed_v)
        second.push_back(tmp); 
    insert_elements_v();
}

void PmergeMe::to_pairs_d()
{
    tmp_d = elements_d.end()[-1];
    if(elements_d.size() % 2 != 0){
        elements_d.pop_back();
        is_removed_d = true;
    }
    for (size_t i = 0; i < elements_d.size(); i += 2)
        pairs_d.push_back(std::make_pair(elements_d[i], elements_d[i + 1]));
    for (size_t i = 0; i < pairs_d.size(); i++) 
    {
        if (pairs_d[i].first < pairs_d[i].second)
            std::swap(pairs_d[i].first, pairs_d[i].second);
    }
    std::sort(pairs_d.begin(), pairs_d.end());
}

void PmergeMe::to_pairs_v()
{
    tmp = elements.end()[-1];
    if(elements.size() % 2 != 0){
        elements.pop_back();
        is_removed_v = true;
    }
    for (size_t i = 0; i < elements.size(); i += 2)
        pairs.push_back(std::make_pair(elements[i], elements[i + 1]));
    for (size_t i = 0; i < pairs.size(); i++) 
    {
        if (pairs[i].first < pairs[i].second)
            std::swap(pairs[i].first, pairs[i].second);
    }
    std::sort(pairs.begin(), pairs.end());
}

bool   is_number(const std::string &s)
{
    for(size_t i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ')
            continue;
        if(!std::isdigit(s[i]))
            return false;
    }
    return true;
}

void PmergeMe::parse_input(char **av)
{
    std::string arg;
    size_t num;

    for (int i = 1; av[i]; ++i) 
    {
        arg = av[i];
        std::istringstream iss(arg);
        if(!is_number(iss.str()))
            throw std::exception();
        while (iss >> num) 
        {
            if (num < 0)
                throw std::exception();
            elements.push_back(num);
            elements_d.push_back(num);
        }
    }
}

void PmergeMe::print_elements_v()
{
    std::cout << "After vector: ";
    for (size_t i = 0; i < elements.size(); i++)
        std::cout << elements[i] << " ";
    std::cout << std::endl;
}

void PmergeMe::print_elements_d()
{
    std::cout << "After deque: ";
    for (size_t i = 0; i < elements_d.size(); i++)
        std::cout << elements_d[i] << " ";
    std::cout << std::endl;
}
PmergeMe::~PmergeMe(){}