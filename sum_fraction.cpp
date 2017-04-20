// this is implematation of https://monoinfinito.wordpress.com/series/introduction-to-c-template-metaprogramming/
// and some my modyfications

#include<iostream>

template <int N, int D> struct Frak {
        static const long Num = N;
        static const long Den = D;
};

template <int N, typename F> struct ScalarMultiplication {
    typedef Frak<N*F::Num, N*F::Den> result;
};

template <int X, int Y>   struct MCD {
        static const long result = MCD<Y, X % Y>::result;
};

template <int X> struct MCD<X, 0> {
        static const long result = X;
};

template <class F> struct Simpl {
        static const long mcd = MCD<F::Num, F::Den>::result;
        typedef Frak< F::Num / mcd, F::Den / mcd > result;
};

template <typename X1, typename Y1> struct SameBase {
    typedef typename ScalarMultiplication< Y1::Den, X1>::result X;
    typedef typename ScalarMultiplication< X1::Den, Y1>::result Y;
};

template <typename X, typename Y> struct Sum {
    typedef SameBase<X, Y> B;
    static const long Num = B::X::Num + B::Y::Num;
    static const long Den = B::Y::Den; // == B::X::Den
    typedef typename Simpl< Frak<Num, Den> >::result result;
};

template <typename Out> struct Calkowita {
    static const long calkowita = Out::Num / Out::Den;
    static const long reszta_licznik = Out::Num % Out::Den;
    static const long mianownik = Out::Den;
};

int main()
{
    typedef Frak<1,2> f1;
    typedef Frak<3,4> f2;
    std::cout << f1::Num << "/" << f1::Den << "+" << std::endl;
    std::cout << f2::Num << "/" << f2::Den << std::endl;
    typedef Sum<f1, f2>::result output;
    std::cout <<" = "<< output::Num << "/" << output::Den << std::endl;

    typedef Calkowita<output> d;
//    std::cout << "d::calkowita" << "sdfds" << std::endl;
    std::cout << "czyli \n" <<  d::calkowita << " i "
                          << d::reszta_licznik << "/" << d::mianownik
                          << std::endl;
return 0;
}
