#!/bin/bash

        BOOK="address-book.txt" 

        # Display the format before the entries
        echo "Line Number:   Name  ;  Phone Number"

        # Print the book with line numbers and paused with less
        nl --number-separator=":    " $BOOK
