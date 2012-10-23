//
//  LoggerInterface.h
//  libloggingsapi
//
//  Created by Andreoletti David on 7/24/12.
//  Copyright 2012 IO Stark. All rights reserved.
//

#ifndef INCLUDE_LOGGINGAPI_LOGGERS_LOGGERINTERFACE_H_
#define INCLUDE_LOGGINGAPI_LOGGERS_LOGGERINTERFACE_H_

#include <string>

namespace loggingapi {
namespace attributes { class AttributeInterface; }
namespace records { class RecordInterface; }
namespace loggers {

/**
 *  A logger
 */
class LoggerInterface {
 public:
    /**
     *  Destructor
     */
    virtual ~LoggerInterface() = 0;

 /**
     *  Gets logger name
  *   \return Logger name
     */
    virtual std::string getName() const = 0;

    /**
     *  Sets logger name
     * \param name Logger name
     */
    virtual void setName(std::string name) = 0;

    /**
     * Gets a filter
     * \param name Filter name.
     * \return If filter is found then Filter instance. Otherwise NULL. 
     * \warning Caller does NOT own the pointer.
     */
    virtual attributes::AttributeInterface* getFilter(const std::string& name) const = 0;  // NOLINT(whitespace/line_length)

    /**
     * Adds a filter
     * \param filter A filter instance. Filter added only if filter is NOT NULL and logger does NOT contain the filter. Caller does NOT own the pointer anymore.
     * \return True if filter is added.
     */
    virtual bool addFilter(attributes::AttributeInterface* filter) = 0;

    /**
     * Removes a filter
     * \param name Name of filter to remove. 
     * \return Removed filter. NULL if not found. Caller ows the non NULL pointer.
     */
    virtual attributes::AttributeInterface* removeFilter(const std::string& name) = 0;  // NOLINT(whitespace/line_length)

    /**
     * Logs a message
     * \param record A record. Callee does NOT own the pointer
     */
    virtual void log(const records::RecordInterface* record) = 0;
};

inline LoggerInterface::~LoggerInterface() {}

}}  // namespaces

#endif  // INCLUDE_LOGGINGAPI_LOGGERS_LOGGERINTERFACE_H_
