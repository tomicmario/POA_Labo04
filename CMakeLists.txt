cmake_minimum_required(VERSION 3.16.5)
project(Labo_04)

set(CMAKE_CXX_STANDARD 11)

add_executable(Labo_04 main.cpp humanoid/Humanoid.cpp humanoid/Humanoid.hpp humanoid/Buffy.cpp humanoid/Buffy.hpp humanoid/Human.cpp humanoid/Human.hpp humanoid/Vampire.cpp humanoid/Vampire.hpp controller/Field.cpp controller/Field.hpp controller/Controller.cpp controller/Controller.hpp actions/Action.cpp actions/Action.hpp actions/Move.cpp actions/Move.hpp actions/Kill.cpp actions/Kill.hpp controller/Util.cpp controller/Util.hpp actions/Transform.cpp actions/Transform.hpp)
