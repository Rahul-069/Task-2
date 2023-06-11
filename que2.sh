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

find "$modified_dir" -type f -print0 | while IFS= read -r -d '' file; do
  current_date=$(date +%Y-%m-%d_%H-%M-%S)
  echo -e "\nAppended at $current_date" >> "$file"
done

echo "Date and time appended to each file in '$modified_dir'."
