if(EXISTS "/mnt/c/Users/avipd/OneDrive/Documents/kvstore-cpp/build/kvstore_test[1]_tests.cmake")
  include("/mnt/c/Users/avipd/OneDrive/Documents/kvstore-cpp/build/kvstore_test[1]_tests.cmake")
else()
  add_test(kvstore_test_NOT_BUILT kvstore_test_NOT_BUILT)
endif()
