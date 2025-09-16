#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <exception>
 #include <stdlib.h>

template< typename T >
class Array
{
	private:
		T*              _array;     // 動的配列のポインタ
		unsigned int    _size;      // 配列のサイズ

	public:
		// デフォルトコンストラクタ：空配列を作成
		Array() : _array(NULL), _size(0)
		{
			std::cout << "Default Constructor called: Created empty Array of size 0" << std::endl;
			this->_array = new T[this->_size];
		}
		// サイズ指定コンストラクタ：指定サイズの配列を作成
		Array(unsigned int size) : _array(NULL), _size(size)
		{
			std::cout << "Constructor for an Array of size " << size << " Array is Created" << std::endl;
			this->_array = new T[this->_size];
			for (unsigned int i = 0; i < this->_size; i++)
				this->_array[i] = T();  // T()で安全で予測可能な初期化。(Tがintなら０，charなら'\0'...というように初期化される。)
		}
		// 既存の配列をコピーして新しい配列を作成
		Array(const Array &src) : _array(NULL), _size(src._size)
		{
			std::cout << "Copy Constructor called" << std::endl;
			this->_array = new T[this->_size];
			for (unsigned int i = 0; i < this->_size; i++)
				this->_array[i] = src._array[i];
		}
		~Array()
		{
			std::cout << "Destructor called" << std::endl;
			delete[] this->_array;
		}
		// 代入演算子：既存配列に別の配列の内容を代入
		Array& operator=(const Array &src)
		{	
			if (this == &src)
				return (*this);
			delete[] this->_array;
			this->_size = src._size;
			this->_array = new T[this->_size];
			for (unsigned int i = 0; i < this->_size; i++)
				this->_array[i] = src._array[i];
			return (*this);
		}
		// 添字演算子（非const版）：配列要素への読み書きアクセス
		T& operator[](unsigned int index)
		{
			if (index >= this->_size)
			{
				std::cout << "index:" << index << std::endl;
				throw InvalidIndexException();
			}
			return this->_array[index];
		}
		// 添字演算子（const版）：配列要素への読み取り専用アクセス
		const T& operator[](unsigned int index) const
		{
			// 範囲外アクセスのチェック
			if (index >= this->_size) {
				std::cout << "index:" << index << std::endl;
				throw InvalidIndexException();
			}
			return this->_array[index];
		}
		unsigned int size() const
		{
			return (this->_size);
		}
		// 不正なインデックスアクセス時の例外
		class InvalidIndexException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Error: Invalid index");
				}
		};
};

#endif