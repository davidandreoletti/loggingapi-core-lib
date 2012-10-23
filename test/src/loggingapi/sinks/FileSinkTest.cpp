//
//  FileSinkTest.cpp
//  libloggingapi
//
//  Created by Andreoletti David on 3/31/12.
//  Copyright 2012 IO Stark. All rights reserved.
//

#include <string>
#include <vector>
#include <fstream>  // NOLINT(readability/streams)
#include "boost/test/unit_test.hpp"
#include "loggingapi/loggers/LoggerInterface.h"
#include "loggingapi/loggers/Logger.h"
#include "loggingapi/sinks/SinkInterface.h"
#include "loggingapi/sinks/FileSink.h"
#include "loggingapi/records/RecordInterface.h"
#include "loggingapi/records/Record.h"
#include "loggingapi/attributes/AttributeConstants.h"
#include "loggingapi/LoggingAPITrivial.h"

namespace test {
namespace loggingapi {
namespace sinks {

typedef ::loggingapi::records::Record Rec;
typedef ::loggingapi::records::RecordInterface RecordI;
typedef ::loggingapi::loggers::LoggerInterface LoggerI;
typedef ::loggingapi::sinks::SinkInterface SinkI;
typedef ::loggingapi::sinks::FileSink FSink;
typedef ::loggingapi::attributes::AttributeInterface AttrI;

const std::string kLoggerName0 = "logger0";
const std::string kSinkFilePath0 = "FileSink.log";

struct FileSinkFixture {
    SinkI* sink0;
    LoggerI* logger0;
    FileSinkFixture() {
        sink0 = static_cast<SinkI*>(new FSink(kSinkFilePath0));
        logger0 = static_cast<LoggerI*>(new ::loggingapi::loggers::Logger());
    }
    ~FileSinkFixture() {
        delete sink0;
        delete logger0;
    }
};

BOOST_FIXTURE_TEST_SUITE(FileSinkTestSuite, FileSinkFixture)

BOOST_AUTO_TEST_CASE(log) {
    RecordI* r = static_cast<RecordI*>(new Rec());
    AttrI* attr0 = ::loggingapi::AttributeFactory<std::string>::createAttribute(::loggingapi::attributes::kMESSAGE_ATTRIBUTE_NAME, "My Message");  // NOLINT(whitespace/line_length)
    r->addAttribute(attr0);
    sink0->log(r);

    std::ifstream logFile(kSinkFilePath0.c_str());
    BOOST_REQUIRE(logFile.is_open() == true);  // File is open
    BOOST_REQUIRE(logFile.good() == true);  // EOF not reached. Sothere is a record in file  NOLINT(whitespace/line_length)
    std::string logRecord;
    while (logFile.good()) {
        getline(logFile, logRecord);
        BOOST_REQUIRE(logRecord.size() > 0);  // A record contains at least one character NOLINT(whitespace/line_length)
    }
}

BOOST_AUTO_TEST_SUITE_END()

}}}  // namespaces
