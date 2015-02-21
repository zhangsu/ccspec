#!/bin/bash

set -ev

sudo add-apt-repository ppa:ubuntu-toolchain-r/test --yes
if [ "$CXX" = "clang++" ]; then sudo add-apt-repository 'deb http://llvm.org/apt/precise/ llvm-toolchain-precise-3.6 main' --yes; fi
sudo apt-get update -qq
if [ "$CXX" = "clang++" ]; then sudo apt-get --allow-unauthenticated install clang-3.6; fi
if [ "$CXX" = "g++" ]; then sudo apt-get install g++-5; fi
