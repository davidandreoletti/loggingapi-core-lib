//
//  LoggingTest.cpp
//  libloggingapi
//
//  Created by Andreoletti David on 3/31/12.
//  Copyright 2012 IO Stark. All rights reserved.
//

#include <string>
#include <vector>
#include "boost/test/unit_test.hpp"
#include "loggingapi/loggers/LoggerInterface.h"
#include "loggingapi/loggers/Logger.h"
#include "loggingapi/attributes/AttributeInterface.h"
#include "loggingapi/attributes/Attribute.h"

namespace test {
namespace loggingapi {
namespace loggers {

typedef ::loggingapi::loggers::LoggerInterface LoggerI;
typedef ::loggingapi::attributes::AttributeInterface AttrI;
typedef ::loggingapi::attributes::Attribute Attr;

const std::string kLoggerName0 = "logger0";
const std::string kAttributeKey0 = "attrKey0";

struct LoggerFixture {
    LoggerI* logger0;
    LoggerFixture() {
        logger0 = static_cast<LoggerI*>(new ::loggingapi::loggers::Logger());
    }
    ~LoggerFixture() {
        delete logger0;
    }
};

BOOST_FIXTURE_TEST_SUITE(LoggerTestSuite, LoggerFixture)

BOOST_AUTO_TEST_CASE(setName) {
    logger0->setName(kLoggerName0);
    BOOST_REQUIRE(logger0->getName().compare(kLoggerName0) == 0);
}

BOOST_AUTO_TEST_CASE(addFilter_FilterNotYedAdded) {
    AttrI* attr0 = static_cast<AttrI*> (new Attr());
    attr0->setKey(kAttributeKey0);
    bool isFilterAdded = logger0->addFilter(attr0);
    BOOST_REQUIRE(isFilterAdded == true);
}

BOOST_AUTO_TEST_CASE(addFilter_FilterAlreadyAdded) {
    AttrI* attr0 = static_cast<AttrI*> (new Attr());
    attr0->setKey(kAttributeKey0);
    bool isFilterAdded = logger0->addFilter(attr0);
    BOOST_REQUIRE(isFilterAdded == true);
    isFilterAdded = logger0->addFilter(attr0);
    BOOST_REQUIRE(isFilterAdded == false);
}

BOOST_AUTO_TEST_CASE(getFilter_NoFilter) {
    AttrI* attr0 = logger0->getFilter(kAttributeKey0);
    BOOST_REQUIRE(attr0 == NULL);
}

BOOST_AUTO_TEST_CASE(getFilter_FilterExists) {
    // Add filter
    AttrI* attr0 = static_cast<AttrI*> (new Attr());
    attr0->setKey(kAttributeKey0);
    bool isFilterAdded = logger0->addFilter(attr0);
    BOOST_REQUIRE(isFilterAdded == true);
    // Get filter
    AttrI* attr1 = logger0->getFilter(kAttributeKey0);
    BOOST_REQUIRE(attr1 != NULL);
    BOOST_REQUIRE(attr1->getKey().compare(kAttributeKey0) == 0);
}

BOOST_AUTO_TEST_CASE(removeFilter_FilterDoesNOTExist) {
    AttrI* attr0 = logger0->removeFilter(kAttributeKey0);
    BOOST_REQUIRE(attr0 == NULL);
}

BOOST_AUTO_TEST_CASE(removeFilter_FilterExists) {
    // Add filter
    AttrI* attr0 = static_cast<AttrI*> (new Attr());
    attr0->setKey(kAttributeKey0);
    bool isFilterAdded = logger0->addFilter(attr0);
    BOOST_REQUIRE(isFilterAdded == true);
    // Get filter
    AttrI* attr1 = logger0->removeFilter(kAttributeKey0);
    BOOST_REQUIRE(attr1 != NULL);
    BOOST_REQUIRE(attr1->getKey().compare(kAttributeKey0) == 0);
    AttrI* attr2 = logger0->removeFilter(kAttributeKey0);
    BOOST_REQUIRE(attr2 == NULL);
    delete attr1;
}

BOOST_AUTO_TEST_CASE(log) {
    AttrI* attr0 = logger0->removeFilter(kAttributeKey0);
    BOOST_REQUIRE(attr0 == NULL);
}

BOOST_AUTO_TEST_SUITE_END()

}}}  // namespaces
