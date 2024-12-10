# Studio 18

# Responses:
Students:
1. Daniel Khen
2. Adam Shumway
3. Malcolm Newmark


Question Answers:
2. Creating a new file system implementation that creates different file types than the SimpleFileSystem would be
   difficult since we would have re-override the abstract createFile method from AbstractFileSystem in that new 
   implementation. We would need to edit all the createFile methods defined in every file system implementation to 
   work with the new concrete file type. 
3. An advantage is that we separate the responsibility of creating an object to a new separate object, and a 
   disadvantage is that it is difficult to support adding new types of object to the factory. We should create a 
   new factory when we need to produce a new distinct type of object. If we introduce a new file type, we need to 
   update the code of the existing factories to support that new file type. We can use the same factory for both 
   similar file systems, but we need to use different factories for file systems managing different types of files.
4. In our test, we made a SimpleFileSystem and SimpleFileFactory, used the SimpleFileFactory to make a text file and 
   an image file, added those files to the SimpleFileSystem, opened those two files, wrote to the two files, read 
   the two files, and closed the two files. This test outputted the contents of the text file and image file as 
   expected without any errors. 
5. Now, SimpleFileSystem only depends on the AbstractFile interface. 