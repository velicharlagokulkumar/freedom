//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// UNSUPPORTED: c++03, c++11, c++14
// TODO: Change to XFAIL once https://github.com/llvm/llvm-project/issues/40340 is fixed
// UNSUPPORTED: availability-pmr-missing

// <memory_resource>

// class monotonic_buffer_resource

#include <memory_resource>
#include <cassert>

#include "count_new.h"

int main(int, char**) {
  // Constructing a monotonic_buffer_resource should not cause allocations
  // by itself; the resource should wait to allocate until an allocation is
  // requested.

  globalMemCounter.reset();
  std::pmr::set_default_resource(std::pmr::new_delete_resource());

  std::pmr::monotonic_buffer_resource r1;
  assert(globalMemCounter.checkNewCalledEq(0));

  std::pmr::monotonic_buffer_resource r2(1024);
  assert(globalMemCounter.checkNewCalledEq(0));

  std::pmr::monotonic_buffer_resource r3(1024, std::pmr::new_delete_resource());
  assert(globalMemCounter.checkNewCalledEq(0));

  return 0;
}
