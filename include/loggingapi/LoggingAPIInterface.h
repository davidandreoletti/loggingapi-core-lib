//
//  LoggingAPIInterface.h
//  libloggingapi
//
//  Created by Andreoletti David on 26/09/2012.
//  Copyright 2012 IO Stark. All rights reserved.
//

#ifndef INCLUDE_LOGGINGAPI_LOGGINGAPIINTERFACE_H_
#define INCLUDE_LOGGINGAPI_LOGGINGAPIINTERFACE_H_

#include <string>

namespace loggingapi {
namespace loggers { class LoggerInterface; }

/**
 *  Public Logging API
 */
class LoggingAPIInterface {
 public:
    /**
     *  Destructor
     */
    virtual ~LoggingAPIInterface() = 0;

    /**
     * Gets a logger
     * \param name Logger name. If NULL then default logger is returned
     * \return Logger. NULL if no logger found
     * \warning Not thread-safe.
     */
    static loggers::LoggerInterface* getLogger(const std::string& name);

    /**
     * Adds a logger
     * \param logger Logger instance. Logger added only if logger != NULL and logger is not yet added. Once added, callee does NOT own the pointer.
     * \return True if logger is added.
     * \warning Not thread-safe.
     */
    static bool addLogger(loggers::LoggerInterface* logger);

    /**
     * Removes a logger
     * \param name Logger name.
     * \return Logger instance. NULL if no logger found. If logger instance is NOT null,
     * callee owns the pointer.
     * \warning Not thread-safe.
     */
    static loggers::LoggerInterface* removeLogger(const std::string& name);
};

inline LoggingAPIInterface::~LoggingAPIInterface() {}

}  // namespaces

#endif  // INCLUDE_LOGGINGAPI_LOGGINGAPIINTERFACE_H_
