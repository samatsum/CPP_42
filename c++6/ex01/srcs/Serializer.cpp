#include "../includes/Serializer.hpp"

/* ************************************************************************** */
Serializer::Serializer()
{
	std::cout << "Serializer default constructor called" << std::endl;
}

Serializer::Serializer(const Serializer &src)
{
	std::cout << "Serializer copy constructor called" << std::endl;
	*this = src;
}

Serializer::~Serializer()
{
	std::cout << "Serializer deconstructor called" << std::endl;
}

Serializer &Serializer::operator=(const Serializer &src)
{
	std::cout << "Serializer assignation operator called" << std::endl;
	if (this == &src)
		return *this;
	return *this;
}

/* ************************************************************************** */
//　reinterpret_castはほとんど制限が無い＝＝非常に自由＝＝非常に危険！取り扱い注意！
// reinterpret_cast を「使わざるを得ない場面」が来るまで使うな。
//　以下の２例とかで使用？
// ポインタのアドレス値を整数型の変数に格納
// double * から int * など違う型のポインタの変換
uintptr_t	Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data	*Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}