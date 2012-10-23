//
//  LoggingAPI.h
//  libloggingapi
//
//  Created by Andreoletti David on 26/09/2012.
//  Copyright 2012 IO Stark. All rights reserved.
//

#ifndef INCLUDE_LOGGINGAPI_LOGGINGAPI_H_
#define INCLUDE_LOGGINGAPI_LOGGINGAPI_H_

#include <string>
#include <vector>
#include "loggingapi/LoggingAPIInterface.h"
#include "loggingapi/core/Core.h"

namespace loggingapi {
namespace core { class Core; }
namespace loggers { class LoggerInterface; }

/**
 *  Public Logging API
 */
class LoggingAPI : LoggingAPIInterface {
 public:
    // Inherited from LoggingAPIInterface
    static loggers::LoggerInterface* getLogger(const std::string& name);
    static bool addLogger(loggers::LoggerInterface* logger);
    static loggers::LoggerInterface* removeLogger(const std::string& name);

 private:
    /**
     * Logging Core
     */
    static core::Core loggingCore_;
};

}  // namespaces

#endif  // INCLUDE_LOGGINGAPI_LOGGINGAPI_H_
