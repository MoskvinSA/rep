file(GLOB hdrs "*.h*") 
file(GLOB srcs "*.cpp")

add_executable(${sample} ${srcs} ${hdrs})
target_link_libraries(${sample} ${polynomialslib})


