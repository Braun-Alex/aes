cmake_minimum_required(VERSION 3.26)
project(AES VERSION 1.0 DESCRIPTION "Secure AES without problems" LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 23)

include_directories(include)

add_library(AES SHARED
        src/AES.cpp
)

install(TARGETS AES
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        RUNTIME DESTINATION bin
        PUBLIC_HEADER DESTINATION include
)

install(DIRECTORY include/ DESTINATION include)

include(FetchContent)

FetchContent_Declare(
        Poco
        URL https://github.com/pocoproject/poco/archive/refs/tags/poco-1.12.4-release.zip
)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip
)

FetchContent_MakeAvailable(Poco googletest)

enable_testing()
add_subdirectory(tests)

target_link_libraries(${PROJECT_NAME} PUBLIC Crypto Util)