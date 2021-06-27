#include<bits/stdc++.h>
using namespace std;

struct node
{
	char value;
	node* left, *right;
    node(char c){
        value = c;
        left = right = NULL;
    }
};

node* newnode(char c){
    node* temp = new node(c);
    return temp;
}

bool check(char c){
    if(c=='/') return 1;
    else if(c=='*') return 1;
    else if(c=='+') return 1;
    else if(c=='-') return 1;
    else if(c=='^') return 1;
    else return 0;
}

node* constructTree(string postfix)
{
    string str(postfix);
    node* root = NULL;
    stack<node*> st;

    for(int i=0;i<str.size();i++){
        if(check(str[i])){
            node* temp = newnode(str[i]);
            temp->right = st.top();
            st.pop();
            temp->left = st.top();
            st.pop();

            root = temp;
            st.push(temp);
        }
        else{
            st.push(newnode(str[i]));
        }
    }

    return root;
}

void inorder(node* root){
    if(root==NULL) return;
    inorder(root->left);
    cout<<root->value;
    inorder(root->right);
}

void postorder(node* root){
    if(root==NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->value;
}

int main()
{
    string s;
    cin>>s;
    node* root = constructTree(s);
    inorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;
}