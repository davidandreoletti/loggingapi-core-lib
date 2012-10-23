//
//  LoggingAPITrivial.h
//  libloggingapi
//
//  Created by Andreoletti David on 26/09/2012.
//  Copyright 2012 IO Stark. All rights reserved.
//

#ifndef INCLUDE_LOGGINGAPI_LOGGINGAPITRIVIAL_H_
#define INCLUDE_LOGGINGAPI_LOGGINGAPITRIVIAL_H_

#include <string>
#include "loggingapi/attributes/Attribute.h"
#include "loggingapi/attributes/AttributeInterface.h"
#include "loggingapi/attributes/AttributeValue.h"
#include "loggingapi/attributes/AttributeValueInterface.h"

namespace loggingapi {

/**
 * Default logger name
 */
static const std::string kDefaultLoggerName = "defaultLogger";

/**
 * Factory to create a basic attribute
 * \param name Type of the attribute Value
 */
template<typename valueT>
class AttributeFactory {
    typedef ::loggingapi::attributes::AttributeInterface AttrI;
    typedef ::loggingapi::attributes::AttributeValueInterface AttrVI;
    typedef ::loggingapi::attributes::Attribute Attr;
    typedef ::loggingapi::attributes::AttributeValue<valueT> AttrV;

 public:
    /**
     * Creates an attribute
     * \param name Attribute name
     * \param value Attribute value
     */
    static attributes::AttributeInterface* createAttribute(std::string name,
                                                           valueT value) {
        Attr* a = new Attr();
        AttrI* attr = static_cast<AttrI*>(a);
        attr->setKey(name);
        AttrV* attrValue = new AttrV(value);
        AttrVI* attrValueI = static_cast<AttrVI*>(attrValue);
        attr->setValue(attrValueI);
        return attr;
    }
};

/**
 * Create a log record and log the record to a logger
 * \param ln Logger Name to log record to
 * \param sv Logging severity
 * \param f File where record is generated from
 * \param l Line where record is generated from
 * \param m Record message
 */
void createRecordAndLog(std::string ln,
                            int sv,
                            std::string f,
                            int l,
                            std::string m);

/**
 * Log a record to logger
 * \param loggerName Logger Name to log record to
 * \param lvl Logging level
 * \param file File whom record is generated from
 * \param line Line whom record is generated from
 * \param message Logging message
 * 
 * Usage:
 * LOGGINGAPI_LOG(lvl) ;
 */
#define LOGGINGAPI_LOG_WITH_PARAMS(loggerName, lvl, file, line, message) \
    ::loggingapi::createRecordAndLog(loggerName, lvl, file, line, message);

/**
 * Log a record to the default logger.
 * The default logger logs message to the standard output.
 * \param lvl Logging level
 * \param message Logging record
 *
 * Usage:
 * LOGGINGAPI_LOG(0 ,"My message!")
 */
#define LOGGINGAPI_LOG(lvl, message) \
    LOGGINGAPI_LOG_WITH_PARAMS(::loggingapi::kDefaultLoggerName, lvl, __FILE__, __LINE__, #message)  // NOLINT(whitespace/line_length)

/**
 * Log a record to logger
 * \param loggerName Logger Name to log record to
 * \param lvl Logging level
 * \param message Logging record
 * 
 * Usage:
 * LOGGINGAPI_LOG("myLogger", 0 ,"My message!")
 */
#define LOGGINGAPI_LOG2(loggerName, lvl, message) \
    LOGGINGAPI_LOG_WITH_PARAMS(#loggerName, lvl, __FILE__, __LINE__, #message)

}  // namespaces

#endif  // INCLUDE_LOGGINGAPI_LOGGINGAPITRIVIAL_H_
