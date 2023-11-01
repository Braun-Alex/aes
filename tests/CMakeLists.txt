add_executable(aes_tests aes_tests.cpp)
target_link_libraries(aes_tests gtest_main AES)
add_test(NAME aes_test COMMAND aes_tests)