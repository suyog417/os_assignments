#!/bin/sh


echo "1. Create a Addressbook"
echo "2. View Addressbook"
echo "3. Insert a record"
echo "4. Delete a record"
echo "5. Modify a record"
echo "6. Exit"
read -p "Enter your choice" choice



case $choice in 
    1 )
        read -p "Enter the name for your Addressbook : " fname
        touch $fname.txt
    ;;
    2 ) 
        echo "Name\tAge\tPhone"
        cat $fname.txt
    ;;
    3 )
        read -p "Enter the name : " name
        read -p "Enter the age : " age
        read -p "Enter the phone : " phone
        echo "$name\t$age\t$phone" >> "abc.txt"
esac

./view.sh $fname.txt