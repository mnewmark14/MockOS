# Studio 20

# Responses:
Students:
1. Daniel Khen
2. Adam Shumway
3. Malcolm Newmark


Question Answers:
2. If we do not delete the pointer to the file when the 'PasswordProxy' object is destroyed, it will lead 
to a memory leak because the memory that was allocated for the real file won't be freed. Therefore, we delete 
the file to prevent any memory leaks in our program.
4. I initialized a pointer to a TextFile, wrote to that file, made a PasswordProxy of that file, and tried reading, 
   writing, and displaying the file via the proxy object. I had to enter my password every time I tried to interact 
   with the file using the proxy object, but besides that, the operations acted the exact same than when interacting 
   with AbstractFile pointers without a password proxy. 
