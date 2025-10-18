# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\QLNS_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\QLNS_autogen.dir\\ParseCache.txt"
  "QLNS_autogen"
  )
endif()
