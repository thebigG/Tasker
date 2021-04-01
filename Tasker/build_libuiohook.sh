cd  libuiohook/
mkdir -p build && cd build
cmake -S .. -D BUILD_SHARED_LIBS=ON -D BUILD_DEMO=ON -DCMAKE_INSTALL_PREFIX=../dist
cmake --build . --parallel 2 --target install
