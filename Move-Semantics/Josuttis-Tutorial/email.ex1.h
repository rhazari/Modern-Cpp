#pragma once

#include <string>

class Email {
public:
    enum class State {
        none,
        set,
        valid
    };

private:
    std::string _value;
    State _state{State::none};

public:
    // constructors:
    Email() = default;

    Email(const std::string &e)
        : _value{e} {
        checkState();
    }

    // getter:
    std::string getValue() const {
        return _value;
    }

    // other:
    void checkState(); // set state according to value
    friend std::ostream &operator<<(std::ostream &strm, const Email &e);
};

inline void Email::checkState() {
    if (_value.empty()) {
        _state = State::none;
    }
    else if (_value.find("@") != std::string::npos) {
        _state = State::valid;
    }
    else {
        _state = State::set;
    }
}

inline std::ostream &operator<<(std::ostream &strm, const Email &e) {
    switch (e._state) {
    case Email::State::none:
        strm << "NONE";
        break;
    case Email::State::set:
        strm << '<' << e._value << '>';
        break;
    case Email::State::valid:
        strm << '<' << e._value << ">OK";
        break;
    }
    return strm;
}