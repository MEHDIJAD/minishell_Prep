//* Command Data structure

//TODO one basic shell command 

struct SimpleCommand
{
    int _numberOfAvailableArguments; 
    //* how much space is allocated in memory for arguments.
    //! Allocate space in advance 

    int _numberOfArguments;
    //* how many arguments are currently in use.
    //? Example: In ls -l, this would be 2 (because you have ls and -l).

    char ** _arguments;
    //* A pointer to an array of strings, This stores the actual arguments of the command.
    //? Example: ["ls", "-l", NULL]

    SimpleCommand();
    //! Constructor (a special function in C++).

    void insertArgument(char *argument);
    //* Adds a new argument (word) to _arguments.
};

struct Command
{
    int _numberOfAvailableSimpleCommands;

    int _numberOfSimpleCommands;

    SimpleCommand ** _simpleCommands;

    char * _outFile;
    char * _inputFile;
    char * _errFile;
    int _background;
    ...;



};

