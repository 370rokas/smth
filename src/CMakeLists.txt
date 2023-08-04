add_executable(smth
        Main.cpp
        TQueue.cpp
)

target_link_libraries(smth PRIVATE
        yaml-cpp
        msquic
)