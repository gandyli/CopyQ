@echo on

cmake -H. -Bbuild -DCMAKE_BUILD_TYPE=RelWithDebInfo -G "%CMAKE_GENERATOR%" -DWITH_TESTS=ON
