Build
From the Terminal, write 
mkdir build
cd build
cmake ..
cmake --build .

Run
./program_1

Data Structures Used
Circular linked lists: The board is thought of as a circular linked list, each node represents a space on the board. 
The tail node always points to the head node which makes a circle. This means that there is no end to it
Node: Holds monopoly space object and a pointer to the next node in the circle
MonopolySpace: Stores the property's name, color, price, and rent (with no houses)
Player Cursor: The player node in the circular linked lists follows the player’s position. Movement is done by going 
to the next pointer one step at a time

Function List
MonopolySpace
MonopolySpace(): initializes all fields to zero
MonopolySpace strings and int’s: overloads constructor to give names, value, rent, and color
isEqual(): compares spaces by names in 2
print(): displays the space’s information
Circular Linked List
addSpace: adds space to tail end of the list
addMany: adds spaces and stops at capacity
movePlayer: moves the player with steps via node to node and tracks GO passes
getPassGoCount: returns how many times the player has loops the board
printFromPlayer: will print a fixed number of spaces from what the position the player is in
removeByName: deletes the first node that matches the name
findByColor: traverses the boards 1 time and will return a vector of names that match the color
countSpaces: goes around the board 1 time and gives the number of nodes
clear: deletes all nodes by breaking the circular link and then follows by deleting linearly

Traversal and Movement Logic
The board is a linked list where the node's pointer is connected to the next space. The last one will connect the last 
node to GO which creates a circle/board. When moving, the node pointers step by step for however many steps are rolled. 
Since the list is circular, the player goes around and around the board with no end. No index math is used.


40 Space Board Limit
The board is 40 spaces. No more no less. This is made sure of with addSpace and nodeCount, if they equal 40 then 
insertion is not accepted and the function will return false. addMany stops adding when the board is at capacity.


