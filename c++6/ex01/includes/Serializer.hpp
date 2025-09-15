
#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <stdint.h> 
# include "Data.hpp"

class Serializer
{
	private:
		Serializer();
		Serializer(const Serializer &src);
		Serializer &operator=(const Serializer &src);
		~Serializer();
	public:
        //　Dataポインタを符号なし整数型 uintptr_t に変換（シリアライズ）
        static uintptr_t serialize(Data* ptr);       // ← staticが必須（static = インスタンス不要）
        // 符号なし整数型 uintptr_tをポインタに戻す（デシリアライズ）
        static Data* deserialize(uintptr_t raw);     // ← staticが必須（static = インスタンス不要）
        // staticなぜ必要なん？　-> "Serializer s;"のようにインスタンス化してたらstatic不要だよ。-> "uintptr_t result = s.serialize(data);"って感じで。
        //　uintptr_t result = Serializer::serialize(data);  <- 今回のコレは、クラス名経由で直接呼び出ししてる。
};
#endif