#ifndef MOCKOS_METADATADISPLAYVISITOR_H
#define MOCKOS_METADATADISPLAYVISITOR_H

#include "AbstractFileVisitor.h"
#include "TextFile.h"
#include "ImageFile.h"

class MetadataDisplayVisitor : public AbstractFileVisitor {
    // Displays text file metadata
    void visit_TextFile(TextFile *text) override;

    // Displays image file metadata
    void visit_ImageFile(ImageFile *image) override;
};


#endif //MOCKOS_METADATADISPLAYVISITOR_H