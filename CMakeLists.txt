cmake_minimum_required(VERSION 3.17)
project(lab11 C)

set(CMAKE_C_STANDARD 99)

add_executable(lab11 main.c btree.c btree.h graph_reader.h graph_reader.c graph_adapter.h graph_adapter.c graph.h queue.c queue.h btree.h btree.c stack.c stack.h)