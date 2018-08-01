/* The MIT License (MIT)
 *
 * Copyright (c) 2014-2018 David Medina and Tim Warburton
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 */
#include <occa.hpp>
#include <occa/tools/testing.hpp>

void testBase2Methods();
void testPtrMethods();

int main(const int argc, const char **argv) {
  testBase2Methods();
  testPtrMethods();

  return 0;
}

void testBase2Methods() {
  // Max bit index
  ASSERT_EQ(occa::maxBase2Bit(0),
            0);
  ASSERT_EQ(occa::maxBase2Bit(1),
            0);
  ASSERT_EQ(occa::maxBase2Bit(2),
            1);
  ASSERT_EQ(occa::maxBase2Bit(3),
            2);
  ASSERT_EQ(occa::maxBase2Bit(7),
            2);
  ASSERT_EQ(occa::maxBase2Bit(-1),
            (int) (8 * sizeof(int)));

  // Max bit value
  ASSERT_EQ(occa::maxBase2(0),
            1);
  ASSERT_EQ(occa::maxBase2(1),
            1);
  ASSERT_EQ(occa::maxBase2(2),
            2);
  ASSERT_EQ(occa::maxBase2(3),
            2);
  ASSERT_EQ(occa::maxBase2(7),
            4);
  ASSERT_EQ(occa::maxBase2(-1),
            -1);
}

void testPtrMethods() {
  int a;
  int *b = new int[10];

  ASSERT_EQ(occa::ptrDiff(&a, &a), (occa::udim_t) 0);
  ASSERT_EQ(occa::ptrDiff(b, b)  , (occa::udim_t) 0);

  ASSERT_GT(occa::ptrDiff(&a, b), (occa::udim_t) 0);
  ASSERT_GT(occa::ptrDiff(b, &a), (occa::udim_t) 0);
}
