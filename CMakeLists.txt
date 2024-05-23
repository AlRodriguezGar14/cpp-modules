cmake_minimum_required(VERSION 3.27)
project(cpp_modules)

set(CMAKE_CXX_STANDARD 14)

include_directories(mod00/ex01)
include_directories(mod00/ex02)
include_directories(mod01/ex00)
include_directories(mod01/ex01)
include_directories(mod01/ex03)
include_directories(mod01/ex05)
include_directories(mod01/ex06)

add_executable(cpp_modules
        mod00/ex00/megaphone.cpp
        mod00/ex01/Contact.cpp
        mod00/ex01/Contact.hpp
        mod00/ex01/main.cpp
        mod00/ex01/PhoneBook.cpp
        mod00/ex01/PhoneBook.hpp
        mod00/ex01/Utils.cpp
        mod00/ex01/Utils.hpp
        mod00/ex02/Account.cpp
        mod00/ex02/Account.hpp
        mod00/ex02/tests.cpp
        mod01/ex00/main.cpp
        mod01/ex00/newZombie.cpp
        mod01/ex00/randomChump.cpp
        mod01/ex00/Zombie.cpp
        mod01/ex00/Zombie.hpp
        mod01/ex01/main.cpp
        mod01/ex01/Zombie.cpp
        mod01/ex01/Zombie.hpp
        mod01/ex01/zombieHorde.cpp
        mod01/ex02/main.cpp
        mod01/ex03/HumanA.cpp
        mod01/ex03/HumanA.hpp
        mod01/ex03/HumanB.cpp
        mod01/ex03/HumanB.hpp
        mod01/ex03/main.cpp
        mod01/ex03/Weapon.cpp
        mod01/ex03/Weapon.hpp
        mod01/ex04/main.cpp
        mod01/ex05/Harl.cpp
        mod01/ex05/Harl.hpp
        mod01/ex05/main.cpp
        mod01/ex06/Harl.cpp
        mod01/ex06/Harl.hpp
        mod01/ex06/main.cpp)
