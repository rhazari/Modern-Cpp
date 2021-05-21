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

    // Email(const std::string& e)
    // : _value{e} {
    //     checkState();
    // }

    Email(std::string e)
        : _value{std::move(e)} {
        checkState();
    }

    // getter:
    // std::string getValue() const {
    //     return _value;
    // }
    // Fast getter for most purposes
    const std::string &getValue() const & {
        return _value;
    }

    // For temporaries
    std::string getValue() && {
        return std::move(_value);
    }

    // disable move semantics:
    // Email(Email&&) = delete;             // ERROR: disables also fallback
    // Email& operator=(Email&&) = delete;  // ERROR: disables also fallback
    Email(const Email&) = default;             // disables move (fallback available)
    Email& operator=(const Email&) = default;  // disables move (fallback available)

    // implement move semantics:
    Email(Email&& e)  noexcept
        : _value{std::move(e._value)}, _state{e._state} {
        e._value.clear();
        e._state = State::none;
    }

    Email& operator= (Email&& e) noexcept {
        _value = std::move(e._value);
        _state = e._state;
        e._value.clear();
        e._state = State::none;
        return *this;
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