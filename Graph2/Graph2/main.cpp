//
//  main.cpp
//  Graph
//
//  Created by 翁 旭扬 on 14/12/19.
//  Copyright (c) 2014年 翁 旭扬. All rights reserved.
//

#include <iostream>
using namespace std;

template <typename E> class List { // List ADT
private:
    void operator =(const List&) {} // Protect assignment
    List(const List&) {} // Protect copy constructor
public:
    List() {} // Default constructor
    //virtual ˜List() {} // Base destructor
    // Clear contents from the list, to make it empty.
    virtual void clear() = 0;
    // Insert an element at the current location.
    // item: The element to be inserted
    virtual void insert(const E& item) = 0;
    // Append an element at the end of the list.
    // item: The element to be appended.
    virtual void append(const E& item) = 0;
    // Remove and return the current element.
    // Return: the element that was removed.
    virtual E remove() = 0;
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
    virtual const E& getValue() const = 0;
};


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
template <typename E>
class Link {
public:
    E element; // Value for this node
    Link *next; // Pointer to next node in list
    // Constructors
    Link(const E& elemval, Link* nextval =NULL)
    { element = elemval; next = nextval; }
    Link(Link* nextval =NULL) { next = nextval; }
};

template <typename E>
class LList: public List<E>
{
private:
    Link<E>* head; // Pointer to list header
    Link<E>* tail; // Pointer to last element
    Link<E>* curr; // Access to current element
    int cnt; // Size of list
    void init() { // Intialization helper method
        curr = tail = head = new Link<E>;
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
    //  ˜LList() { removeall(); } // Destructor
    void print() const; // Print list contents
    void clear() { removeall(); init(); } // Clear list
    // Insert "it" at current position
    void insert(const E& it) {
        curr->next = new Link<E>(it, curr->next);
        if (tail == curr) tail = curr->next; // New tail
        cnt++;
    }
    void append(const E& it) { // Append "it" to list
        tail = tail->next = new Link<E>(it, NULL);
        cnt++;
    }
    // Remove and return current element
    E remove() {
        // ssert(curr->next != NULL, "No element");
        E it = curr->next->element; // Remember value
        Link<E>* ltemp = curr->next; // Remember link node
        if (tail == curr->next) tail = curr; // Reset tail
        curr->next = curr->next->next; // Remove from list
        delete ltemp; // Reclaim space
        cnt--; // Decrement the count
        return it;
    }
    void moveToStart() // Place curr at list start
    { curr = head; }
    void moveToEnd() // Place curr at list end
    { curr = tail; }
    // Move curr one step left; no change if already at front
    void prev() {
        if (curr == head) return; // No previous element
        Link<E>* temp = head;
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
        Link<E>* temp = head;
        int i;
        for (i=0; curr != temp; i++)
            temp = temp->next;
        return i;
    }
    // Move down list to "pos" position
    void moveToPos(int pos) {
        //Assert ((pos>=0)&&(pos<=cnt), "Position out of range");
        curr = head;
        for(int i=0; i<pos; i++) curr = curr->next;
    }
    const  E& getValue() const { // Return current element
        //    Assert(curr->next != NULL, "No value");
        return curr->next->element;
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
class Graphl : public Graph {
private:
    List<Edge>** vertex; // List headers
    int numVertex, numEdge; // Number of vertices, edges
    int *mark; // Pointer to mark array
public:
    Graphl(int numVert)
    { Init(numVert); }
    // ˜Graphl() { // Destructor
    //   delete [] mark; // Return dynamically allocated memory
    //  for (int i=0; i<numVertex; i++) delete [] vertex[i];
    //delete [] vertex;
    //}
    void Init(int n) {
        int i;
        numVertex = n;
        numEdge = 0;
        mark = new int[n]; // Initialize mark array
        for (i=0; i<numVertex; i++) mark[i] = 0;
        // Create and initialize adjacency lists
        vertex = (List<Edge>**) new List<Edge>*[numVertex];
        for (i=0; i<numVertex; i++)
        {
            vertex[i] = new LList<Edge>();
        }
    }
    int n() { return numVertex; } // Number of vertices
    int e() { return numEdge; } // Number of edges
    int first(int v) { // Return first neighbor of "v"
        if (vertex[v]->length() == 0)
            return numVertex; // No neighbor
        vertex[v]->moveToStart();
        Edge it = vertex[v]->getValue();
        return it.vertex();
    }
    // Get v’s next neighbor after w
    int next(int v, int w) {
        Edge it;
        if (isEdge(v, w)) {
            if ((vertex[v]->currPos()+1) < vertex[v]->length()) {
                vertex[v]->next();
                it = vertex[v]->getValue();
                return it.vertex();
            }
        }
        return n(); // No neighbor
    }
    
    // Set edge (i, j) to "weight"
    void setEdge(int i, int j, int weight) {
        // Assert(weight>0, "May not set weight to 0");
        Edge currEdge(j, weight);
        if (isEdge(i, j)) { // Edge already exists in graph
            vertex[i]->remove();
            vertex[i]->insert(currEdge);
        }
        else { // Keep neighbors sorted by vertex index
            numEdge++;
            for (vertex[i]->moveToStart();
                 vertex[i]->currPos() < vertex[i]->length();
                 vertex[i]->next()) {
                Edge temp = vertex[i]->getValue();
                if (temp.vertex() > j) break;
            }
            vertex[i]->insert(currEdge);
        }
    }
    void delEdge(int i, int j) { // Delete edge (i, j)
        if (isEdge(i,j)) {
            vertex[i]->remove();
            numEdge--;
        }
    }
    bool isEdge(int i, int j) { // Is (i,j) an edge?
        Edge it;
        for (vertex[i]->moveToStart();
             vertex[i]->currPos() < vertex[i]->length();
             vertex[i]->next()) { // Check whole list
            Edge temp = vertex[i]->getValue();
            if (temp.vertex() == j) return true;
        }
        return false;
    }
    int weight(int i, int j) { // Return weight of (i, j)
        Edge curr;
        if (isEdge(i, j)) {
            curr = vertex[i]->getValue();
            return curr.weight();
        }
        else return 0;
    }
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
            cout<<"<"<<v<<","<<w<<">"<<"               ";
            DFS(G, w);
        }
    }
    
}
// Abstract queue class
template <typename E> class Queue {
private:
    void operator =(const Queue&) {} // Protect assignment
    Queue(const Queue&) {} // Protect copy constructor
public:
    Queue() {} // Default
  //  virtual ˜Queue() {} // Base destructor
    // Reinitialize the queue. The user is responsible for
    // reclaiming the storage used by the queue elements.
    virtual void clear() = 0;
    // Place an element at the rear of the queue.
    // it: The element being enqueued.
    virtual void enqueue(const E&) = 0;
    // Remove and return element at the front of the queue.
    // Return: The element at the front of the queue.
    virtual E dequeue() = 0;
    // Return: A copy of the front element.
    virtual const E& frontValue() const = 0;
    // Return: The number of elements in the queue.
    virtual int length() const = 0;
};
// Array-based queue implementation
template <typename E> class AQueue: public Queue<E> {
private:
    int maxSize; // Maximum size of queue
    int front; // Index of front element
    int rear; // Index of rear element
    E *listArray; // Array holding queue elements
public:
    AQueue(int size =10) { // Constructor
        // Make list array one position larger for empty slot
        maxSize = size+1;
        rear = 0; front = 1;
        listArray = new E[maxSize];
    }
   // ˜AQueue() { delete [] listArray; } // Destructor
    void clear() { rear = 0; front = 1; } // Reinitialize
    void enqueue(const E& it) { // Put "it" in queue
       // Assert(((rear+2) % maxSize) != front, "Queue is full");
        rear = (rear+1) % maxSize; // Circular increment
        listArray[rear] = it;
    }
    E dequeue() { // Take element out
       // Assert(length() != 0, "Queue is empty");
        E it = listArray[front];
        front = (front+1) % maxSize; // Circular increment
        return it;
    }
    const E& frontValue() const { // Get front value
        //Assert(length() != 0, "Queue is empty");
        return listArray[front];
    }
    virtual int length() const // Return length
    { return ((rear+maxSize) - front + 1) % maxSize; }
};
void BFS(Graph* G, int start, AQueue<int>* Q) {
    int v, w;
    Q->enqueue(start); // Initialize Q
    G->setMark(start, 1);
    while (Q->length() != 0) { // Process all vertices on Q
        v = Q->dequeue();
        cout<<"                    "<<v<<endl;
 // Take appropriate action

               for (w=G->first(v); w<G->n(); w = G->next(v,w))
        {
                        if (G->getMark(w) == 0) {
                G->setMark(w, 1);
                Q->enqueue(w);
                cout<<"<"<<v<<","<<w<<">"<<"               "<<endl;
            }
        
        }
        
    }
}
void graphTraverse(Graph* G) {
    int v;
    for (v=0; v<G->n(); v++)
        G->setMark(v, 0); // Initialize mark bits
    for (v=0; v<G->n(); v++)
        if (G->getMark(v) == 0)
            DFS(G, v);
}
void    menu3l();
void    menu3m();


void menu()
{
    int choice;
    do{
        cout<<"Choose structure:"<<endl<<"1.The adjacency matrix."<<endl<<"2.The adjacency list."<<endl<<"3.Exit."<<endl;
        cin>>choice;
        switch (choice) {
            case 1:
                menu3m();
                break;
                
            case 2:
                menu3l();
                break;
            case 3:
                break;
            default:
                break;
        }
    }while(choice!=3);
}

void menu2(Graph* G, int start, AQueue<int>* Q)
{
    int choice;
    do{
        cout<<"Choose the search way:"<<endl;
        cout<<"1.DFS "<<endl<<"2.BFS"<<endl<<"3.Return"<<endl;
        cin>>choice;
        switch (choice) {
            case 1:
                cout<<"Eage Set"<<"     "<<"Traversal Order"<<endl;
                cout<<"                    ";
                DFS(G,start);
                return;
            case 2:
                cout<<"Eage Set"<<"     "<<"Traversal Order"<<endl;
                //cout<<"                    ";
                BFS(G,start,Q);
                return;
            case 3:
                break;
            default:
                break;
        }
    }while(choice!=3);
        
}
void menu3m()
{
    int choice;
    do{
        cout<<"1.Input graph by defult."<<endl<<"2.Input graph by hand"<<endl<<"3.Return"<<endl;
        cin>>choice;
        switch (choice) {
            case 1:
            {
                AQueue<int> q;
                Graphm mar(30);
                mar.setEdge(1,3,2);
                mar.setEdge(3,1,2);
                mar.setEdge(2,3,2);
                mar.setEdge(3,2,2);
                mar.setEdge(1,5,2);
                mar.setEdge(5,1,2);
                mar.setEdge(5,6,2);
                mar.setEdge(6,5,2);
                mar.setEdge(2,6,2);
                mar.setEdge(6,2,2);
                mar.setEdge(3,4,2);
                mar.setEdge(4,3,2);
                mar.setEdge(3,6,2);
                mar.setEdge(6,3,2);
                mar.setEdge(4,6,2);
                mar.setEdge(6,4,2);
                cout<<"Choose the start point:"<<endl;
                int startPoint;
                cin>>startPoint;
                menu2(&mar,startPoint,&q);
                break;
            }
            case 2:
            {
                AQueue<int> q;
                Graphl mar(30);
                cout<<"How many edge would you like to input?"<<endl;
                int number;
                cin>>number;
                int* start=new int[number];
                int* stop=new int[number];
                cout<<"Input start point:"<<endl;
                for (int i=0; i<number; i++) {
                    cin>>start[i];
                }
                cout<<"Input stop point:"<<endl;
                for (int i=0; i<number; i++) {
                    cin>>stop[i];
                }
                for (int i=0; i<number; i++) {
                    mar.setEdge(start[i], stop[i], 2);
                }
                for (int i=0; i<number; i++) {
                    mar.setEdge(stop[i], start[i], 2);
                }
                cout<<"Choose the start point:"<<endl;
                int startPoint;
                cin>>startPoint;
                menu2(&mar,startPoint,&q);
            }
            case 3:
                break;
                
                
            default:
                cout<<"Not a vailable choice . Choose again."<<endl;
                break;
        }
    }while (choice!=3);
    
    
}
void menu3l()
{
    int choice;
    do{
        cout<<"1.Input graph by defult."<<endl<<"2.Input graph by hand"<<endl<<"3.Return"<<endl;
        cin>>choice;
        switch (choice) {
            case 1:
            {
                AQueue<int> q;
                Graphl mar(30);
                mar.setEdge(1,3,2);
                mar.setEdge(3,1,2);
                mar.setEdge(2,3,2);
                mar.setEdge(3,2,2);
                mar.setEdge(1,5,2);
                mar.setEdge(5,1,2);
                mar.setEdge(5,6,2);
                mar.setEdge(6,5,2);
                mar.setEdge(2,6,2);
                mar.setEdge(6,2,2);
                mar.setEdge(3,4,2);
                mar.setEdge(4,3,2);
                mar.setEdge(3,6,2);
                mar.setEdge(6,3,2);
                mar.setEdge(4,6,2);
                mar.setEdge(6,4,2);
                cout<<"Choose the start point:"<<endl;
                int startPoint;
                cin>>startPoint;
                menu2(&mar,startPoint,&q);
                break;
            }
            case 2:
            {
                AQueue<int> q;
                Graphl mar(30);
                cout<<"How many edge would you like to input?"<<endl;
                int number;
                cin>>number;
                int* start=new int[number];
                int* stop=new int[number];
                cout<<"Input start point:"<<endl;
                for (int i=0; i<number; i++) {
                    cin>>start[i];
                }
                cout<<"Input stop point:"<<endl;
                for (int i=0; i<number; i++) {
                    cin>>stop[i];
                }
                for (int i=0; i<number; i++) {
                    mar.setEdge(start[i], stop[i], 2);
                }
                for (int i=0; i<number; i++) {
                    mar.setEdge(stop[i], start[i], 2);
                }
                cout<<"Choose the start point:"<<endl;
                int startPoint;
                cin>>startPoint;
                menu2(&mar,startPoint,&q);
                break;
            }
            case 3:
                break;
               
                
            default:
                cout<<"Not a vailable choice . Choose again."<<endl;
                break;
        }
    }while (choice!=3);

    
}
int main(int argc, const char * argv[]) {
    cout<<"Welcome to graph travelsals"<<endl;
    menu();
    return 0;
}
