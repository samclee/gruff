# gruff
A single-header graph-implementation library in C++14. Designed for quick constuction and visualization. Gotta have a speedy way of checking graph-related interview problems, ya know.

## Classes
### Node
#### Members
  - neighbors: private set<string>
  - marked: private bool

#### Functions
  - Node()
  
  Default constructor.
  - bool isMarked()
  
  Getter for _marked_ member.
  
  __Returns:__ Whether the Node is marked or not (useful for BFS/DFS-type algorithms).
  
  - set<string> getNeighbors()
  
  Getter for the _neighbors_ member.
  
  __Returns:__ The neighbor set of the Node.
  
  - void mark()
  
  Marks the Node.
  
  - void addNeighbor(string)
  
  Adds a Node to the neighbor set.
  
  __Arguments:__ The name of a Node.
  
  - void removeNeighbor(string)
  
  Removes a Node from the neighbor set. Does nothing if the neighbor set does not contain a neighbor with the given name.
  
  __Arguments:__ Takes the name of a Node and removes it from the neighbor set.

### Graph (directed)
#### Members
  - nodes: protected map<string, Node>
#### Functions
  - Graph()
  
  Default constructor
  
  - Graph(string)
  
  Input file constructor. Parses file into a graph. Usage specifics can be found in the Usage section.
  
  __Arguments:__ The name of the file to parse.
  
  - void addNode(string)
  
  Adds a Node to the Graph.
  
  __Arguments:__ The name of the Node to create.
  
  - void removeNode(string)
  
  Removes a Node from the Graph. Does nothing if the Graph does not contain the Node.
  
  __Arguments:__ The name of the Node to remove.
  
  - addEdge(string, string)
  
  Creates an directed edge between the Node names, with the start point at the first argument and the end point at the second argument. If either Node does not exist, it is created.
  
  __Arguments:__ Two Node names.
  
  - removeEdge(string, string)
  
  Removes the directed edge between the Node names, with the start point at the first argument and the end point at the second argument. Does nothing if the edge does not exist.
  
  __Arguments:__ Two Node names.
  
  - void interactiveAdd()
  
  My preferred method of Graph construction. Running this will prompt the user with instructions to add edge in the CLI.
  
