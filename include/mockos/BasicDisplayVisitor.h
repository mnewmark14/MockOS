#ifndef MOCKOS_BASICDISPLAYVISITOR_H
#define MOCKOS_BASICDISPLAYVISITOR_H

#include "AbstractFileVisitor.h"
#include "TextFile.h"
#include "ImageFile.h"

class BasicDisplayVisitor : public AbstractFileVisitor {
    // Displays text file
    void visit_TextFile(TextFile *textFile) override;
    // Displays image file
    void visit_ImageFile(ImageFile *imageFile) override;
};

#endif //MOCKOS_BASICDISPLAYVISITOR_H