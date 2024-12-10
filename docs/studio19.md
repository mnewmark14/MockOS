# Studio 19

# Responses:
Students:
1. Daniel Khen
2. Adam Shumway
3. Malcolm Newmark


Question Answers:
2. I created a new text file, wrote the string "hello" (as a vector<char>) to the file, stored the result of reading 
   the file into a local variable, changed the first character of the local variable, and re-wrote the text file 
   with the contents of the local variable. I made sure everything was working by printing out the contents of the 
   text file at each step.
3. First, the concrete visitor is called with the object passed in as a parameter. Then, the object has accept() 
   called on it, which requests the concrete visitor to visit the object. The concrete visitor then visits the object.
4. The visitor pattern uses delegation by having a visitor class implement various visit methods that handle logic 
   for interacting with different types of elements, which adds functionality to a class hierarchy without 
   modifying the concrete classes' interfaces.
5. Every time that we decide to add a new concrete file type that should be visitable, we need to modify each 
   concrete visitor to support visiting that new concrete file type. Thus, it might be a bad idea to use the visitor 
   pattern when we have a lot of unique visitors, and we are consistently adding new concrete file types to our program. 