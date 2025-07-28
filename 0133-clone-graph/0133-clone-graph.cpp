/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map <Node*, Node*> visited;

    Node* cloneGraph(Node* node) {
       if(!node) return nullptr;

       //if already cloned, return the clone 
       if(visited.find(node) != visited.end()) {
        return visited[node];
       }

       //clone the node
       Node* clone = new Node(node->val);
       visited[node] = clone; //Mark this node as visited by storing in the hash map

       //Iterate over all the neighbors of the original node 
       for(Node* neighbor : node->neighbors) {
        // Recursively clone the neighbors and add them to the current clone's neighbor list
        clone->neighbors.push_back(cloneGraph(neighbor));
       }
       //Return the fully cloned node 
       return clone;
    }

    // //BFS Approach:
    //  Node* cloneGraph(Node* node) {
    //     if (!node) return nullptr;

    //     unordered_map<Node*, Node*> visited;
    //     queue<Node*> q;

    //     // Clone the root node
    //     Node* clone = new Node(node->val);
    //     visited[node] = clone;
    //     q.push(node);

    //     while (!q.empty()) {
    //         Node* curr = q.front(); q.pop();

    //         for (Node* neighbor : curr->neighbors) {
    //             if (visited.find(neighbor) == visited.end()) {
    //                 visited[neighbor] = new Node(neighbor->val);
    //                 q.push(neighbor);
    //             }
    //             visited[curr]->neighbors.push_back(visited[neighbor]);
    //         }
    //     }

    //     return clone;
    // }
};