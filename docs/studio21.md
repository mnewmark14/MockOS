# Studio 21

Team Members:
1. Adam Shumway
2. Malcolm Newmark
3. Daniel Khen

2. We declare the virtual destructor for the Abstract Command class in order to make sure that the proper 
destructors are called when deleting objects through base class pointers which will help to prevent any 
memory leaks and ensure that the resources of the allocated classes are cleaned up correctly.
3. The command prompt be easily configured to use different file system implementations and different file factory 
implementations. Our use of configuring the command prompt to only need to know an AbstractFileSystem and 
AbstractFileFactory object to work makes it compatible with any implementation of a file system and file factory.
4. The first test I ran simply tested properly inputting "help", "help touch", and "q", which all worked
   properly:
   /Users/malcolm/CLionProjects/oop-work-ballllllllllllllll/cmake-build-debug/src/studio21
   Enter a command, q to quit, help for a list of commands, or
   help followed by a command name for more information about
   that command.
   $  help
   Available Commands: touch
   Enter a command, q to quit, help for a list of commands, or
   help followed by a command name for more information about
   that command.
   $  help touch
   touch creates a file, touch can be invoked with the command: touch <filename>
   Enter a command, q to quit, help for a list of commands, or
   help followed by a command name for more information about
   that command.
   $  q
   Quitting Program.

Process finished with exit code 0

Next, I tested badly formed inputs, and they did not work as intended:
/Users/malcolm/CLionProjects/oop-work-ballllllllllllllll/cmake-build-debug/src/studio21
Enter a command, q to quit, help for a list of commands, or
help followed by a command name for more information about
that command.
$  hel
Command not found
Enter a command, q to quit, help for a list of commands, or
help followed by a command name for more information about
that command.
$  help
Available Commands: touch
Enter a command, q to quit, help for a list of commands, or
help followed by a command name for more information about
that command.
$  help green
Command not found
Enter a command, q to quit, help for a list of commands, or
help followed by a command name for more information about
that command.
$  q
Quitting Program.

Process finished with exit code 0

Next I tested entering touch without a file name, which did not work. This is intentional:
/Users/malcolm/CLionProjects/oop-work-ballllllllllllllll/cmake-build-debug/src/studio21
Enter a command, q to quit, help for a list of commands, or
help followed by a command name for more information about
that command.
$  help touch
touch creates a file, touch can be invoked with the command: touch <filename>
Enter a command, q to quit, help for a list of commands, or
help followed by a command name for more information about
that command.
$  touch
Enter a command, q to quit, help for a list of commands, or
help followed by a command name for more information about
that command.
$  Error: Failed creating a new file.
This command failed and returned error: 13

Finally, we made a text file using the touch command and we successfully opened the file after running the command.
/Users/malcolm/CLionProjects/oop-work-ballllllllllllllll/cmake-build-debug/src/studio21
Enter a command, q to quit, help for a list of commands, or
help followed by a command name for more information about
that command.
$  touch file.txt
Enter a command, q to quit, help for a list of commands, or
help followed by a command name for more information about
that command.
$  q
Quitting Program.
File successfully opened

Process finished with exit code 0
