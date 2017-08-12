//
//  main.cpp
//  Graph
//
//  Created by 翁 旭扬 on 14/12/19.
//  Copyright (c) 2014年 翁 旭扬. All rights reserved.
//

#include <iostream>
using namespace std;


//template <typename E>
class List { // List ADT
private:
    void operator =(const List&) {} // Protect assignment
    List(const List&) {} // Protect copy constructor
public:
    List() {} // Default constructor
   // virtual ˜List() {} // Base destructor
    // Clear contents from the list, to make it empty.
    virtual void clear() = 0;
    // Insert an element at the current location.
    // item: The element to be inserted
    virtual void insert(const int& item) = 0;
    // Append an element at the end of the list.
    // item: The element to be appended.
    virtual void append(const int& item) = 0;
    // Remove and return the current element.
    // Return: the element that was removed.
    virtual int remove() = 0;
    // Set the current position to the start of the list
    virtual void moveToStart() = 0;
    // Set the current position to the end of the list
    virtual void moveToEnd() = 0;
    // Move the current position one step left. No change
    // if already at beginning.
    virtual void prev() = 0;
    // Move the current position one step right. No change
    // if already at end.
    virtual void next() = 0;
    // Return: The number of elements in the list.
    virtual int length() const = 0;
    // Return: The position of the current element.
    virtual int currPos() const = 0;
    // Set current position.
    // pos: The position to make current.
    virtual void moveToPos(int pos) = 0;
    // Return: The current element.
    virtual const int& getValue() const = 0;
};
// Linked list implementation
//template <typename E>

// Singly linked list node
//template <typename E>
class Edge {
    int vert, wt;
public:
    Edge() { vert = -1; wt = -1; }
    Edge(int v, int w) { vert = v; wt = w; }
    int vertex() { return vert; }
    int weight() { return wt; }
};
class Link {
public:
    Edge element; // Value for this node
    Link *next; // Pointer to next node in list
    // Constructors
    Link(const Edge& elemval, Link* nextval =NULL)
    { element = elemval; next = nextval; }
    Link(Link* nextval =NULL) { next = nextval; }
};
class LList: public List {
private:
    Link* head; // Pointer to list header
    Link* tail; // Pointer to last element
    Link* curr; // Access to current element
    int cnt; // Size of list
    void init() { // Intialization helper method
        curr = tail = head = new Link;
        cnt = 0;
    }
    void removeall() { // Return link nodes to free store
        while(head != NULL) {
            curr = head;
            head = head->next;
            delete curr;
        }
    }
public:
    LList(int size=10) { init(); } // Constructor
   // ˜LList() { removeall(); } // Destructor
    void print() const; // Print list contents
    void clear() { removeall(); init(); } // Clear list
    // Insert "it" at current position
    void insert(const Edge& it) {
        curr->next = new Link(it, curr->next);
        if (tail == curr) tail = curr->next; // New tail
        cnt++;
    }
    void append(const Edge& it) { // Append "it" to list
        tail = tail->next = new Link(it, NULL);
        cnt++;
    }
 //    Remove and return current element
  int remove() {
    //    Assert(curr->next != NULL, "No element");
        Edge it = curr->next->element; // Remember value
    Link* ltemp = curr->next; // Remember link node
        if (tail == curr->next) tail = curr; // Reset tail
        curr->next = curr->next->next; // Remove from list
        delete ltemp; // Reclaim space
        cnt--; // Decrement the count
        return it.vertex();
    }
    void moveToStart() // Place curr at list start
    { curr = head; }
    void moveToEnd() // Place curr at list end
    { curr = tail; }
    // Move curr one step left; no change if already at front
    void prev() {
        if (curr == head) return; // No previous element
        Link* temp = head;
        // March down list until we find the previous element
        while (temp->next!=curr) temp=temp->next;
        curr = temp;
    }
    // Move curr one step right; no change if already at end
    void next()
    { if (curr != tail) curr = curr->next; }
    int length() const { return cnt; } // Return length
    // Return the position of the current element
    int currPos() const {
        Link* temp = head;
        int i;
        for (i=0; curr != temp; i++)
            temp = temp->next;
        return i;
    }
    // Move down list to "pos" position
    void moveToPos(int pos) {
       // Assert ((pos>=0)&&(pos<=cnt), "Position out of range");
        curr = head;
        for(int i=0; i<pos; i++) curr = curr->next;
    }
    const int& getValue() const { // Return current element
       // Assert(curr->next != NULL, "No value");
        return curr->next->element.vertex();
    }
};

// Graph abstract class. This ADT assumes that the number
// of vertices is fixed when the graph is created.
class Graph {
private:
    void operator =(const Graph&) {} // Protect assignment
    Graph(const Graph&) {} // Protect copy constructor
public:
    Graph() {} // Default constructor
   // virtual ˜Graph() {} // Base destructor
    // Initialize a graph of n vertices
    virtual void Init(int n) =0;
    // Return: the number of vertices and edges
    virtual int n() =0;
    virtual int e() =0;
    // Return v’s first neighbor
    virtual int first(int v) =0;
    // Return v’s next neighbor
    virtual int next(int v, int w) =0;
    // Set the weight for an edge
    // i, j: The vertices
    // wgt: Edge weight
    virtual void setEdge(int v1, int v2, int wght) =0;
    // Delete an edge
    // i, j: The vertices
    virtual void delEdge(int v1, int v2) =0;
    // Determine if an edge is in the graph
    // i, j: The vertices
    // Return: true if edge i,j has non-zero weight
    virtual bool isEdge(int i, int j) =0;
    // Return an edge’s weight
    // i, j: The vertices
    // Return: The weight of edge i,j, or zero
    virtual int weight(int v1, int v2) =0;
    // Get and Set the mark value for a vertex
    // v: The vertex
    // val: The value to set
    virtual int getMark(int v) =0;
    virtual void setMark(int v, int val) =0;
};
// Edge class for Adjacency List graph representation


// Implementation for the adjacency matrix representation
class Graphm : public Graph {
private:
    int numVertex, numEdge; // Store number of vertices, edges
    int **matrix; // Pointer to adjacency matrix
    int *mark; // Pointer to mark array
public:
    Graphm(int numVert) // Constructor
    { Init(numVert); }
  //  ˜Graphm() { // Destructor
    //    delete [] mark; // Return dynamically allocated memory
      //  for (int i=0; i<numVertex; i++)
        //    delete [] matrix[i];
        //delete [] matrix;
    //}
    void Init(int n) { // Initialize the graph
        int i;
        numVertex = n;
        numEdge = 0;
        mark = new int[n]; // Initialize mark array
        for (i=0; i<numVertex; i++)
            mark[i] = 0;
        matrix = (int**) new int*[numVertex]; // Make matrix
        for (i=0; i<numVertex; i++)
            matrix[i] = new int[numVertex];
        for (i=0; i< numVertex; i++) // Initialize to 0 weights
            for (int j=0; j<numVertex; j++)
                matrix[i][j] = 0;
    }
    int n() { return numVertex; } // Number of vertices
    int e() { return numEdge; } // Number of edges
    // Return first neighbor of "v"
    int first(int v) {
        for (int i=0; i<numVertex; i++)
                if (matrix[v][i] != 0) return i;
            return numVertex; // Return n if none
        }
        // Return v’s next neighbor after w
        int next(int v, int w) {
            for(int i=w+1; i<numVertex; i++)
                if (matrix[v][i] != 0)
                    return i;
            return numVertex; // Return n if none
        }
        
        // Set edge (v1, v2) to "wt"
        void setEdge(int v1, int v2, int wt) {
            //     Assert(wt>0, "Illegal weight value");
            if (matrix[v1][v2] == 0) numEdge++;
            matrix[v1][v2] = wt;
        }
        void delEdge(int v1, int v2) { // Delete edge (v1, v2)
            if (matrix[v1][v2] != 0) numEdge--;
            matrix[v1][v2] = 0;
        }
        bool isEdge(int i, int j) // Is (i, j) an edge?
        { return matrix[i][j] != 0; }
        int weight(int v1, int v2) { return matrix[v1][v2]; }
        int getMark(int v) { return mark[v]; }
        void setMark(int v, int val) { mark[v] = val; }
    };

void PreVisit(Graph* G,int v)
{
    cout<<v<<endl;
}
void PostVisit(Graph* G,int v)
{
    cout<<G<<endl;
}
void DFS(Graph* G, int v) { // Depth first search
     PreVisit(G, v);// Take appropriate action
    G->setMark(v, 1);
    for (int w=G->first(v); w<G->n(); w = G->next(v,w))
    {
        if (G->getMark(w) == 0)
        {
            // PreVisit(G, v);
            cout<<"<"<<v<<","<<w<<">"<<"               ";
            DFS(G, w);
            
        }
      //  else
        //{
    //PreVisit(G, w); // Take appropriate action
        //}
    
    }
   // PreVisit(G, v);
  
    }
void graphTraverse(Graph* G) {
    int v;
    for (v=0; v<G->n(); v++)
        G->setMark(v, 0); // Initialize mark bits
    for (v=0; v<G->n(); v++)
        if (G->getMark(v) == 0)
            DFS(G, v);
}
int main(int argc, const char * argv[]) {
    // insert code here...
    
    Graphm mar(30);
    mar.setEdge(1,0,2);
     mar.setEdge(0,1,2);
    mar.setEdge(3,0,2);
    mar.setEdge(0,3,2);
    mar.setEdge(2,0,2);
    mar.setEdge(0,4,2);
   mar.setEdge(4,0,2);
     mar.setEdge(0,2,2);
     mar.setEdge(5,0,2);
     mar.setEdge(6,0,2);
     mar.setEdge(7,0,2);
     mar.setEdge(8,0,2);
     mar.setEdge(9,0,2);
     mar.setEdge(0,5,2);
     mar.setEdge(0,6,2);
     mar.setEdge(0,7,2);
     mar.setEdge(0,8,2);
     mar.setEdge(0,9,2);
  cout<<"Edge Set"<<"     "<<"Traversal Order"<<endl;
cout<<"                    ";
    //graphTraverse(&mar);
    DFS(&mar,4);
    return 0;
}
