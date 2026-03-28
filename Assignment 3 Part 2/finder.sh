#!/bin/sh
# Check if both arguments are provided
if [ $# -lt 2 ]; then
    echo "Error: Two arguments required. Usage: ./finder.sh <filesdir> <searchstr>"
    exit 1
fi

FILESDIR=$1
SEARCHSTR=$2

# Check if FILESDIR is a valid directory
if [ ! -d "$FILESDIR" ]; then
    echo "Error: $FILESDIR is not a directory."
    exit 1
fi

# Count number of files and matching lines
X=$(find "$FILESDIR" -type f | wc -l)
Y=$(grep -r "$SEARCHSTR" "$FILESDIR" | wc -l)

echo "The number of files are $X and the number of matching lines are $Y"
