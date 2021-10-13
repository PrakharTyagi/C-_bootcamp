#!/bin/bash

repos=( 
  "/home/ptyagi1/projects/HelloWorld/Projects"
  
)

echo ""
echo "Getting latest for" ${#repos[@]} "repositories using pull --rebase"

for repo in "${repos[@]}"
do
  echo ""
  echo "****** Getting latest for" ${repo} "******"
  cd "${repo}"
  git pull --rebase
  echo "******************************************"
    cd Demo_Day1
    cd Assignment
    utput=$(g++ Assignment3.cpp)
  # utput=$(g++ $Assignment3.cpp -o Assignment3)
   echo "**********Compilation successfull**************"
if [[ $? != 0 ]]; then
    # There was an error, display the error in $output
    echo -e "Error:\n$output"
else
    # Compilation successfull
        ./a.out
fi
done
