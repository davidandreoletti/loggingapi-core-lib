//
//  newsimpletest.cpp
//  libloggingapi
//
//  Created by Andreoletti David on 3/31/12.
//  Copyright 2012 IO Stark. All rights reserved.
//


#include <stdlib.h>
#include <iostream>  // NOLINT(readability/streams)
#include "loggingapi/LoggingAPITrivial.h"

/*
 * Simple C++ Test Suite
 */

int main(int argc, char** argv) {
    std::cout << "TEST SUITE START" << std::endl;

    LOGGINGAPI_LOG(0, "My test suite message");
//    LOGGINGAPI_LOG(0, "My test suite message 2");
//    LOGGINGAPI_LOG(0, "My test suite message 3");

    std::cout << "TEST SUITE END" << std::endl;

    return (EXIT_SUCCESS);
}

