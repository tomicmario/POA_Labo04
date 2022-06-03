cmake_minimum_required(VERSION 3.16.5)
project(Labo_04)

set(CMAKE_CXX_STANDARD 11)

add_executable(Labo_04 main.cpp humanoid/Humanoid.cpp humanoid/Humanoid.hpp humanoid/Buffy.cpp humanoid/Buffy.hpp humanoid/Human.cpp humanoid/Human.hpp humanoid/Vampire.cpp humanoid/Vampire.hpp graphics/Field.cpp graphics/Field.hpp controller/Controller.cpp controller/Controller.hpp graphics/Graphics.cpp graphics/Graphics.hpp controller/Action.cpp controller/Action.hpp controller/Move.cpp controller/Move.hpp controller/Kill.cpp controller/Kill.hpp)
