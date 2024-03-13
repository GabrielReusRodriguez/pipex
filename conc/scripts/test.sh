#!/bin/bash

echo "Hola mundo"

ls -l | echo $?
#ls -l | echo $? | exit 10 | echo $?
#ls -l |  kill -9  | echo $?

echo "Adios mundo!"