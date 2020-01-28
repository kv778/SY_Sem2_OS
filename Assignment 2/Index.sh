#!/bin/bash

        # Name of address book
        BOOK="address-book.txt"
        exit=0
        while [ $exit -ne 1 ]
        do
            echo "What operation do you want?"
            echo -e "add, list, find, del, exit: "
            read answer

            if [ "$answer" = "add" ]
            then
                ./Add.sh
            elif [ "$answer" = "list" ]
            then
                ./List.sh
            elif [ "$answer" = "find" ]
            then
                ./Search.sh
            elif [ "$answer" = "del" ]
            then
                ./Delete.sh
            elif [ "$answer" = "exit" ]
            then
                exit=1
            else
                echo "I do not understand the command."
            fi
        done

        exit 0
