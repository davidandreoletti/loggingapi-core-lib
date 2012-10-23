//
//  Logger.cpp
//  libloggingapi
//
//  Created by Andreoletti David on 7/24/12.
//  Copyright 2012 IO Stark. All rights reserved.
//

#include <string>
#include "loggingapi/sinks/FileSink.h"
#include "loggingapi/records/RecordInterface.h"
#include "loggingapi/formatters/FormatterInterface.h"

namespace loggingapi {
namespace sinks {

void FileSink::log(records::RecordInterface* r) {
    if (!file_.is_open()) {
        const char* fName = filePath_.c_str();
        file_.exceptions(std::ofstream::goodbit);
        file_.open(fName, std::ios::out | std::ios::ate);
    }

    std::string msg;
    if (this->formatter_ != NULL) {
        msg.append(this->formatter_->format(r));
    } else {
        msg.append("<No formatter - Have you forgot to set a formatter ?>");
    }

    const char* s = msg.c_str();
    file_.write(s, msg.size());
    if (!file_.bad()) {
        file_.flush();
    }
}

FileSink::FileSink(const std::string fPath) {
    filePath_ = fPath;
    formatter_ = NULL;
}

FileSink::~FileSink() {
    file_.close();
    delete formatter_;
}

std::string FileSink::getName() {
    return name_;
}

void FileSink::setName(std::string name) {
    name_ = name;
}

void FileSink::setFormatter(formatters::FormatterInterface* f) {
    formatter_ = f;
}

}}  // namespaces
