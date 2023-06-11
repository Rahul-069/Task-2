#!/bin/bash

if [ $# -eq 0 ]; then
echo "Please provide password length as an argument."
exit 1
fi

password_length=$1

password=$(openssl rand -base64 "$((password_length * 3/4))" | tr -d '\n' | head -c "$password_length")

echo "Random password : $password"
