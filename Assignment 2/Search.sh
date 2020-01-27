#!/bin/sh
     
        BOOK="address-book.txt"

        # Ask the user what to look for.
        echo -n "What person or number are you seeking: "
        read find

        # Print the header before the answer
        echo "Name ; Phone number"
        grep -i $find $BOOK
