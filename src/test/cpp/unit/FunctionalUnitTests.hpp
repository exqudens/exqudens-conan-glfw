#pragma once

#include <string>
#include <exception>

#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <exqudens/log/api/Logging.hpp>

#include "TestUtils.hpp"
#include "GLFW/glfw3.h"

class FunctionalUnitTests: public testing::Test {

    public:

        inline static const char* LOGGER_ID = "FunctionalUnitTests";

};

TEST_F(FunctionalUnitTests, test_1) {
    try {
        std::string testGroup = testing::UnitTest::GetInstance()->current_test_info()->test_suite_name();
        std::string testCase = testing::UnitTest::GetInstance()->current_test_info()->name();
        EXQUDENS_LOG_INFO(LOGGER_ID) << "bgn";

        int expected = 1;
        EXQUDENS_LOG_INFO(LOGGER_ID) << "expected: " << expected;
        int actual = glfwInit();
        EXQUDENS_LOG_INFO(LOGGER_ID) << "actual: " << actual;

        ASSERT_EQ(expected, actual);

        glfwTerminate();

        EXQUDENS_LOG_INFO(LOGGER_ID) << "end";
    } catch (const std::exception& e) {
        std::string errorMessage = TestUtils::toString(e);
        std::cout << LOGGER_ID << " ERROR: " << errorMessage << std::endl;
        FAIL() << errorMessage;
    }
}
