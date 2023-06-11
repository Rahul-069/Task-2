#!/bin/bash

if [ $# -eq 0 ]; then
  echo "Please provide thye password length as an argument."
  exit 1
fi

password_length=$1

password=$(tr -dc  'a-zA-Z0-9' < /dev/urandom | head -c "$password_length")

echo "Random password : $password"
