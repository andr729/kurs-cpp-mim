#include <cstdint>
#include <iostream> 
#include <utility> 
#include <string> 
#include <vector> 

namespace first {
    struct Q {
        Q() {
            std::cerr << "Q created!\n";
        }
    };

    struct T {
        T(Q q) {}
    };

    void foo() {
        T t(Q());
    }

    // A: Q is created!
    // B: Q is not created!
    // C: compilation error
    // D: implementation defined
}


namespace second {
    struct MoveMe {
        MoveMe() {
            std::cerr << "MoveMe created!\n";
        }
        MoveMe(const MoveMe&) {
            std::cerr << "MoveMe copied!\n";
        };
        MoveMe(MoveMe&&) {
            std::cerr << "MoveMe moved!\n";
        };
    };

    void foo() {
        MoveMe m1;
        
        std::move(m1);
    }

    // A: MoveMe created! MoveMe moved!
    // B: MoveMe created! MoveMe copied!
    // C: MoveMe created!
    // D: compilation error
}

namespace third {

    void foo() {
        std::string s;

        s = 42.7;

        std::cout << s << "\n";

        // A: 42.7 is printed
        // D: 42 is printed
        // B: * is printed
        // C: compilation error
    }

}


namespace fourth {
    void foo() {
        uint64_t minus_one = -1;
        int64_t zero = 0;

        std::cout << (minus_one < zero) << "\n";

        // A: 1 is printed (true)
        // B: 0 is printed (false)
        // C: implementation defined
        // D: undefined behavior
    }
}


namespace fifth {
    void foo() {
        std::vector<int> v1(3, 5);
        std::vector<int> v2{3, 5};

        std::cout << "v1: ";
        for (int i : v1) std::cout << i << " ";
        std::cout << "\n";

        std::cout << "v2: ";
        for (int i : v2) std::cout << i << " ";
        std::cout << "\n";

        // A: v1: 5 5 5 
        //    v2: 5 5 5
        
        // B: v1: 5 5 5 
        //    v2: 3 5

        // C: v1: 3 5 
        //    v2: 3 5 5

        // D: v1: 3 5 
        //    v2: 3 5

    }
}

int main() {
    first::foo();
    second::foo();
    third::foo();
    fourth::foo();
    fifth::foo();
    return 0;
}