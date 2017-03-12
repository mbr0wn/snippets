#include <iostream>
#include <string>
#include <tuple>

int test_func(std::string s, double d, int i)
{
    std::cout << s << std::endl;
    std::cout << d << std::endl;
    std::cout << i << std::endl;
    return 5;
}

template <size_t n_tup_args>
struct call_helper
{
    template <typename Functor, typename... ArgsT, typename... ArgsF>
    static decltype(auto) call(Functor f, std::tuple<ArgsT...> args_t, ArgsF&&... args_f)
    {
        return call_helper<n_tup_args-1>::call(
                f,
                args_t,
                std::get<n_tup_args-1>(args_t),
                std::forward<ArgsF>(args_f)...
        );
    }
};

template <>
struct call_helper<0>
{
    template <typename Functor, typename... ArgsT, typename... ArgsF>
    static decltype(auto) call(Functor f, std::tuple<ArgsT...>        , ArgsF&&... args_f)
    {
        return f(std::forward<ArgsF>(args_f)...);
    }
};

template <typename Functor, typename... Args>
decltype(auto) call(Functor f, std::tuple<Args...> args) {
    return call_helper<sizeof...(Args)>::call(f, std::forward<std::tuple<Args...>>(args));
}

int main(void)
{
    auto T = std::make_tuple(std::string("foo"), 23.5, 5);
    auto R = call(&test_func, T);
    std::cout << R << std::endl;

    return 0;
}
