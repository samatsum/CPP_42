#include "../includes/Base.hpp"
#include "../includes/A.hpp"
#include "../includes/B.hpp"
#include "../includes/C.hpp"

#include <cstdlib>
#include <cstdio>

/* ************************************************************************** */
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

/* ************************************************************************** */
void identify(Base *Test)
{
	if (dynamic_cast<A *>(Test))
		std::cout << "A is the identified type" << std::endl;
	else if (dynamic_cast<B *>(Test))
		std::cout << "B is the identified type" << std::endl;
	else if (dynamic_cast<C *>(Test))
		std::cout << "C is the identified type" << std::endl;
	else
		std::cout << "\033[31m Unknown Type Base \033[m" << std::endl;
}

/* ************************************************************************** */
void identify(Base &Test)
{
    try {
		//ここでダウンキャストしている（動物（犬以外かもしれない）を犬として扱っている可能性があり、危険。）
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

/* ************************************************************************** */
int main()
{
	Base *Test = generate();//ここでアップキャストしている（犬を動物としてあつかっている）//新しくBaseインスタンスが作成されたわけではないことに注意！！！
	// Base*は「窓」のようなもの
	// 現実:
	// ┌─────────────────┐
	// │   Aインスタンス   │  ← 実際のオブジェクト
	// └─────────────────┘
	// Base*という窓を通して見ると:
	// ┌─────────────────┐
	// │   Base部分のみ   │  ← Base*で見える範囲(Base部分は、最初からAインスタンスが継承して持っていたもの。)
	// │   見える         │
	// └─────────────────┘
	// でも実際のオブジェクトはAのままだよ！
	// いやいや待て待て...Base部分のみ見えるって、それなんでよ？？？？？？
	// コンパイラの思考プロセス：
	// Base* basePtr = /* Aインスタンスのポインタ */;
	// 1. basePtr の型は Base* である
	// 2. Base* は Base クラスのメンバのみアクセス可能
	// 3. Aインスタンス のメンバへのアクセスは許可しない
	// 4. 実際に何を指しているかは実行時にならないとわからない。でも、型安全性のため、Base のメンバのみ許可する（Base部分のみ見えるという比喩）
	// さらにわかりやすい例↓

	
	// あなたがスマートフォンを持っているとします：
	// // スマートフォン（実際のオブジェクト）
	// class SmartPhone : public Phone {
	// public:
	//     void call() { /* 電話機能 */ }        // Phone由来
	//     void internet() { /* ネット機能 */ }   // SmartPhone独自
	//     void camera() { /* カメラ機能 */ }     // SmartPhone独自
	// };
	// Phone*として見る場合：
	// Phone* device = new SmartPhone();
	// device->call();      // ✅ OK（電話として使える）
	// device->internet();  // ❌ NG（「これは電話だ」という契約なので）
	// device->camera();    // ❌ NG（「これは電話だ」という契約なので）
	// 実際はスマートフォンだけど、「電話として扱う」という約束だから、電話の機能しか使えません。
	// SmartPhone*として見る場合：
	// SmartPhone* phone = static_cast<SmartPhone*>(device);
	// phone->call();      // ✅ OK
	// phone->internet();  // ✅ OK
	// phone->camera();    // ✅ OK
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
