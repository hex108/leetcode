#!/bin/bash

if [ $# -ne 1 ]; then
    echo "usage: ./$0 code_name"
    exit 0
fi

CODE_NAME=$1

mkdir $CODE_NAME

cp template/test_file.h $CODE_NAME/$CODE_NAME.h

cp template/test.cpp $CODE_NAME/test.cpp
sed -i "s/TEST_FILE_H/$CODE_NAME\.h/" $CODE_NAME/test.cpp

cp template/Makefile $CODE_NAME/Makefile

REAL_NAME=$(echo $CODE_NAME | sed -e 's/_/ /g' -e 's/\b[a-z]/\U&/g' -e 's/\b2\b/II/g')

echo $(date +"%D %H:%M") $REAL_NAME >> PROGRESS.md
echo "" >> PROGRESS.md
