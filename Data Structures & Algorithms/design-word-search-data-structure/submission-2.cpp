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
class WordDictionary {
public:
     TreeNode* root;
    WordDictionary() {
        root  =new TreeNode();
        root->isEnd =false;
    }
    
    void addWord(string word) {
        TreeNode* node=root;

        for(auto &it: word){
            if( node->children[it-'a']==nullptr) node->children[it-'a']=new TreeNode();

            node= node->children[it-'a'];
        }

        node->isEnd =true;
    }
    
    bool search(string word) {
        int n =word.size();
        TreeNode* node= root;
        return helper( 0, node, word);
    }

    bool helper( int idx , TreeNode* node ,string word){

        if( idx==word.size())return node->isEnd;
        int key = word[idx]-'a';
        if( word[idx]!='.'){
            if( node->children[key]==nullptr)return false;
            node =node->children[key];
           return helper( idx+1 , node ,word);
        }else{
            for( int i=0;i<26;i++){
                if( node->children[i]!=nullptr){
                if( helper( idx+1 , node->children[i] , word))return true;
                }
            }
        }
        return false;
    }
};
