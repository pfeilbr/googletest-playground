# googletest-playground

learn [Googletest](https://github.com/google/googletest), Google Testing and Mocking Framework with CMake

based on <https://raymii.org/s/tutorials/Cpp_project_setup_with_cmake_and_unit_tests.html>

```sh
# begin: one-time setup to add googletest dependency
mkdir lib
pushd lib
git clone https://github.com/google/googletest/
popd
# end: one-time setup

#clean
./run.sh clean

# build
./run.sh buildandtest

# run tests
./run.sh test

# build and run tests when file changes under src/ and tst/
./run.sh watch

# build main binary
./run.sh buildmain

# run main binary
./run.sh main
```