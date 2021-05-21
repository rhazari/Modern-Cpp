#include "perf.h"
#include "email.ex1.h"
#include "emailTestHelpers.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

Email nextEmail() {
    static int id = 0;
    return Email{"User" + std::to_string(++id) + "@mynicedomain.com"};
}

int main(int argc, char **argv) {
    Perf perf;
    int numElems = argc > 1 ? std::atoi(argv[1]) : 100000;

    // initialize with a few basic email addresses:
    std::vector<Email> coll{
        std::string{"nico@josuttis.de"},
        std::string{"nico@josuttis.com"},
        std::string{},
        std::string{"invalid email"},
    };

    // insert additional emails (number from command line):
    perf.reset();
    for (int i = 0; i < numElems; ++i) {
        coll.push_back(nextEmail());
    }
    perf.diff("after init");
    print(coll.begin(), coll.end());

    // sort elements:
    perf.reset();
    std::sort(coll.begin(), coll.end(), [](const Email &lhs, const Email &rhs)
              { return lhs.getValue() < rhs.getValue(); });
    perf.diff("after sort");
    print(coll.begin(), coll.end());
}