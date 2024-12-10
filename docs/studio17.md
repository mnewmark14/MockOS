# Studio 17

# Responses:
Students:
1. Daniel Khen
2. Adam Shumway
3. Malcolm Newmark


Question Answers:
2. The helper function should be private. We aren't using ImageFile as a base class for other derived classes, and 
   we want to abstract this unnecessary implementation detail away from the client. The test cases we ran were 
   test1: {'X', 'X', ' ', 'X', '2'}, test2: {'0'}, and test3: {'X', 'O', 'X', ' ', '2'}. We tested writing these 
   images to an ImageFile object, reading them, attempting the append() operation and verifying that it returned a 
   non-zero value, and using getSize() and getName() with them. The image in test3 is invalid, so we made sure that 
   trying to write that image would return a non-zero value. We then did the same thing but ran the method through a 
   pointer to an AbstractFile object instead. All tests ran as expected.
3. New subclasses that define the interface can be created and used without modification to the client, which 
   makes it easy to reuse the client.
4. We would need to add functionality in SimpleFileSystem::createFile to support creating a MusicFile, since this 
   method only supports creating an ImageFile or TextFile right now.