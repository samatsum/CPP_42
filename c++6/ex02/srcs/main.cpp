#include "../includes/Base.hpp"
#include "../includes/A.hpp"
#include "../includes/B.hpp"
#include "../includes/C.hpp"

#include <cstdlib>
#include <cstdio>

Base *generate(void)
{
	srand(time(NULL));
	switch (rand() % 3)
	{
		case 0:
			return (new A());
			break;
		case 1:
			return (new B());
			break;
		case 2:
			return (new C());
			break;
		default:
			std::cout << "\033[31m Unknown Type Base \033[m" << std::endl;
			return (NULL);
			break;
	}
}

void identify(Base *Test)
{
	if (dynamic_cast<A *>(Test))//// 失敗時: nullptr を返す
		std::cout << "A is the identified type" << std::endl;
	else if (dynamic_cast<B *>(Test))
		std::cout << "B is the identified type" << std::endl;
	else if (dynamic_cast<C *>(Test))
		std::cout << "C is the identified type" << std::endl;
	else
		std::cout << "\033[31m Unknown Type Base \033[m" << std::endl;
}

void identify(Base &Test)
{
    try {
        A &a = dynamic_cast<A &>(Test);// 例えばB型のオブジェクトをA型のaという参照（別名）に変換しようとすると、std::bad_cast例外が自動的に投げられる->catchに飛ぶ。
        (void)a;
        std::cout << "A is the identified type" << std::endl;
        return;
    }
    catch (std::exception &e)
	{
    }
    
    try {
        B &b = dynamic_cast<B &>(Test);
        (void)b;
        std::cout << "B is the identified type" << std::endl;
        return;
    }
    catch (std::exception &e)
	{
    }
    
    try {
        C &c = dynamic_cast<C &>(Test);
        (void)c;
        std::cout << "C is the identified type" << std::endl;
        return;
    }
    catch (std::exception &e)
	{
        std::cout << "\033[31m Unknown Type Base \033[m" << std::endl;
    }
}

int main()
{
	Base *Test = generate();
	if (Test == NULL)
		return (1);
	else
	{
		identify(Test);
		identify(*Test);
		delete (Test);

		std::cout << std::endl;
	}
	return (0);
}
