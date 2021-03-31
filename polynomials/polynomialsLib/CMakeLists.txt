file(GLOB hdrs "*.h*")
file(GLOB srcs "*.cpp")

add_library(${polynomialslib} STATIC ${srcs} ${hdrs})