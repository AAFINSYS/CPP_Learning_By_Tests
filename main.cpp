#include <iostream>
#define CATCH_CONFIG_MAIN
#include "catch2.hpp"

#include <string>

std::string fizzbuzz(int const number)
{
    if (number != 0)
    {
        auto m3 = number % 3;
        auto m5 = number % 5;
        if (!m5 && !m3) { return "fizzbuzz"; }
        else if (!m5) { return "buzz"; }
        else if (!m3) { return "fizz"; }
    }
    return std::to_string(number);
}

TEST_CASE("Test with zero", "[classic]")
{
    REQUIRE(fizzbuzz(0) == "0");
}

SCENARIO("BDD test with zero", "[bdd]")
{
    WHEN("The number is 0") {
        THEN("The result is 0") {
            REQUIRE(fizzbuzz(0) == "0");
        }
    }
}

SCENARIO("BDD test any number", "[bdd]")
{
    GIVEN("Any positive number")
    {
        WHEN("The number is 1") {
            THEN("The result is 1") {
                REQUIRE(fizzbuzz(1) == "1");
            }
        }
        WHEN("The number is 2") {
            THEN("The result is 2") {
                REQUIRE(fizzbuzz(2) == "2");
            }
        }
        WHEN("The number is 3") {
            THEN("The result is fizz") {
                REQUIRE(fizzbuzz(3) == "fizz");
            }
        }
        WHEN("The number is 4") {
            THEN("The result is 4") {
                REQUIRE(fizzbuzz(4) == "4");
            }
        }
        WHEN("The number is 5") {
            THEN("The result is buzz") {
                REQUIRE(fizzbuzz(5) == "buzz");
            }
        }
        WHEN("The number is a multiple of 3 only") {
            THEN("The result is buzz") {
                for (int i = 3; i <= 100; i += 3) {
                    if (i % 5) REQUIRE(fizzbuzz(i) == "fizz");
                }
            }
        }
        WHEN("The number is a multiple of 5 only") {
            THEN("The result is buzz") {
                for (int i = 5; i <= 100; i += 5) {
                    if (i % 3) REQUIRE(fizzbuzz(i) == "buzz");
                }
            }
        }
        WHEN("The number is a multiple of 3 and 5") {
            THEN("The result is fizzbuzz") {
                for (int i = 15; i <= 100; i += 15) {
                    REQUIRE(fizzbuzz(i) == "fizzbuzz");
                }
            }
        }
    }
    GIVEN("Any negative number") {
        WHEN("The number is -1") {
            THEN("The result is -1") {
                REQUIRE(fizzbuzz(-1) == "-1");
            }
        }
        WHEN("The number is -2") {
            THEN("The result is -2") {
                REQUIRE(fizzbuzz(-2) == "-2");
            }
        }
        WHEN("The number is -3") {
            THEN("The result is fizz") {
                REQUIRE(fizzbuzz(-3) == "fizz");
            }
        }
        WHEN("The number is -4") {
            THEN("The result is -4") {
                REQUIRE(fizzbuzz(-4) == "-4");
            }
        }
        WHEN("The number is -5") {
            THEN("The result is buzz") {
                REQUIRE(fizzbuzz(-5) == "buzz");
            }
        }
    }
}