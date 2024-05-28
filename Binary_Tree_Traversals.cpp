#include<bits/stdc++.h>
using namespace std;

//Structure of the Tree Node
class Node{

    public: 
        int data;
        Node* left;
        Node* right;

        //Constructors
        Node()
        {
            data = 0;
            left = right = NULL;
        }

        Node(int val)
        {
            data = val;
            left = right = NULL;
        }
};

//Print Function
void print_vec(vector<int> arr)
{
    for(auto it : arr) cout<<it<<" ";
}

//Recursive Solution
void preorder(Node* node)
{
    if(node == NULL)
        return;
    
    cout<<(node->data)<<" ";
    preorder(node->left);
    preorder(node->right);
}

void inorder(Node* node)
{
    if(node == NULL)
        return;
    
    inorder(node->left);
    cout<<(node->data)<<" ";
    inorder(node->right);
}

void postorder(Node* node)
{
    if(node == NULL)
        return;
    
    postorder(node->left);
    postorder(node->right);
    cout<<(node->data)<<" ";
}


//Iterative Solutions
void preorder_i(Node* node)
{
    if(node==NULL) return;
    stack<Node*> st;
    vector<int> store;
    st.push(node);
    while(!st.empty())
    {
        Node* temp = st.top();
        store.push_back(temp->data);
        st.pop();

        if(temp->right != NULL) st.push(temp->right);
        if(temp->left != NULL) st.push(temp->left);
    }

    print_vec(store);
}


void inorder_i(Node* node)
{
    stack<Node*> st;
    if(node == NULL)    return;
    Node* temp = node;
    while(1)
    {
        if(temp != NULL)
        {
            st.push(temp);
            temp = temp->left;
        }
        else
        {
            if(st.empty()) break;
            temp = st.top();
            cout<<temp->data<<" ";
            st.pop();
            temp = temp->right;
        }
    }
    cout<<endl;
}

void postorder_i(Node* node)
{
    if(node == NULL)    return;
    vector<int> ans;
    stack<Node*> st;
    st.push(node);

    while(!st.empty())
    {
        Node* temp = st.top();
        st.pop();
        ans.push_back(temp->data);
        if(temp->left != NULL) st.push(temp->left);
        if(temp->right != NULL) st.push(temp->right);
    }

    reverse(ans.begin(),ans.end());

    for(auto it : ans) cout<<it<<" ";
}

//Print all the DFS Traversals in single code using single stack
void all_order(Node* node)
{
    if(node == NULL) return;

    stack<pair<Node*,int>> st;
    vector<int> inorder;
    vector<int> preorder;
    vector<int> postorder;
 
    st.push({node,1});

    while(!st.empty())
    {
        auto temp = st.top();
        st.pop();
        if(temp.second == 1) {
            preorder.push_back(temp.first->data); 
            temp.second++;
            st.push(temp);
            if(temp.first->left != NULL) st.push({temp.first->left,1});
        }
        else if(temp.second == 2)
        {
            inorder.push_back(temp.first->data);
            temp.second++;
            st.push(temp);
            if(temp.first->right != NULL) st.push({temp.first->right,1});
        }
        else if(temp.second == 3){
            postorder.push_back(temp.first->data);
        }
    }

    //print to STDOUT
    cout<<"preorder : ";
    print_vec(preorder);
    cout<<endl;
     cout<<"inorder  : ";
    print_vec(inorder);
    cout<<endl;
     cout<<"postorder: ";
    print_vec(postorder);

}

//Levelwise traversal or BFS
void bfs(Node* root)
{
    //Will use one queue data structure
    if(root == NULL) return;
    queue<Node*> q;
    q.push(root);
    cout<<endl;
    while(!q.empty()){
        int size = q.size();
        for(int i =0 ; i < size;i++)
        {
            Node* temp = q.front();
            q.pop();
            cout<<temp->data<<" ";
            if(temp->left != NULL) q.push(temp->left);
            if(temp->right!= NULL) q.push(temp->right);
        }
        cout<<endl;
    }
}


int main()
{
    //Sample Tree Structure

    //        5
    //       / \
    //      4   3
    //     /\   /\
    //    6  7 8  9

    // Created the Sample Tree using dynamic memory allocation
    Node* root = new Node(5);
    root->left = new Node(4);
    root->right = new Node(3);
    root->left->left = new Node(6);
    root->left->right = new Node(7);
    root->right->left = new Node(8);
    root->right->right = new Node(9);

    //Program to select which traversal you want to use
    int input=-1;
    cout<<endl<<"Enter :   "<<endl;
    do
    {
        if(input!=8)cout<<endl;
        cout<<"-------------------------------------"<<endl;
        cout<<"1 --> inorder recursive"<<endl;
        cout<<"2 --> inorder iterative"<<endl;
        cout<<"3 --> preorder recursive"<<endl;
        cout<<"4 --> preorder iterative"<<endl;
        cout<<"5 --> postorder recursive"<<endl;
        cout<<"6 --> postorder iterative"<<endl;
        cout<<"7 --> ALL in one"<<endl;          //THALA FOR A REASON
        cout<<"8 --> BFS (LEVEL wise) "<<endl;
        cout<<"0 --> EXIT"<<endl;
        cout<<"-------------------------------------"<<endl;

        cin>>input;
        if(input == 1)  inorder(root);
        else if(input == 2)  inorder_i(root);
        else if(input == 3)  preorder(root);
        else if(input == 4)  preorder_i(root);
        else if(input == 5)  postorder(root);
        else if(input == 6)  postorder_i(root);
        else if(input == 7)  all_order(root);
        else if(input == 8)  bfs(root);
        else if(input == 0);
        else{
            cout<<"Invalid Input"<<endl;
        }
        
    }while(input != 0);

    return 0;
}