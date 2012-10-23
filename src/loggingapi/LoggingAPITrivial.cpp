//
//  LoggingAPITrivial.h
//  libloggingapi
//
//  Created by Andreoletti David on 26/09/2012.
//  Copyright 2012 IO Stark. All rights reserved.
//

#include <string>
#include "loggingapi/LoggingAPITrivial.h"
#include "loggingapi/LoggingAPI.h"
#include "loggingapi/attributes/AttributeInterface.h"
#include "loggingapi/attributes/AttributeConstants.h"
#include "loggingapi/records/Record.h"
#include "loggingapi/records/RecordInterface.h"
#include "loggingapi/loggers/LoggerInterface.h"
#include "loggingapi/loggers/Logger.h"
#include "loggingapi/sinks/SinkInterface.h"
#include "loggingapi/sinks/ConsoleSink.h"
#include "loggingapi/formatters/FormatterInterface.h"
#include "loggingapi/formatters/Formatter.h"

namespace loggingapi {

void createRecordAndLog(std::string ln,
                        int sv,
                        std::string f,
                        int l,
                        std::string m) {
    typedef ::loggingapi::attributes::AttributeInterface AttrI;
    typedef ::loggingapi::records::Record Rec;
    typedef ::loggingapi::records::RecordInterface RecI;
    typedef ::loggingapi::loggers::LoggerInterface LoggerI;
    typedef ::loggingapi::loggers::Logger Log;
    typedef ::loggingapi::sinks::SinkInterface SinkI;
    typedef ::loggingapi::sinks::ConsoleSink SinkC;
    typedef ::loggingapi::formatters::FormatterInterface FtterI;
    typedef ::loggingapi::formatters::Formatter Ftter;

    if (ln.compare(::loggingapi::kDefaultLoggerName) == 0
        && ::loggingapi::LoggingAPI::getLogger(ln) == NULL) {
        Ftter* ftt = new Ftter();
        FtterI* ftti = static_cast<FtterI*>(ftt);
        SinkC* cs = new SinkC();
        SinkI* si = static_cast<SinkI*>(cs);
        si->setFormatter(ftti);
        Log* lggr = new Log();
        lggr->setName(ln);
        lggr->addSink(si);
        LoggerI* lggrI = static_cast<LoggerI*>(lggr);
        LoggingAPI::addLogger(lggrI);
    }

    // Create Record
    RecI* r = static_cast<RecI*>(new Rec());

    // Message attribute
    AttrI* attr0 = loggingapi::AttributeFactory<std::string>::createAttribute(attributes::kMESSAGE_ATTRIBUTE_NAME, m);  // NOLINT(whitespace/line_length)
    r->addAttribute(attr0);
    // Severity attribute
    AttrI* attr1 = ::loggingapi::AttributeFactory<int>::createAttribute(attributes::kSEVERITY_ATTRIBUTE_NAME, sv);  // NOLINT(whitespace/line_length)
    r->addAttribute(attr1);
    // File attribute
    AttrI* attr2 = ::loggingapi::AttributeFactory<std::string>::createAttribute(attributes::kFILE_ATTRIBUTE_NAME, f);  // NOLINT(whitespace/line_length)
    r->addAttribute(attr2);
    // Line attribute
    AttrI* attr3 = ::loggingapi::AttributeFactory<int>::createAttribute(attributes::kLINENUMBER_ATTRIBUTE_NAME, l);  // NOLINT(whitespace/line_length)
    r->addAttribute(attr3);

    // Log record
    LoggerI* logger = LoggingAPI::getLogger(ln);
    if (logger != NULL) {logger->log(r);}
}

}  // namespaces
