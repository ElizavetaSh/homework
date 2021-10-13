
cmake_minimum_required(VERSION 3.5)

project(Techno)

set(LIB_SOURCE_FILES hist.c)
set(LIB_HEADERS_FILES hist.h)

add_library(hist STATIC ${LIB_SOURCE_FILES} ${LIB_HEADERS_FILES})

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(main main.cpp "hist.h" "hist.c" )
target_link_libraries(main hist)


include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
  hello_test
  test_hist.cpp
)
target_link_libraries(
  hello_test
  gtest_main
)

include(GoogleTest)
gtest_discover_tests(hello_test)

#add_executable(test_hist test_hist.cpp)
#target_link_libraries(test_hist hist)


