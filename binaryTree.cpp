#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class node{
    
    public:
    int data;
    node* left;
    node* right;
    
    node(int data){
        this -> data = data;
        this -> left = NULL;
        this -> right = NULL;
    }
};

node* buildTree(node* root){
    //create node
    int data;
    cout << "Enter data: " << endl;
    cin >> data;
    if(data == -1){
        return NULL;
    }
    
    root = new node(data);
    
    //build left three
    cout << "Enter data to insert in left of: " << data << endl;
    root -> left = buildTree(root -> left);
    
    //build right tree
    cout << "Enter data to insert in right of: " << data << endl;
    root -> right = buildTree(root -> right);
    return root;
}


void levelOrderTraversal(node* root){
    
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
       node* temp = q.front();
       q.pop();
       if(temp == NULL){
           cout << endl;
           if(!q.empty()){
               q.push(NULL);
           }
       }else{
           cout << temp -> data << " ";
           if(temp -> left){
            q.push(temp -> left);
        }
        if(temp -> right){
            q.push(temp -> right);
        }
       }
    }
}

void reverseLevelOrderTraversal(node* root){
    if(root == nullptr){
        cout << "tree has no node: " << endl;
        return;
    }
    
    queue<node*> q;
    stack<node*> s;
    
    q.push(root);
    q.push(nullptr);
    // s.push(root);
    // s.push(nullptr);
    
    while(!q.empty()){
        node* temp = q.front();
        s.push(temp);
        q.pop();
        if(temp == nullptr){
            if(!q.empty()){
                q.push(nullptr);
            }
        }else{
            if(temp -> right){
                q.push(temp -> right);
            }
            if(temp -> left){
                q.push(temp -> left);
            }
        }
    }
    
    while(!s.empty()){
        if(s.top() != nullptr){
            cout << s.top() -> data << " ";
            s.pop();
        }else{
            cout << endl;
            s.pop();
        }
    }
    
}


void inOrderTraversal(node* root){
    
    node* temp = root;
    
    //base case
    if(temp == NULL) return;
    
    inOrderTraversal(temp -> left);
    cout << temp -> data << " ";
    inOrderTraversal(temp -> right);
}

void preOrderTraversal(node* root){
    
    node* temp = root;
    
    //base case
    if(temp == NULL) return;
    
    cout << temp -> data << " ";
    preOrderTraversal(temp -> left);
    preOrderTraversal(temp -> right);
}

void postOrderTraversal(node* root){
    
    node* temp = root;
    
    //base case 
    if(temp == NULL) return;
    
    postOrderTraversal(temp -> left);
    postOrderTraversal(temp -> right);
    cout << temp -> data << " ";
}


node* buildFromLevelOrderTraversal(node* root){
    
    queue<node* > q;
    cout << "Enter data for root: " << endl;
    int data;
    cin >> data;
    root = new node(data);
    q.push(root);
    
    while(!q.empty()){
        node* temp = q.front();
        q.pop();
        
        cout << "Enter data to insert in left of: " << temp -> data << endl;
        int leftData;
        cin >> leftData;
        if(leftData != -1){
            temp -> left = new node(leftData);
            q.push(temp -> left);
        }
        
        cout << "Enter data to insert in right of: " << temp -> data << endl;
        int rightData;
        cin >> rightData;
        
        if(rightData != -1){
            temp -> right = new node(rightData);
            q.push(temp -> right);
        }
    }
    
    return root;
}

int height(node* root){
    
    if(root == NULL) return 0;
    
    int leftHeight = height(root -> left);
    int rightHeight = height(root -> right);
    
    return max(leftHeight, rightHeight) + 1;
}

int width(node* root){
    queue<pair<node*, long long>> q;
    
    q.push({root, 0});
    
    int maxWidth = 0;
    
    while(!q.empty()){
        int level = q.size();
        long long first_index = q.front().second;
        long long last_index = q.back().second;
        
        maxWidth = max(maxWidth, int (last_index - first_index + 1));
        
        for(int i = 0; i<level; i++){
            auto [temp, index] = q.front();
            
             q.pop();
            
            if(temp -> left)
                q.push({temp -> left, 2 * (index - first_index)});
                
            if(temp -> right)
                q.push({temp -> right, 2 * (index - first_index) + 1});
        }
    }
    
    return maxWidth;
}


int diameter(node* root, int &maxDiameter) {
    // Base case
    if (root == NULL) return 0;

    int leftHeight = diameter(root->left, maxDiameter);
    int rightHeight = diameter(root->right, maxDiameter);

    int currDiameter = leftHeight + rightHeight;

    maxDiameter = max(maxDiameter, currDiameter);

    return max(leftHeight, rightHeight) + 1;
}


int getDiameter(node* root){
    int maxDiameter = 0;
    diameter(root, maxDiameter);
    return maxDiameter;
}

bool isBalanced(node* root, int& height) {
    if (root == NULL) {
        height = 0;
        return true;
    }

    int leftHeight = 0, rightHeight = 0;

    bool leftBalanced = isBalanced(root->left, leftHeight);
    bool rightBalanced = isBalanced(root->right, rightHeight);

    height = max(leftHeight, rightHeight) + 1;

    if (abs(leftHeight - rightHeight) > 1) {
        return false;
    }

    return leftBalanced && rightBalanced;
}

bool isTreeBalanced(node* root) {
    int height = 0;
    return isBalanced(root, height);
}



int main() {
    
    node* root = NULL;
    
    root = buildTree(root);
    
    // cout << "level order traversal: " << endl;
    // levelOrderTraversal(root);
    
    cout << "reverse level oreder travesal: " << endl;
    reverseLevelOrderTraversal(root);
    cout << endl;
    
    // cout << "inorder traversal: " << endl;
    // inOrderTraversal(root);
    // cout << endl;
    
    // cout << "preorder traversal: " << endl;
    // preOrderTraversal(root);
    // cout << endl;
    
    // cout << "postorder traversal: " << endl;
    // postOrderTraversal(root);
    // cout << endl;
    
    // cout <<"height: " << height(root) << endl;
    
    // cout <<"width: " <<  width(root) << endl;
    // cout <<"diameter: " << getDiameter(root) << endl;
    
    
    // root = buildFromLevelOrderTraversal(root);
    
    // cout << "level order traversal: " << endl;
    // levelOrderTraversal(root);
    
    cout << "balanced: " << isTreeBalanced(root) << endl;
    
 
    //5 7 1 -1 -1 8 -1 -1 3 -1 2 -1 -1 
    
    return 0;
}
