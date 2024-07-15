# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

# If CMAKE_DISABLE_SOURCE_CHANGES is set to true and the source directory is an
# existing directory in our source tree, calling file(MAKE_DIRECTORY) on it
# would cause a fatal error, even though it would be a no-op.
if(NOT EXISTS "D:/Dsa/benchmark/googletest")
  file(MAKE_DIRECTORY "D:/Dsa/benchmark/googletest")
endif()
file(MAKE_DIRECTORY
  "D:/Dsa/benchmark/build/third_party/googletest/build"
  "D:/Dsa/benchmark/build/third_party/googletest"
  "D:/Dsa/benchmark/build/third_party/googletest/tmp"
  "D:/Dsa/benchmark/build/third_party/googletest/src/googletest-stamp"
  "D:/Dsa/benchmark/build/third_party/googletest/download"
  "D:/Dsa/benchmark/build/third_party/googletest/src/googletest-stamp"
)

set(configSubDirs Debug;Release;MinSizeRel;RelWithDebInfo)
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "D:/Dsa/benchmark/build/third_party/googletest/src/googletest-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "D:/Dsa/benchmark/build/third_party/googletest/src/googletest-stamp${cfgdir}") # cfgdir has leading slash
endif()
