# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\GD_NV_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\GD_NV_autogen.dir\\ParseCache.txt"
  "GD_NV_autogen"
  )
endif()
