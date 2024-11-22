//30 commands
//1.Change your password to a password you would like to use for the remainder of the semester
passwd
//2.	Display the system’s date.
date
//3.	Count the number of lines in the /etc/passwd file
wc -l /etc/passwd
//4.	Find out who else is on the system.
who
//5.	Direct the output of the man pages for the date command to a file named mydate.
man date > mydate
//6.	Create a subdirectory called mydir.
mkdir mydir
//7.	Move the file mydate into the new subdirectory.
mv mydate mydir
//8.	Go to the subdirectory mydir and copy the file mydate to a new file called ourdate
cd mydir
cp mydate ourdate
//9.	List the contents of mydir.
mydate ourdate
//10.	Do a long listing on the file ourdate and note the permissions.
ls -l ourdate
//11.	Display the name of the current directory starting from the root.
pwd
//12.	Move the files in the directory mydir back to your home directory.
mv * ~/
//13.	Display the first 5 lines of mydate.
head -n 5 mydate
//14.	Display the last 8 lines of mydate.
tail -n 8 mydate
//15.	Remove the directory mydir.
rmdir mydir
//16.	Redirect the output of the long listing of files to a file named list
ls -l > list
//17.	Select any 5 capitals of states in India and enter them in a file named capitals1. Choose 5 more capitals and enter them in a file named capitals2. Choose 5 more capitals and enter them in a file named capitals3. Concatenate all 3 files and redirect the output to a file named capitals.
cat > capitals1
------
cat > capitals2
--------
cat capitals3
---------
cat capitals1 capitals2 capitals3 > capitals


//18.	Concatenate the file capitals2 at the end of file capitals.
cat capitals2 >> capitals
//19.	Give read and write permissions to all users for the file capitals.
chmod ugo+rw capitals
//20.	Give read permissions only to the owner of the file capitals. Open the file, make some changes and try to save it. What happens ?
chmod u=r capitals
nano capitals 
chmod u=rw capitals
//21. Create an alias to concatenate the 3 files capitals1, capitals2, capitals3 and redirect the output to a file named capitals. Activate the alias and make it run.
alias concatenate ='cat capitals1 capitals2 capitals3 > capitals'
//21.	Find out the number of times the string “the” appears in the file mydate.
 grep -o -i 'the' mydate | wc -l
//22.	Find out the line numbers on which the string “date” exists in mydate.
grep -n 'date' mydate
//23.	Print all lines of mydate except those that have the letter “i” in them.
sejal@Sejal:~$ grep -v 'i' mydate
//24.	List the words of 4 letters from the file mydate.
sejal@Sejal:~$ grep -o -E '\b[a-zA-Z]{4}\b' mydate
//25.	List 5 states in north east India in a file mystates. List their corresponding capitals in a file mycapitals. Use the paste command to join the 2 files.
cat > mystates
---------
cat > mycapitals
---------
paste mystates mycapitals
//26.	Use the cut command to print the 1 st and 3 rd columns of the /etc/passwd file for all students in this class.
grep '^student' /etc/passwd | cut -d: -f1,3
//27.	Count the number of people logged in and also trap the users in a file using the tee command.
who \ tee logged_user.txt \ wc -l
//28.	Convert the contents of mystates into uppercase.
tr '[:lower:]' '[:upper:]' <mystates_uppercase>
//29.	Create any two files & display the common values between them.
comm -12 <(sort file) <(sort file2)




