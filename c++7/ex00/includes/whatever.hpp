#ifndef WHATEVER_HPP
# define WHATEVER_HPP

//以下で使用されている、T_MAX、T_MIN、T_SWAPは、名前が全て同じでも問題なくコンパイルされるし実行時にも問題無い。
//ただ、読む時理解しにくいので名前はわかりやすくって感じ。

// そもそも関数テンプレートってなぜ作る必要が？
// int、float、stringなど、異なる型に対して同じロジックの関数を何個も書くのは非効率
// テンプレートなら1つの定義で全ての型に対応できる
// コンパイル時に、使用された型に応じて実際の関数が自動生成される
//なぜテンプレートはヘッダファイルに書くのか？
//テンプレートは「型が決まった時点」で実際のコードが生成される
// myFunc<int>が必要になった時、コンパイラはT=intとして実装を見つける必要がある
// ヘッダに書いておけば、#includeした時点で実装が見える
// .cppにも書けるけど、型を指定したインスタンス化が必要。
template< typename T_MAX >// この宣言は max関数だけに適用される
const T_MAX	&max(const T_MAX &x ,const T_MAX &y)
{
	return (x > y ? x : y);// if(x == y) -> return(y);
}

template< typename T_MIN >// この宣言は min関数だけに適用される
const T_MIN	&min(const T_MIN &x ,const T_MIN &y)
{
	return (x < y ? x : y);// if(x == y) -> return(y);
}

template< typename T_SWAP >// この宣言は swap関数だけに適用される
void swap(T_SWAP &x, T_SWAP &y)
{
	T_SWAP temp = x;
	x = y;
	y = temp;
}

//https://zenn.dev/kojiban_cpp/articles/660ef6893cc762
// template <class T>
// T add(const T& a, const T& b) {
//     return a + b;
// }
// add関数の引数にconstキーワードが付いたのと参照を示すキーワード「&」がついています。こうすることで、addの引数a, bは値渡しではなく、参照渡しとなり関数呼び出し時の引数のコピーコストを削減することができます（int型単体の場合は参照渡しよりもコピーの方がよいそうですが）。参照渡しということはこのadd関数は万が一にでも引数a, bを変更した場合、関数呼び出し元のa, bの値も変わってしまう可能性があるということです。これを防ぐためにconstをつけることでadd関数内では引数a, bを変更できないように設定しています。関数の引数に値を設定するときに値渡しかポインタ渡しか参照渡しかという議論が度々あがっているようですが、筆者はよく参照渡しを使います。これは無駄なコピーが発生する値渡しよりも参照渡しの方が大体の場面で優れているからです。参照渡しをする場合はconstをつけるべきかよく考えましょう。その引数が絶対に変更されるべきではない場合はconstをつけ、変更したい場合はconstをつけるべきではありません。どちらかわからない場合はとりあえずconstをつけ、変更する必要に迫られた場合のみconstを外すくらいの心構えでよいかと思われます。
//機能的差異: テンプレートパラメータではclassとtypenameは全く同じ意味を持つ。　"template <class T>"=="template <typename T>"
// 歴史: classが先、typenameが後から追加
// 推奨: 現代ではtypenameを使う方が一般的
// 理由: 意味が明確で、一貫性があるため
#endif