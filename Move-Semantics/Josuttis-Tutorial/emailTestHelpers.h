#pragma once

#include <iostream>
#include <string>
#include <vector>

// print first and last 5 elements of a NON-CONST collection:
void print(typename std::vector<Email>::iterator beg,
           typename std::vector<Email>::iterator end) {
    std::cout << "\nNON-CONST elems:\n";
    std::size_t size = end - beg;
    std::size_t num = 0;
    for (auto pos = beg; pos != end; ++pos, ++num) {
        if (num < 4 || num >= size - 4) {
            std::cout << "  " << *pos << '\n';
        }
        if (num == 4 && size > 4 * 2) {
            std::cout << "  ..." << '\n';
        }
    }
}

// print first and last 5 elements of a CONST collection:
void print(typename std::vector<Email>::const_iterator beg,
           typename std::vector<Email>::const_iterator end)
{
    std::cout << "\nCONST elems:\n";
    std::size_t size = end - beg;
    std::size_t num = 0;
    for (auto pos = beg; pos != end; ++pos, ++num) {
        if (num < 4 || num >= size - 4) {
            std::cout << "  " << *pos << '\n';
        }
        if (num == 4 && size > 4 * 2) {
            std::cout << "  ..." << '\n';
        }
    }
}