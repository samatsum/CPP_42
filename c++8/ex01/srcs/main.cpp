#include "../includes/Span.hpp"
#include <cstdlib> 
#include <ctime>


void addNumber_wrapper(Span& sp, int nb)
{
	try
	{
		sp.addNumber(nb);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
void largeInput_wrapper(Span& sp, std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	try
	{
		sp.multipleAdd(begin, end);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void span_wrapper(Span& sp)
{
	try
	{
		int shrt = sp.shortestSpan();
		std::cout << "shortest span is : " << shrt << std::endl;
		
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		int lrg = sp.longestSpan();
		std::cout << "longest span is : " << lrg << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void testBulk() 
{
	srand(static_cast<unsigned int>(time(NULL)));
	
	// Scenario 1: Bulk addition fitting exactly into capacity
    Span spanExactFit(5);
	std::vector<int> numbersToFit;
	numbersToFit.push_back(1);
	numbersToFit.push_back(2);
	numbersToFit.push_back(3);
	numbersToFit.push_back(4);
	numbersToFit.push_back(5);
    largeInput_wrapper(spanExactFit, numbersToFit.begin(), numbersToFit.end());
    std::cout << "testing on : ";
	spanExactFit.printvec(); // Expected: All numbers added
	span_wrapper(spanExactFit);
	std::cout << std::endl;

    // Scenario 2: Exceeding capacity
	Span spanExceed(5);
    std::vector<int> tooManyNumbers;
	tooManyNumbers.push_back(1);
	tooManyNumbers.push_back(2);
	tooManyNumbers.push_back(3);
	tooManyNumbers.push_back(4);
	tooManyNumbers.push_back(5);
	tooManyNumbers.push_back(6);
	std::cout << "testing to fill 6 nb in a Span of size 5 \n";
    largeInput_wrapper(spanExceed, tooManyNumbers.begin(), tooManyNumbers.end()); // Expects to catch and report an exception
	std::cout << std::endl;

    // Scenario 3: Correct calculations for known sequence
	Span spanCalc(10);
    std::vector<int> numbersForCalc;
	numbersForCalc.push_back(0);
	numbersForCalc.push_back(-100);
	numbersForCalc.push_back(5);
	numbersForCalc.push_back(20);
	numbersForCalc.push_back(100);
    largeInput_wrapper(spanCalc, numbersForCalc.begin(), numbersForCalc.end());
	std::cout << "testing on : ";
	spanCalc.printvec();
    span_wrapper(spanCalc); // Utilizing span_wrapper to catch potential exceptions from span calculations
	std::cout << std::endl;

    // Scenario 4: Edge case with identical numbers
    Span identicalNumbersSpan(2);
    addNumber_wrapper(identicalNumbersSpan, 100);
    addNumber_wrapper(identicalNumbersSpan, 100);
	std::cout << "testing on : ";
	identicalNumbersSpan.printvec();
    span_wrapper(identicalNumbersSpan); // Expected shortest span: 0
	std::cout << std::endl;

	
	// Scenario 5: test on 1 nbr
	Span TinySpan(1);
	addNumber_wrapper(TinySpan, 42);
	std::cout << "testing on : ";
	TinySpan.printvec();
	span_wrapper(TinySpan);
	std::cout << std::endl;
	
	// Scenario 6: test on 15k
	std::vector<int> BigVec;
	for (size_t i = 0; i < 15000; ++i)
		BigVec.push_back(rand());
	Span BigSpan(BigVec.size());
	largeInput_wrapper(BigSpan, BigVec.begin(), BigVec.end());
	std::cout << "testing on "<< BigVec.size() <<" nbers range: [" << *std::min_element(BigVec.begin(), BigVec.end()) << "] ... [" << *std::max_element(BigVec.begin(), BigVec.end()) <<"]\n";
	span_wrapper(BigSpan);
	std::cout << std::endl;
}

int test_subject()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	return(0);
}


int main()
{
	std::cout << "Subject tests\n";
	test_subject();
	std::cout << "\nMy tests\n";
	testBulk();
}