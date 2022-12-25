/*
 * Framework Set-up
*/

#ifndef CATCH_CONFIG_MAIN
#  define CATCH_CONFIG_MAIN
#endif

#include "catch.hpp"

/*
 * Necessary user header files and library includes
*/

#include "BankApp.hpp"
/*
 * Test cases
*/

TEST_CASE("Bank Account app getAmount()") {
  std::vector<double> accounts = {1001, 2002, 3002, 4001};
  BankApp bankApp(accounts);

  REQUIRE(accounts.size() == 4);

  SECTION("Negative index should throw") {
    CHECK_THROWS(bankApp.getAmount(-1));
  }

  SECTION("Index greater than account size should throw") {
    CHECK_THROWS(bankApp.getAmount(4));
  }

  SECTION("Should fetch the amount for account id 1") {
    REQUIRE(bankApp.getAmount(1) == 2002);
  }
}