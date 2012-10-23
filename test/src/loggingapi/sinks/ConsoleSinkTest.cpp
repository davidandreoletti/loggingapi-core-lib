//
//  ConsoleSinkTest.cpp
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
#include "loggingapi/sinks/SinkInterface.h"
#include "loggingapi/sinks/ConsoleSink.h"
#include "loggingapi/records/RecordInterface.h"
#include "loggingapi/records/Record.h"

namespace test {
namespace loggingapi {
namespace sinks {

typedef ::loggingapi::records::Record Rec;
typedef ::loggingapi::records::RecordInterface RecordI;
typedef ::loggingapi::loggers::LoggerInterface LoggerI;
typedef ::loggingapi::sinks::SinkInterface SinkI;
typedef ::loggingapi::sinks::ConsoleSink CSink;

const std::string kLoggerName0 = "logger0";

struct ConsoleSinkFixture {
    SinkI* sink0;
    LoggerI* logger0;
    ConsoleSinkFixture() {
        sink0 = static_cast<SinkI*>(new CSink());
        logger0 = static_cast<LoggerI*>(new ::loggingapi::loggers::Logger());
    }
    ~ConsoleSinkFixture() {
        delete sink0;
        delete logger0;
    }
};

BOOST_FIXTURE_TEST_SUITE(ConsoleSinkTestSuite, ConsoleSinkFixture)

BOOST_AUTO_TEST_CASE(log) {
    RecordI* r = static_cast<RecordI*>(new Rec());
    sink0->log(r);
    BOOST_REQUIRE(true);  // How can I test this ?
}

BOOST_AUTO_TEST_SUITE_END()

}}}  // namespaces
