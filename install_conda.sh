#!/bin/bash

ARCH=$(uname -m)

mkdir .env
echo "download conda..."

if [ "$ARCH" = "x86_64" ]; then
  echo "x86_64 arch"
  wget https://repo.anaconda.com/miniconda/Miniconda3-latest-Linux-x86_64.sh -O .env/miniconda.sh
elif [ "$ARCH" = "aarch64" ]; then
  echo "aarch64"
  wget https://repo.anaconda.com/miniconda/Miniconda3-latest-Linux-aarch64.sh -O .env/miniconda.sh
else
  echo "This is neither x86_64 nor arm64. Architecture: $ARCH"
  exit
fi

bash .env/miniconda.sh -b -p .env/miniconda3
