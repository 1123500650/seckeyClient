cmake_minimum_required(VERSION 3.0)

project(SECKEYCLIENT)

add_executable(main *.cpp -lssl -lcrypto -lmysqlclient)