// #include "../includes/PmergeMe.hpp"

// // ================= コンストラクタ =================
// template <typename Container>
// PmergeMe<Container>::PmergeMe() {}

// template <typename Container>
// PmergeMe<Container>::PmergeMe(char **av) {
//     for (int i = 0; av[i]; ++i) {
//         std::istringstream iss(av[i]);
//         ValueType num;
//         if (!(iss >> num)) {
//             throw std::invalid_argument("Invalid number in input");
//         }
//         container.push_back(num);
//     }
// }

// // ================= ソート制御 =================
// template <typename Container>
// void PmergeMe<Container>::sort_time() {
//     start_ = std::clock();
//     sort();
//     end_ = std::clock();
// }

// template <typename Container>
// void PmergeMe<Container>::sort() {
//     sort(container);
// }

// // ================= イテレータ =================
// template <typename Container>
// typename PmergeMe<Container>::Iterator PmergeMe<Container>::begin() {
//     return container.begin();
// }

// template <typename Container>
// typename PmergeMe<Container>::Iterator PmergeMe<Container>::end() {
//     return container.end();
// }

// // ================= 内部関数 =================
// template <typename Container>
// float PmergeMe<Container>::time() {
//     return static_cast<float>(end_ - start_) / CLOCKS_PER_SEC;
// }

// template <typename Container>
// int PmergeMe<Container>::Jacobsthal(int k) {
//     if (k == 0) return 0;
//     if (k == 1) return 1;
//     return Jacobsthal(k - 1) + 2 * Jacobsthal(k - 2);
// }

// template <typename Container>
// size_t PmergeMe<Container>::count_word_and_check(std::string &str) {
//     std::istringstream iss(str);
//     size_t count = 0;
//     ValueType tmp;
//     while (iss >> tmp) {
//         count++;
//     }
//     return count;
// }

// template <typename Container>
// void PmergeMe<Container>::sort(Container &vec) {
//     std::sort(vec.begin(), vec.end());
// }

// template <typename Container>
// std::string PmergeMe<Container>::container_type() {
//     if (typeid(Container) == typeid(std::vector<ValueType>))
//         return "std::vector";
//     else if (typeid(Container) == typeid(std::deque<ValueType>))
//         return "std::deque";
//     return "unknown";
// }

// template <typename Container>
// void PmergeMe<Container>::insert(Container &main, Container &pend,
//                                  ValueType odd, Container &left, Container &vec,
//                                  bool is_odd, int order) {
//     // Ford-Johnson の insert ロジックを書くべき場所
//     main.insert(main.end(), pend.begin(), pend.end());
//     if (is_odd) {
//         main.push_back(odd);
//     }
// }

// // ================= operator<< =================
// template <typename Container>
// std::ostream& operator<<(std::ostream &os, const PmergeMe<Container> &obj) {
//     for (typename Container::const_iterator it = obj.begin();
//          it != obj.end(); ++it) {
//         os << *it << " ";
//     }
//     return os;
// }

// // ================= 明示的インスタンス化 =================
// template class PmergeMe<std::vector<int> >;
// template class PmergeMe<std::deque<int> >;

// template std::ostream& operator<<(std::ostream&, const PmergeMe<std::vector<int> > &);
// template std::ostream& operator<<(std::ostream&, const PmergeMe<std::deque<int> > &);
