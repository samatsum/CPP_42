#ifndef ITER_HPP
# define ITER_HPP

#include <cstddef>
#include <iostream>
#include <cctype>
#include <string>
// T *arrayは「ポインタ」であることが確定しているため、NULLチェックOK。
// FをNULLチェックしない理由は以下。
// Fは関数ポインタかもしれない
// Fは関数名かもしれない
// Fはテンプレート関数のインスタンスかもしれない
// Fは関数オブジェクト（ラムダなど）かもしれない
// NULLチェックできないものをチェックしようとすると、エラーになるぞ。
template< typename T, typename F >
void iter(T *array, size_t arr_len, F func)
{
    if (array == NULL)
        return;
    for (size_t i = 0; i < arr_len; i++)
        func(array[i]);
}

// const配列用のオーバーロード
template< typename T, typename F >
void iter(const T *array, size_t arr_len, F func)
{
    if (array == NULL)
        return;
    for (size_t i = 0; i < arr_len; i++)
        func(array[i]);
}

// func が void func(int& x) なら、array[i] は int& として渡される
// func が void func(const int& x) なら、array[i] は const int& として渡される
// func が void func(int x) なら、array[i] は値（コピー）として渡される
#endif