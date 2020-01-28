#!/bin/bash

        BOOK="address-book.txt"

        # Ask the user which line to delete
        echo -n "Which line should I delete: "
        read number

        # Rename the file before deleting
        mv $BOOK boo.txt

        # Add line numbers and delete against that number
        nl --number-separator=":" boo.txt | grep -v $number: | awk -F: '{print $2}' |  tee $BOOK
