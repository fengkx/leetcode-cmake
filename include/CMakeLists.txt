aux_source_directory(. LEETCODE)
#set (LEETCODE headers.h)
message(STATUS "Source files : " ${LEETCODE})
add_library(leetcode ${LEETCODE})