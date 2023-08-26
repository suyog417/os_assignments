#!/bin/sh

read -p "Enter the name of addressbook to create or open it : " fname
touch "$fname.csv"

cnt=0
while [ cnt==0 ]
do
    echo "1.Insert record"
    echo "2.Modify record"
    echo "3.Delete record"
    echo "4.View Addressbook"
    echo "5.Exit"
    read -p "Enter your choice : " ch
    case $ch in 
        1 ) 
            read -p "Enter name : " name
            read -p "Enter age : " age
            read -p "Enter phone : " phone
            read -p "Enter city : " city
            echo "$name\t$age\t$phone\t$city" >> "$fname.csv"
        ;;
        2 )
            cat "$fname.csv"
            read -p "Enter line number for the record you want to edit " line_no
            echo "Enter new data :  "
            read -p "Enter name : " name
            read -p "Enter age : " age
            read -p "Enter phone : " phone
            read -p "Enter city : " city
            sed -i "${line_no}s/.*/"${name}"\t"${age}"\t"${phone}"\t"${city}"/" "$fname.csv"
            echo "Record Modified"
        ;;
        3 )
            read -p "Enter the line number of the record you want to delete : " line_no
            sed -i "${line_no}d" "$fname.csv"
            echo "Record Deleted."
        ;;
        4 )
            echo "Name\tAge\tPhone\tCity"
            cat "$fname.csv"
        ;;
        5 ) 
            exit
        ;;
        * )
            echo "Invaid Option.Enter a valid number from the list above."
        ;;
    esac
done