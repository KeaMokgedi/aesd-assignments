#!/bin/sh
#Check if both arguments are provided
if [ $# -lt 2 ]; then
echo "Error:Two arguments required. Usage: ./writer.sh <filepath> <string>"
exit 1
fi
WRITEFILE=$1
WRITESTR=$2

#Create the directory path if it does not exist 
mkdir -p "$(dirname "$WRITEFILE")"

#Write the string to the file (overwriting if it exists)
echo "$WRITESTR" > "$WRITEFILE"

if [ $? -ne 0 ]; then 
echo "Error: File could not be created."
exit 1

fi 
