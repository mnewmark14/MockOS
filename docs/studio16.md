# Studio 16

# Responses:
Students:
1. Daniel Khen
2. Adam Shumway
3. Malcolm Newmark


Question Answers:
2a. To declare an interface, you need to make an abstract base class with pure virtual functions. 
3a. This is an example of interface inheritance, because we are inheriting from an abstract base class.
3b. These member variables should be private, since, according to the OOP principle of encapsulation, data of a class 
should remain internal. Since we probably aren't going to create more member classes by inheriting the TextFile class,
we should these member variables private, not protected. 
4. The test cases we ran were test1 : {'p', 'r', 'i', 'z', 'e'}, test 2: {''}, and test3: {'p', ' ', 'p'}.
We first called the write function on test1 and read it out to output "prize" We then called the append function on 
test2 and read it out to output "prize" (this is correct because test2 was an empty vector)
Finally, we called write on test3 function and read it out to output "p p"
5a. We created a pointer to an AbstractFile type and we set it to the address of the TextFile object we created.
   cout << "Call methods by aliased abstract class" << endl;
   AbstractFile* p;
   p = &textFile;
   p->write(test2); // Make textFile.contents blank again
   p->write(test1);
   p->read();
   p->append(test2);
   p->read();
   p->write(test3);
   p->read();
