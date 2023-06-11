#!/bin/bash

if [ $# -eq 0 ]; then
  echo "Please provide directory as an argument"
  exit 1
fi

directory="$1"

if [ ! -d "$directory" ]; then
  echo "The specified directory does not exist."
  exit 1
fi

modified_dir="$directory/Modified"

if [ ! -d "$modified_dir" ];
then
  mkdir "$modified_dir"
fi

find "$directory" -type f -name "*.txt" -print0 | while IFS= read -r -d '' file; do
  cp "$file" "${modified_dir}/$(basename "$file" .txt).bak"
done

echo "Files with .txt extension copied to '$modified_dir' with .bak extension."
