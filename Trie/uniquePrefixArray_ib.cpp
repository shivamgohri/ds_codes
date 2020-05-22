
class Node{
    
    public:
  
        char data;
        unordered_map<char, Node*> children;
        bool terminal;
        int count;
        
        Node(char d){
            data = d;
            terminal = false;
            count = 0;
        }
    
};

class Trie{
    
    public:
    
        Node* root;
        
        Trie(){
            root = new Node('\0');
        }
        
        void insert(string s){
            
            Node* temp = root;
            for(int i=0; i<s.length(); i++){
                
                char ch = s[i];
                temp->count++;
                
                if( temp->children.count(ch) ){
                    temp = temp->children[ch];
                }
                else{
                    Node* n = new Node(ch);
                    temp->children[ch] = n;
                    temp = temp->children[ch];
                }
            }
            temp->terminal = true;
        }
    
};


vector<string> Solution::prefix(vector<string> &A) {
    
    
    vector<string> res;
    
    Trie t;
    
    for(int i=0; i<A.size(); i++){
        t.insert(A[i]);
    }
    
    for(int i=0; i<A.size(); i++){
        
        Node* temp = t.root;
        string output = "";
        
        for(int j=0; j<A[i].length(); j++){
            
            if( temp->count==1 && temp->children.size()==1 ){
                res.push_back(output);
                break;
            }
            else{
                output += A[i][j];
                temp = temp->children[A[i][j]];
            }
        }
        if(temp->terminal==true){
            res.push_back(output);
        }
    }
    
    return res;
}

