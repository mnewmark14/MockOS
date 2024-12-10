# CSE 332 Lab Base
Repository for submitting lab work

Note: We will read this file as raw text rather than markdown.

Names: Malcolm Newmark, Adam Shumway, Daniel Khen
Lab #: 5

Division of Work:
 - For all studios we worked collaboratively, using CLion share sessions to work simultaneously
 - For the lab we split up the commands between the three of us. Adam made CatCommand, TC, and updated Touch
 - Malcolm made Remove, Rename, worked with Adam on CopyCommand and MacroCommands
 - Daniel made LSCommand, DisplayCommand, did most of main, and looked over everyone's work

Document your lab work here according to the lab specification
1. For this command, we use the getFileNames function from the AbstractFileSystem member variable in order to print 
   out all the file names if "ls" is called. If "ls -m" is called, we use the MetadataDisplayVisitor to display the 
   metadata of each file in the file system. We gain access to the pointer to each file in the file system by 
   opening the file with the file system and then closing the file when we're done displaying it.
2. For this command, we use the deleteFile function from the AbstractFileSystem member variable to delete
   the files entered along with the "rm" input.
3. For this functionality, we changed the execute function in TouchCommand.cpp so that if -p is added to the end of 
   the touch command, it prompts the user to create a password and makes a PasswordProxy with the file it already 
   initially created. Then, it adds either the PasswordProxy of the initially created file or just the initally 
   created file to the file system. 
4. Implementing cat command:
   We started this command by making CatCommand a ConcreteCommand object of the command pattern. We implemented the 
   interface of AbstractCommand. For the displayInfo method, we outputted that the cat command would work to display 
   and append contents to a file. For the execute method, we read in the program name and information from the user, 
   and if the input is to be displayed, the program will write out the input, if the user adds a '-a', then the 
   input will be appended onto the file. The execute method ends by closing the file. 
5. Implementing the display command:
   We started this command by making DisplayCommand a ConcreteCommand object of the command pattern. We implemented 
   the interface of AbstractCommand. For the displayInfo method, we outputted that display command displays the 
   contents of a file. For the execute method, we read in the program name and information and if the user added a 
   '-d' we displayed the contents of the file. This execute method ends by closing the file.
6. I implemented the prototype pattern by adding a virtual clone method to AbstractFile which takes in a string as a 
   parameter. Every implementation of this method in every concrete class returns a pointer to a copy of that object 
   with the string parameter as its name. 
7. Implementing the Macro command:
   We started this command by making MacroCommand a ConcreteCommand object of the command pattern. We implemented
   the interface of AbstractCommand. For the displayInfo method, we outputted that macro command creates new 
   commands out of existing commands. For the execute method, if the number of commands was the same as the number 
   of inputs, it executes each command with the corresponding parsed input, and then checks to see if each was 
   successful. This execute method ends by closing the file. The addCommand and setParseStrategy methods were also 
   added as public to the class; addCommand pushed back an inputted command onto the vector of AbstractCommands, 
   setParseStrategy took an inputted parsing strategy as a parameter and set it equal to the original parse strategy.
8. Implementing the rename command:
   We started this command declaring and defining the RenameParsingStrategy class. It extends the 
   AbstractParsingStrategy class. It simply pulls the first two words from user input (let's call them first and
   second) and returns a vector {first second, first}. Next, in main, we created a new instance of a MacroCommand
   object called rename, updating its parsing strategy to RenameParsingStrategy, and inserted the two commands of
   copy and remove. Then, we added to our CommandPrompt object cp the command rename, with user input "rn".
9. Implementing the touch-cat command:
   We started this command by creating a new MacroCommand object called tc in main. We then created new header and 
   source files TCParsingStrategy, in order to parse the inputted file for both the touch and cat commands. We set this
   TCParsingStrategy to be the parsing strategy for our tc MacroCommand. We then used the addCommand function
   to insert the two functions of touch and cat.
10. During our testing, we realized we made the display command name "dp" instead of "ds" and we fixed this. Here are
first tests:

[d.d.khen@shell lab5]$ ./mockos
Enter a command, q to quit, help for a list of commands, or
help followed by a command name for more information about
that command.
$  touch text.txt
Enter a command, q to quit, help for a list of commands, or
help followed by a command name for more information about
that command.
$  touch image.img
Enter a command, q to quit, help for a list of commands, or
help followed by a command name for more information about
that command.
$  ls
image.img           text.txt
Enter a command, q to quit, help for a list of commands, or
help followed by a command name for more information about
that command.
$  ls -m
image.img           image       0
text.txt            text        0
Enter a command, q to quit, help for a list of commands, or
help followed by a command name for more information about
that command.
$  help touch
touch creates a file. touch can be invoked with the command: touch <filename>
touch <filename> -p will create a password protected file and prompt you to make your password.
Enter a command, q to quit, help for a list of commands, or
help followed by a command name for more information about
that command.
$  touch protected.txt -p
What is the password?
password
Enter a command, q to quit, help for a list of commands, or
help followed by a command name for more information about
that command.
$  ls
image.img           protected.txt
text.txt
Enter a command, q to quit, help for a list of commands, or
help followed by a command name for more information about
that command.
$  touch
Error: Failed creating a new file.
This command failed and returned error: 13
Enter a command, q to quit, help for a list of commands, or
help followed by a command name for more information about
that command.
$  ls -a
Error: option not supported for ls command
This command failed and returned error: 15
Enter a command, q to quit, help for a list of commands, or
help followed by a command name for more information about
that command.
$  help ls
ls outputs the names of all files currently in the file system. ls can be invoked with the command: ls
ls -m will display the metadata for each file as well.
Enter a command, q to quit, help for a list of commands, or
help followed by a command name for more information about
that command.
$  help rm
Remove removes a file, remove can be invoked with the command: rm <filename>
Enter a command, q to quit, help for a list of commands, or
help followed by a command name for more information about
that command.
$  touch fileToRemove.txt
Enter a command, q to quit, help for a list of commands, or
help followed by a command name for more information about
that command.
$  rm fileToRemove.txt
Enter a command, q to quit, help for a list of commands, or
help followed by a command name for more information about
that command.
$  ls
image.img           protected.txt
text.txt
Enter a command, q to quit, help for a list of commands, or
help followed by a command name for more information about
that command.
$  rm fileToRemove.txt
Deletion was unsuccessful
This command failed and returned error: 19
Enter a command, q to quit, help for a list of commands, or
help followed by a command name for more information about
that command.
$  help cat
cat both displays and then appends content to a file. Usage: cat <fileName> [-a]
Enter a command, q to quit, help for a list of commands, or
help followed by a command name for more information about
that command.
$  cat text.txt
hello world
:q
Enter a command, q to quit, help for a list of commands, or
help followed by a command name for more information about
that command.
$  dp text.txt

Enter a command, q to quit, help for a list of commands, or
help followed by a command name for more information about
that command.
$  cat text.txt
hello world
:wq
Enter a command, q to quit, help for a list of commands, or
help followed by a command name for more information about
that command.
$  dp text.txt
hello world
Enter a command, q to quit, help for a list of commands, or
help followed by a command name for more information about
that command.
$  cat text.txt -a
hello world

it's me
:wq
Enter a command, q to quit, help for a list of commands, or
help followed by a command name for more information about
that command.
$  dp text.txt
hello worldit's me
Enter a command, q to quit, help for a list of commands, or
help followed by a command name for more information about
that command.
$  cat dne.txt
Error: This file does not exist
This command failed and returned error: 8
Enter a command, q to quit, help for a list of commands, or
help followed by a command name for more information about
that command.
$  help dp
ds opens a file and displays its contents. Usage: ds <fileName> [-d]
Enter a command, q to quit, help for a list of commands, or
help followed by a command name for more information about
that command.
$  dp dne.txt
Error: This file does not exist
This command failed and returned error: 8
Enter a command, q to quit, help for a list of commands, or
help followed by a command name for more information about
that command.
$  cat image.img
X X X X X3
:wq
Enter a command, q to quit, help for a list of commands, or
help followed by a command name for more information about
that command.
$  dp image.img
X X
X
X X
Enter a command, q to quit, help for a list of commands, or
help followed by a command name for more information about
that command.
$  ls
image.img           protected.txt
text.txt
Enter a command, q to quit, help for a list of commands, or
help followed by a command name for more information about
that command.
$  cat protected.txt
i am protected
:wq
Enter your password:
notpassowrd
This command failed and returned error: 10
Enter a command, q to quit, help for a list of commands, or
help followed by a command name for more information about
that command.
$  Command not found
Enter a command, q to quit, help for a list of commands, or
help followed by a command name for more information about
that command.
$  cat protected.txt
i am super protected
:wq
Enter your password:
password
Enter a command, q to quit, help for a list of commands, or
help followed by a command name for more information about
that command.
$  Command not found
Enter a command, q to quit, help for a list of commands, or
help followed by a command name for more information about
that command.
$  dp protected.txt
Enter your password:
password
i am super protected
Enter a command, q to quit, help for a list of commands, or
help followed by a command name for more information about
that command.
$  Command not found
Enter a command, q to quit, help for a list of commands, or
help followed by a command name for more information about
that command.
$  help cp
cp will copy a file that exists in the file system and add the copy to the file
system with a different name. It is invoked with the following command structure:
cp <file_to_copy> <new_name_with_no_extension>
Enter a command, q to quit, help for a list of commands, or
help followed by a command name for more information about
that command.
$  cp thiswontwork.txt lol
Error: file to copy does not exist in file system
This command failed and returned error: 8
Enter a command, q to quit, help for a list of commands, or
help followed by a command name for more information about
that command.
$  cp this also wont work
Error: file to copy does not exist in file system
This command failed and returned error: 8
Enter a command, q to quit, help for a list of commands, or
help followed by a command name for more information about
that command.
$  cp thistoo
Error: option not supported for cp command
This command failed and returned error: 15
Enter a command, q to quit, help for a list of commands, or
help followed by a command name for more information about
that command.
$  ls
image.img           protected.txt
text.txt
Enter a command, q to quit, help for a list of commands, or
help followed by a command name for more information about
that command.
$  cp image.img imageCopy
Enter a command, q to quit, help for a list of commands, or
help followed by a command name for more information about
that command.
$  ls
image.img           imageCopy.img
protected.txt       text.txt
Enter a command, q to quit, help for a list of commands, or
help followed by a command name for more information about
that command.
$  dp imageCopy.img
Error: invalid size
Enter a command, q to quit, help for a list of commands, or
help followed by a command name for more information about
that command.
$
   
After these tests, we realized we forgot to set the size member variables of our image copy in our image clone function,
so we went and fixed that. However, it was at this stage that we also realized that our clone functions were making
shallow copies, not deep copies, so we went and fixed this as well. 

[d.d.khen@shell lab5]$ ./mockos
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  touch image.img
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  touch text.txt
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  touch protected.img -p
What is the password?
123
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  ls
image.img           protected.img
text.txt
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  cat protected.img
X X X X X3
:wq
Enter your password:
123
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  Command not found
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  ds protected.img
Enter your password:
123
X X
X
X X
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  Command not found
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  cp protected.img copy
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  ls
copy.img            image.img
protected.img       text.txt
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  ds copy.img
Enter your password:
123
X X
X
X X
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  Command not found
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  cp text.txt copy
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  ls
copy.img            copy.txt
image.img           protected.img
text.txt
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  ds copy.txt

Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  cat text.txt
hello
:wq
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  ds copy.txt

Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  ds text.txt
hello
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  help rn
MacroCommand constructs commands out of other commands
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  rn
Error: option not supported for cp command
This command failed and returned error: 15
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  rn
Error: option not supported for cp command
This command failed and returned error: 15
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  rn copy.txt txtcopy
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  ls
copy.img            image.img
protected.img       text.txt
txtcopy.txt
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  tc newtext.txt -p
What is the password?
123
hello worlddddd
:wq
Enter your password:
123
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  Command not found
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  ls
copy.img            image.img
newtext.txt         protected.img
text.txt            txtcopy.txt
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  ds newtxt.txt
Error: This file does not exist
This command failed and returned error: 8
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  ds newtext.txt
Enter your password:
123
hello worlddddd
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  Command not found
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  ls -m
Enter your password:
123
copy.img            image       9
image.img           image       0
Enter your password:
123
newtext.txt         text       15
Enter your password:
123
protected.img       image       9
text.txt            text        5
txtcopy.txt         text        0
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  Command not found
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  help
Available Commands: cat cp ds ls rm rn tc touch
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$  q
Quitting Program.