/*
 * Copyright (C) 2020 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "LazyTestService.h"
#include <binder/LazyServiceRegistrar.h>

namespace android {
namespace binder {

Status LazyTestService::forcePersist(bool persist) {
  auto lazyRegistrar = LazyServiceRegistrar::getInstance();
  lazyRegistrar.forcePersist(persist);

  return Status::ok();
}

Status LazyTestService::setCustomActiveServicesCountCallback() {
  auto lazyRegistrar = LazyServiceRegistrar::getInstance();
  lazyRegistrar.setActiveServicesCountCallback([lazyRegistrar](int count) mutable -> bool {
    if (count != 0) {
      return false;
    }

    // Unregister all services
    if (!lazyRegistrar.tryUnregister()) {
      // Prevent shutdown (test will fail)
      return true;
    }

    // Re-register all services
    lazyRegistrar.reRegister();

    // Unregister again before shutdown
    if (!lazyRegistrar.tryUnregister()) {
      // Prevent shutdown (test will fail)
      return true;
    }

    exit(EXIT_SUCCESS);
    // Unreachable
  });

  return Status::ok();
}

}  // namespace binder
}  // namespace android
