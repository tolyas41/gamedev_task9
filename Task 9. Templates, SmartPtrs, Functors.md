Modify the container class previously developed

Inside, not instances or pointers to objects should be stored, but array of smart pointers to objects;

The container class becomes template (if is not already);

The container class must also store an array of strings of the given format:

Each line is an “action” - a string description of the action on the elements of the container. Possible options: "+", "-", "/", "*".

Implement the function of loading such an array of strings from a given file - each action in the file is on a new line;

Create function Calculate(…), which calculates the result of applying "actions" to the elements of the container;

All actions take place from left to right without priority;

The result of the previous action is the left operand of the next action;

The function returns a mathematical object or an error is signaled;

Create a class that stores map in itself for converting “action” lines into a functor for implementing this action.

The smart pointer class can be used standard or implemented by yourself;

Implement error checking in the program;

In Main (), make a demonstration of the work of all the given functionality.
