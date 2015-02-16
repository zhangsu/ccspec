#!/bin/bash

set -ev

if [ "`uname -s`" = "Darwin" ] ; then
  brew update
  brew install cmake
  echo
else
  sudo add-apt-repository ppa:kalakris/cmake -y
  sudo apt-get update -qq
  sudo apt-get install cmake
fi
