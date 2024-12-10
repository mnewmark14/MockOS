#include <iostream>
#include "mockos/CommandPrompt.h"
#include "mockos/Constants.h"
#include "mockos/TouchCommand.h"
#include "mockos/AbstractCommand.h"
#include "mockos/AbstractFileSystem.h"
#include "mockos/AbstractFileFactory.h"
#include "mockos/SimpleFileSystem.h"
#include "mockos/SimpleFileFactory.h"
#include "mockos/AbstractFile.h"
#include "mockos/MacroCommand.h"
#include "mockos/RenameParsingStrategy.h"
#include "mockos/CopyCommand.h"
#include "mockos/RemoveCommand.h"
#include "mockos/LSCommand.h"
#include "mockos/CatCommand.h"
#include "mockos/DisplayCommand.h"
#include "mockos/TCParsingStrategy.h"

int main() {
    // Creates an instance of all the different command objects
    AbstractFileSystem* abstractSystem = new SimpleFileSystem();
    AbstractFileFactory* factory = new SimpleFileFactory();
    AbstractCommand* touch = new TouchCommand(abstractSystem, factory);
    AbstractCommand* ls = new LSCommand(abstractSystem);
    AbstractCommand* remove = new RemoveCommand(abstractSystem);
    AbstractCommand* cat = new CatCommand(abstractSystem);
    AbstractCommand* display = new DisplayCommand(abstractSystem);
    AbstractCommand* copy = new CopyCommand(abstractSystem);

    // Creates the new macro command rename
    MacroCommand* rename = new MacroCommand(abstractSystem);

    // Sets parsing strategy to the rename specific parsing strategy
    rename->setParseStrategy(new RenameParsingStrategy());

    // Adds copy and remove to the rename commands member variable
    rename->addCommand(copy);
    rename->addCommand(remove);

    //Touch-Cat Macro-command
    MacroCommand* tc = new MacroCommand(abstractSystem);
    tc->setParseStrategy(new TCParsingStrategy());

    // Adds touch and cat commands to the tc commands member variable
    tc->addCommand(touch);
    tc->addCommand(cat);

    // Creation of command prompt object, sets file system and file factory
    CommandPrompt* cp = new CommandPrompt();
    cp->setFileSystem(abstractSystem);
    cp->setFileFactory(factory);

    // Adds basic commands to cp
    cp->addCommand("touch", touch);
    cp->addCommand("ls", ls);
    cp->addCommand("rm", remove);
    cp->addCommand("cat", cat);
    cp->addCommand("ds", display);
    cp->addCommand("cp", copy);

    // Adds macro commands to cp
    cp->addCommand("rn", rename);
    cp->addCommand("tc", tc);

    // Allows us to test all commands
    cp->run();

    // Delete dynamically allocated objects
    delete cp;
    delete tc;
    delete rename;
    delete copy;
    delete display;
    delete cat;
    delete remove;
    delete ls;
    delete touch;
    delete factory;
    delete abstractSystem;

    return SUCCESS;
}
