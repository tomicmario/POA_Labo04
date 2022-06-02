cmake_minimum_required(VERSION 3.16.5)
project(Labo_04)

set(CMAKE_CXX_STANDARD 11)

add_executable(Labo_04 main.cpp humanoid/Humanoid.cpp humanoid/Humanoid.h humanoid/Buffy.cpp humanoid/Buffy.h humanoid/Human.cpp humanoid/Human.h humanoid/Vampire.cpp humanoid/Vampire.h graphics/Field.cpp graphics/Field.h controller/Controller.cpp controller/Controller.h graphics/Graphics.cpp graphics/Graphics.h)
