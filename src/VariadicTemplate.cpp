
#include "Exercise.hpp"
#include "VariadicTemplate.hpp"
#include <iostream>
#include <cstdint>
#include <string>
#include <typeinfo>
#include <map>

// http://eli.thegreenplace.net/2014/variadic-templates-in-c/

template<typename T>
T adder(T v) {
    std::cout << __PRETTY_FUNCTION__ << "\n";
    return v;
}

// As there's no actual recursion involved, all we have is a sequence of function calls pre-generated at compile-time.
template<typename T, typename... Pack>
T adder(T first, Pack... pack) {
    // template arguments are peeled off one by one until the base case is hit.
    std::cout << __PRETTY_FUNCTION__ << "\n";
    return first + adder(pack...);
}

template <class... Ts> struct tuple {};

template <class T, class... Ts>
struct tuple<T, Ts...> : tuple<Ts...> {
  tuple(T t, Ts... ts) : tuple<Ts...>(ts...), tail(t) {}

  T tail;
};

template <size_t, class> struct elem_type_holder;

template <class T, class... Ts>
struct elem_type_holder<0, tuple<T, Ts...>> {
  typedef T type;
};

template <size_t k, class T, class... Ts>
struct elem_type_holder<k, tuple<T, Ts...>> {
  typedef typename elem_type_holder<k - 1, tuple<Ts...>>::type type;
};

template <size_t k, class... Ts>
typename std::enable_if<
    k == 0, typename elem_type_holder<0, tuple<Ts...>>::type&>::type
get(tuple<Ts...>& t) {
  return t.tail;
}

template <size_t k, class T, class... Ts>
typename std::enable_if<
    k != 0, typename elem_type_holder<k, tuple<T, Ts...>>::type&>::type
get(tuple<T, Ts...>& t) {
  tuple<Ts...>& base = t;
  return get<k - 1>(base);
}

template <template <typename, typename...> class ContainerType,
          typename ValueType, typename... Args>
void print_container(const ContainerType<ValueType, Args...>& c) {
  for (const auto& v : c) {
    std::cout << v << ' ';
  }
  std::cout << '\n';
}

// Implement << for pairs: this is needed to print out mappings where range
// iteration goes over (key, value) pairs.
template <typename T, typename U>
std::ostream& operator<<(std::ostream& out, const std::pair<T, U>& p) {
  out << "[" << p.first << ", " << p.second << "]";
  return out;
}

void VariadicTemplate::execute()
{
    long sum = adder(1, 2, 3, 8, 7);
    std::cout << "VariadicTemplate::execute sum " << sum << std::endl;

    tuple<double, uint64_t, const char*> t1(12.2, 42, "big");

    std::cout << std::dec;
    int const a = get<0>(t1);
    std::cout << "a: " << a << std::endl;
    std::cout << "0th elem is " << get<0>(t1) << "\n";
    std::cout << "1th elem is " << get<1>(t1) << "\n";
    std::cout << "2th elem is " << get<2>(t1) << "\n";

    get<1>(t1) = 103;

    std::cout << "1th elem is " << get<1>(t1) << "\n";

    std::map<std::string, int> msi{{"foo", 42}, {"bar", 81}, {"bazzo", 4}};
    print_container(msi);

    log();
}
