file(GLOB hdrs "${CMAKE_SOURCE_DIR}/include/*.h*")
file(GLOB_RECURSE source_files "*.cpp")


add_executable(loader ${source_files} ${hdrs})

target_link_libraries(loader
                        glfw 
                        libglew_static						
                        ${OPENGL_LIBRARIES}
)
