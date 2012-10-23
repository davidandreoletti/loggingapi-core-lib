//
//  Logger.cpp
//  libloggingapi
//
//  Created by Andreoletti David on 7/24/12.
//  Copyright 2012 IO Stark. All rights reserved.
//

#include <iostream>  // NOLINT(readability/streams)
#include <string>
#include "loggingapi/sinks/ConsoleSink.h"
#include "loggingapi/records/RecordInterface.h"
#include "loggingapi/formatters/FormatterInterface.h"

namespace loggingapi {
namespace sinks {

ConsoleSink::~ConsoleSink() {
    delete formatter_;
}

ConsoleSink::ConsoleSink() {
    formatter_ = NULL;
}

void ConsoleSink::log(records::RecordInterface* r) {
    std::string msg;
    if (this->formatter_ != NULL) {
        msg.append(this->formatter_->format(r));
    } else {
        msg.append("<No formatter - Have you forgot to set a formatter ?>");
    }
    std::cout << msg << std::endl;
}

std::string ConsoleSink::getName() {
    return name_;
}

void ConsoleSink::setName(std::string name) {
    name_ = name;
}

void ConsoleSink::setFormatter(formatters::FormatterInterface* f) {
    formatter_ = f;
}

}}  // namespaces
