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
    Node* cloneGraph(Node* node) {
        if(node == nullptr) return nullptr;
        unordered_map<Node*,Node*> clone;
        clone[node] = new Node(node->val);
        queue<Node*> q;
        q.push(node);
        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            for(auto it : temp->neighbors){
                if(clone.find(it) == clone.end()){
                    clone[it] = new Node(it->val);
                    q.push(it);
                }
                clone[temp]->neighbors.push_back(clone[it]);
            }
        }
        return clone[node];
    }
};