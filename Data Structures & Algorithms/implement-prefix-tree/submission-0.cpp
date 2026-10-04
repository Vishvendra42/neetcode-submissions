class TreeNode{
    public:
    bool isEnd;
    TreeNode* children[26];

    TreeNode(){
        for( auto &it:children){
            it=nullptr;
        }
        isEnd =false;
    }

};

class PrefixTree {
public:

    TreeNode* root;
    PrefixTree() {
        root = new TreeNode();
    }
    
    void insert(string word) {
        TreeNode* node = root; 
        for(auto  &it:word){
           if( node->children[it-'a'] ==nullptr){
              node->children[it-'a'] = new TreeNode();
           }

           node= node->children[it-'a'];
        }
        node->isEnd = true;

    }

    
    bool search(string word) {
        TreeNode* node=root;

        for( auto &it:word){
            if( node->children[it-'a'] ==nullptr) return false;
            node= node->children[it-'a'];
        }

        return node->isEnd ;
    }
    
    bool startsWith(string prefix) {
         TreeNode* node=root;

        for( auto &it:prefix){
            if( node->children[it-'a'] ==nullptr) return false;
            node= node->children[it-'a'];
        }

        return true;
    }
};
