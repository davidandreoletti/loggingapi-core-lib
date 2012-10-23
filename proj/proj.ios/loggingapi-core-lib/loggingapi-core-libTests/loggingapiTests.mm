//
//  loggingapi_core_libTests.m
//  loggingapi-core-libTests
//
//  Created by David Andreoletti on 8/24/12.
//  Copyright (c) 2012 IO Stark. All rights reserved.
//

#import "loggingapiTests.h"

#import "./TestRunner.h"

@implementation loggingapiTests

- (void)setUp
{
    [super setUp];
    
    // Set-up code here.
}

- (void)tearDown
{
    // Tear-down code here.
    
    [super tearDown];
}

- (void)testLoggingMasterTestSuite
{
    ::test::loggingapi::TestRunner* testRunner = new ::test::loggingapi::TestRunner();
    int testSuiteResult = testRunner->run();
    STAssertEquals(0, testSuiteResult, @"Logging Master Test Suite Failed.");

}

@end
