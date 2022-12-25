#include "BankApp.hpp"

#include <stdexcept>
#include <iostream>

BankApp::BankApp(const std::vector<double>& accounts): _accounts(accounts){}

double BankApp::getAmount(const int& accountId) const{
  if (accountId < 0 || _accounts.size() == 0 || accountId >= static_cast<int>(_accounts.size())){
      throw std::invalid_argument("Invalid Argument");
  }
  return _accounts[accountId];
}

