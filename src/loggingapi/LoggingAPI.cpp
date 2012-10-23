//
//  SettingsAPI.cpp
//  libloggingapi
//
//  Created by Andreoletti David on 7/24/12.
//  Copyright 2012 IO Stark. All rights reserved.
//

#include <vector>
#include <string>

#include "loggingapi/LoggingAPI.h"
#include "loggingapi/loggers/LoggerInterface.h"
#include "loggingapi/core/Core.h"

namespace loggingapi {

loggers::LoggerInterface* LoggingAPI::getLogger(const std::string& name) {
    return loggingCore_.getLogger(name);
}

bool LoggingAPI::addLogger(loggers::LoggerInterface* logger) {
    return loggingCore_.addLogger(logger);
}

loggers::LoggerInterface* LoggingAPI::removeLogger(const std::string& name) {
    return loggingCore_.removeLogger(name);
}

}  // namespaces
