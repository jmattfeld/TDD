/***
 * Excerpted from "Test-Driven Development for Embedded C",
 * published by The Pragmatic Bookshelf.
 * Copyrights apply to this code. It may not be used to create training material, 
 * courses, books, articles, and the like. Contact us if you are in doubt.
 * We make no guarantees that this code is fit for any purpose. 
 * Visit http://www.pragmaticprogrammer.com/titles/jgade for more book information.
***/
/*- ------------------------------------------------------------------ -*/
/*-    Copyright (c) James W. Grenning -- All Rights Reserved          -*/
/*-    For use by owners of Test-Driven Development for Embedded C,    -*/
/*-    and attendees of Renaissance Software Consulting, Co. training  -*/
/*-    classes.                                                        -*/
/*-                                                                    -*/
/*-    Available at http://pragprog.com/titles/jgade/                  -*/
/*-        ISBN 1-934356-62-X, ISBN13 978-1-934356-62-3                -*/
/*-                                                                    -*/
/*-    Authorized users may use this source code in your own           -*/
/*-    projects, however the source code may not be used to            -*/
/*-    create training material, courses, books, articles, and         -*/
/*-    the like. We make no guarantees that this source code is        -*/
/*-    fit for any purpose.                                            -*/
/*-                                                                    -*/
/*-    www.renaissancesoftware.net james@renaissancesoftware.net       -*/
/*- ------------------------------------------------------------------ -*/


#include "unity_fixture.h"
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#include "CircularBuffer.h"

TEST_GROUP(CircularBuffer);

TEST_SETUP(CircularBuffer)
{
}

TEST_TEAR_DOWN(CircularBuffer)
{
}

// helper fxns
/* static void expect(const char * s) */
/* { */
/* 	l1 = strlen(s); */
/* 	expected = s; */
/* 	/1* printf("s=%ld\n",l1); *1/ */
/* 	output = (char *)malloc(l1 + 2); */
/* 	if (output) { */
/* 		memset(output, 0xaa, l1 + 2); */
/* 	} */
/* 	/1* printf("output=%s\n",output); *1/ */
/* } */

/* static void given(int charsWritten) */
/* { */
/* 	l2 = strlen(expected); */
/* 	/1* printf("expected=%ld\n",l2); *1/ */
/*     TEST_ASSERT_EQUAL(strlen(expected), charsWritten); */
/*     TEST_ASSERT_EQUAL_STRING(expected, output); */
/*     TEST_ASSERT_BYTES_EQUAL(0xaa, output[l2 + 1]); */
/* } */

#if 1 
TEST(CircularBuffer, TestCapacity)
{
	int capacity = 10;
	CircularBuffer buffer = CircularBuffer_Create(capacity);
	TEST_ASSERT_EQUAL(capacity, buffer->capacity);
	CircularBuffer_Destroy(buffer);
}
#endif
