#!/bin/bash

# 设置目标环境名称
ENV_NAME="python_env"
PYTHON_VERSION="3.12"

source .env/miniconda3/bin/activate
# 检查是否存在目标环境
if conda info --envs | grep -q "^$ENV_NAME "; then
    echo "Environment '$ENV_NAME' already exists. Activating it..."
    conda activate $ENV_NAME
else
    echo "Environment '$ENV_NAME' does not exist. Creating it..."
    conda create -n $ENV_NAME python=$PYTHON_VERSION
    conda activate $ENV_NAME
fi

# 输出当前环境的 Python 版本以确认
python --version
