//
//  LoggingAPITest.cpp
//  libsettingapi
//
//  Created by Andreoletti David on 3/31/12.
//  Copyright 2012 IO Stark. All rights reserved.
//

#include <string>
#include <vector>
#include "boost/test/unit_test.hpp"
#include "./loggingapi/LoggingAPI.h"
#include "./loggingapi/loggers/LoggerInterface.h"
#include "./loggingapi/loggers/Logger.h"

namespace loggingapi {
namespace test {

const std::string kLoggerName0 = "logger0";
const std::string kLoggerName1 = "logger1";

typedef loggingapi::loggers::LoggerInterface LoggerI;

struct LoggingAPIFixture {
    LoggingAPIFixture() {}
    ~LoggingAPIFixture() {
        LoggingAPI::removeLogger(kLoggerName0);
        LoggingAPI::removeLogger(kLoggerName1);
    }
};

BOOST_FIXTURE_TEST_SUITE(LoggingAPITestSuite, LoggingAPIFixture)

BOOST_AUTO_TEST_CASE(addLogger_LoggerNotYetAdded) {
    // Add logger
    LoggerI* logger0 = static_cast<LoggerI*> (new loggers::Logger());
    logger0->setName(kLoggerName0);
    bool isLoggerAdded = LoggingAPI::addLogger(logger0);
    BOOST_REQUIRE(isLoggerAdded == true);
}

BOOST_AUTO_TEST_CASE(addLogger_LoggerAlreadyAdded) {
    // Add logger
    LoggerI* logger0 = static_cast<LoggerI*> (new loggers::Logger());
    logger0->setName(kLoggerName0);
    bool isLoggerAdded = LoggingAPI::addLogger(logger0);
    BOOST_REQUIRE(isLoggerAdded == true);
    // Add logger again
    isLoggerAdded = LoggingAPI::addLogger(logger0);
    BOOST_REQUIRE(isLoggerAdded == false);
}

BOOST_AUTO_TEST_CASE(getLogger_NoLoggerFound) {
    // Get logger defined
    LoggerI* logger0 = LoggingAPI::getLogger(kLoggerName0);
    BOOST_REQUIRE(logger0 == NULL);
}

BOOST_AUTO_TEST_CASE(getLogger_LoggerFound) {
    // Add logger
    LoggerI* logger0 = static_cast<LoggerI*> (new loggers::Logger());
    logger0->setName(kLoggerName0);
    bool isLoggerAdded = LoggingAPI::addLogger(logger0);
    BOOST_REQUIRE(isLoggerAdded == true);
    // Get Logger
    LoggerI* logger1 = LoggingAPI::getLogger(kLoggerName0);
    BOOST_REQUIRE(logger1 != NULL);
}

BOOST_AUTO_TEST_CASE(removeLogger_LoggerFound) {
    // Add logger
    LoggerI* logger0 = static_cast<LoggerI*> (new loggers::Logger());
    logger0->setName(kLoggerName0);
    bool isLoggerAdded = LoggingAPI::addLogger(logger0);
    BOOST_REQUIRE(isLoggerAdded == true);
    // Remove logger
    LoggerI* logger1 = LoggingAPI::removeLogger(kLoggerName0);
    BOOST_REQUIRE(logger1 != NULL);
    // Confirm logger is removed
    LoggerI* logger2 = LoggingAPI::removeLogger(kLoggerName0);
    BOOST_REQUIRE(logger2 == NULL);
    delete logger1;
}

BOOST_AUTO_TEST_CASE(removeLogger_LoggerNotFound) {
    // Remove logger
    LoggerI* logger0 = LoggingAPI::removeLogger(kLoggerName0);
    BOOST_REQUIRE(logger0 == NULL);
}

BOOST_AUTO_TEST_SUITE_END()

}}  // namespaces
