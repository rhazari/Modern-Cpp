#include "perf.h"
#include "email.ex2.h"
#include "emailTestHelpers.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

Email nextEmail() {
    static int id = 0;
    return Email{"User" + std::to_string(++id) + "@mynicedomain.com"};
}

// helper to call print() for a full collection:
template <typename T>
//void print(const T& coll) {  // looses constness
//void print(T& coll) {        // doesn't bind to prvalues
void print(T&& coll) {         // OK (universal/forwarding reference)
    print(coll.begin(), coll.end());
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

    // iterate over first character of a temporary email address:
    std::cout << "chars of tmp email: ";
    for (char c : nextEmail().getValue()) {
        std::cout << ' ' << c;
    }
    std::cout << '\n';

    // remove elements with ".com":
    perf.reset();
    std::remove_if(coll.begin(), coll.end(),[] (const Email& e) {
                    return e.getValue().find(".com") != std::string::npos;
                    });
    perf.diff("after remove_if");
    print(coll.begin(), coll.end());

    print(coll);
    print(std::vector<Email>{});
    const std::vector<Email> cv{};
    print(cv);
}