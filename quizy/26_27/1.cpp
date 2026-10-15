#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

namespace first {

    void foo(bool b) {
        std::cout << "bool\n";
    }
    void foo(std::string) {
        std::cout << "string\n";
    }

    void test() {
        foo("abc");
    }
}

namespace second {

    void foo(int&&) {
        std::cout << "int&&\n";
    }
    void foo(float&&) {
        std::cout << "float&&\n";
    }
    
    void test() {
        int i = 1;
        foo(i);
    }
}

namespace third {

    // using T = int;
    typedef int T1;
    int typedef T2;

    // typedefs will return
    // don't use typedefs

    void test() {
        T1 a = 1;
        T2 b = 2;
    }
    
}

namespace fourth {

    void test() {
        std::vector<int> v{1, 2, 3, 4};

        auto _ = std::remove_if(v.begin(), v.end(), [](const int& x) { return x % 2 == 0; });

        for (int x : v) {
            std::cout << x << " ";
        }
        std::cout << "\n";
    }
}

int main() {
    first::test();
    second::test();
    third::test();
    fourth::test();
}

