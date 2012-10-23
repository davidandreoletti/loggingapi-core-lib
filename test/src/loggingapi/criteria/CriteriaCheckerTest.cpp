//
//  CriteriaCheckerTest.cpp
//  libloggingapi
//
//  Created by Andreoletti David on 3/31/12.
//  Copyright 2012 IO Stark. All rights reserved.
//

#include <string>
#include <vector>
#include "boost/test/unit_test.hpp"
#include "loggingapi/criteria/CriteriaChecker.h"
#include "loggingapi/attributes/AttributeInterface.h"
#include "loggingapi/attributes/Attribute.h"
#include "loggingapi/LoggingAPITrivial.h"

namespace test {
namespace loggingapi {
namespace criteria {

typedef ::loggingapi::attributes::AttributeInterface AttrI;
typedef ::loggingapi::attributes::Attribute Attr;
typedef ::loggingapi::criteria::CriteriaChecker CC;

struct CriteriaCheckerFixture {
    CC* cc;
    std::vector<AttrI*> ecs;  // Expected criteria
    std::vector<AttrI*> ccs;  // Current criteria
    CriteriaCheckerFixture() {
        cc = new CC();
    }
    ~CriteriaCheckerFixture() {
        delete cc;

        while (!ecs.empty()) {
            delete ecs.back();
            ecs.pop_back();
        }

        while (!ccs.empty()) {
            delete ccs.back();
            ccs.pop_back();
        }
    }
};

BOOST_FIXTURE_TEST_SUITE(CriteriaCheckerFixtureTestSuite, CriteriaCheckerFixture)  // NOLINT(whitespace/line_length)

BOOST_AUTO_TEST_CASE(pass_NoExpectedCriteria) {
    BOOST_REQUIRE(cc->pass(ecs, ccs) == true);
}

BOOST_AUTO_TEST_CASE(pass_NoCurrentCriteria) {
    AttrI* e0 = ::loggingapi::AttributeFactory<int>::createAttribute("attr0", 10);  // NOLINT(whitespace/line_length)
    ecs.push_back(e0);
    BOOST_REQUIRE(cc->pass(ecs, ccs) == false);
}

BOOST_AUTO_TEST_CASE(pass_ExpectedCriteriaNotMatchingCurrentCriteria) {
    AttrI* e0 = ::loggingapi::AttributeFactory<int>::createAttribute("attr0", 10);  // NOLINT(whitespace/line_length)
    AttrI* c0 = ::loggingapi::AttributeFactory<int>::createAttribute("attr0", 9);  // NOLINT(whitespace/line_length)
    ecs.push_back(e0);
    ccs.push_back(c0);
    BOOST_REQUIRE(cc->pass(ecs, ccs) == false);
}

BOOST_AUTO_TEST_CASE(pass_ExpectedCriteriaMatchingCurrentCriteria) {
    AttrI* e0 = ::loggingapi::AttributeFactory<int>::createAttribute("attr0", 10);  // NOLINT(whitespace/line_length)
    AttrI* c0 = ::loggingapi::AttributeFactory<int>::createAttribute("attr0", 11);  // NOLINT(whitespace/line_length)
    ecs.push_back(e0);
    ccs.push_back(c0);
    BOOST_REQUIRE(cc->pass(ecs, ccs) == true);
}

BOOST_AUTO_TEST_CASE(pass_2ExpectedCriteriaWhom1NotMatchingCurrentCriteria) {
    AttrI* e0 = ::loggingapi::AttributeFactory<int>::createAttribute("attr0", 10);  // NOLINT(whitespace/line_length)
    AttrI* c0 = ::loggingapi::AttributeFactory<int>::createAttribute("attr0", 11);  // NOLINT(whitespace/line_length)
    AttrI* e1 = ::loggingapi::AttributeFactory<int>::createAttribute("attr1", 10);  // NOLINT(whitespace/line_length)
    ecs.push_back(e0);
    ecs.push_back(e1);
    ccs.push_back(c0);
    BOOST_REQUIRE(cc->pass(ecs, ccs) == false);
}

BOOST_AUTO_TEST_SUITE_END()

}}}  // namespaces
