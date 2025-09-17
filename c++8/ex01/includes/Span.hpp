#ifndef SPAN_HPP
# define SPAN_HPP

#include <exception>
#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <vector>
#include <list>
#include <deque>
#include <iostream>
#include <iomanip>
#include <iterator>
#include <algorithm>
#include <cstddef>
#include <iostream>
#include <cctype>
#include <string>

class	Span
{
    private:
        std::vector<int> _vec;
        unsigned int _N;
    public:
        Span(unsigned int n);
        ~Span();
        Span(const Span& src);
        Span& operator=(const Span& src);
        
        void addNumber(int x);
        int shortestSpan() const;
        int longestSpan() const;
        void multipleAdd(std::vector<int>::iterator begin, std::vector<int>::iterator end);
        void printvec() const;
};
#endif