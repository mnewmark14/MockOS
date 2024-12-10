#ifndef MOCKOS_ABSTRACTFILEVISITOR_H
#define MOCKOS_ABSTRACTFILEVISITOR_H

class TextFile;  // forward declaration
class ImageFile; // forward declaration

using namespace std;

// Base class for file visitors, which display text and image files
class AbstractFileVisitor {
public:
    virtual void visit_TextFile(TextFile *textFile) = 0;
    virtual void visit_ImageFile(ImageFile *imageFile) = 0;
};

#endif //MOCKOS_ABSTRACTFILEVISITOR_H