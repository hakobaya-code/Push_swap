#!/bin/bash

# random_values プログラムを実行し、出力を変数に格納
RANDOM_VALUES=$(./random_values)

# 出力された値を other_program の引数として渡す
./push_swap $RANDOM_VALUES
