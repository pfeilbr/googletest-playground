#!/bin/bash

CMD="$1"
ABSOLUTE_SCRIPT_PATH="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)/$(basename "${BASH_SOURCE[0]}")"
DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"
BUILD_DIR="$DIR/build"
MAIN_BINARY="$BUILD_DIR/src/App01_run"
TEST_BINARY="$BUILD_DIR/tst/App01_tst"
FSWATCH_ARGS="-o src -o tst" # directories to watch for file changes

debug()
{
    echo CMD=$CMD
    echo DIR=$DIR
    echo BUILD_DIR=$BUILD_DIR
}

clean()
{
    [ -d "$BUILD_DIR" ] && rm -fr "$BUILD_DIR"
}

build()
{
    mkdir "$BUILD_DIR"
    pushd "$BUILD_DIR"
    cmake .. -DCMAKE_BUILD_TYPE=Debug -G "Unix Makefiles"
    make all
    popd
}

test()
{
    exec "$TEST_BINARY"
}

buildandtest()
{
    build
    test
}

watch()
{
    echo watch

    fswatch $FSWATCH_ARGS | xargs -n1 -I{} sh $ABSOLUTE_SCRIPT_PATH buildandtest
}

main()
{
    exec "$MAIN_BINARY"
}

case $CMD in
    clean)
        clean
    ;;
    build)
        build
    ;;    
    test)
        test
    ;;
    buildandtest)
        buildandtest
    ;;
    watch)
        watch
    ;;            
    main)
        main
    ;;
esac

# rm -fr build

#./build/tst/App01_tst