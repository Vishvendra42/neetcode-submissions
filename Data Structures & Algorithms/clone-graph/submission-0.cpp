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
    void dfs(Node* node, Node* copy, unordered_map<int, Node*>& mp) {
        copy->val = node->val;

        for (auto& it : node->neighbors) {
            if (mp.find(it->val) == mp.end()) {
                Node* newnode = new Node();
                copy->neighbors.push_back(newnode);
                mp[it->val] = newnode;
                dfs(it, newnode, mp);
            } else {
                Node* equivalentNode = mp[it->val];

                copy->neighbors.push_back(equivalentNode);
            }
        }
        return;
    }
    Node* cloneGraph(Node* node) {
        if (node == NULL) return NULL;
        unordered_map<int, Node*> mp;

        vector<int> vis(100, 0);

        Node* clone = new Node();
        mp[node->val] = clone;
        dfs(node, clone, mp);
        return clone;
    }
};
