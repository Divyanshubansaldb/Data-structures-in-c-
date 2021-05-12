vector<int> tree(pow(2,18),-1);

void inorder(int node)
{
    int left=2*node+1;
    int right=2*node+2;
    if(tree[left]!=-1)
        inorder(left);
    cout<<tree[node]<<" ";
    if(tree[right]!=-1)
        inorder(right);
}

void preorder(int node)
{
    int left=2*node+1;
    int right=2*node+2;
    cout<<tree[node]<<" ";
    if(tree[left]!=-1)
        preorder(left);
    if(tree[right]!=-1)
        preorder(right);
}

void postorder(int node)
{
    int left=2*node+1;
    int right=2*node+2;
    if(tree[left]!=-1)
        postorder(left);
    if(tree[right]!=-1)
        postorder(right);
    cout<<tree[node]<<" ";
}




//////// without recursion

void inorder(int node)
{
    stack<pair<int,int>> s;
    s.push(mk(node,0));
    while(!s.empty())
    {
        pair<int,int> v=s.top();
        s.pop();
        int left=2*(v.first)+1;
        int right=2*(v.first)+2;
        if(v.second==0)
        {
            s.push(mk(v.first,1));
            if(tree[left]!=-1)
            {
                s.push(mk(left,0));
            }
        }
        else
        {
            cout<<tree[v.first]<<" ";
            if(tree[right]!=-1)
                    s.push(mk(right,0));
        }
    }
}

void preorder(int node)
{
    stack<pair<int,int>> s;
    s.push(mk(node,0));
    while(!s.empty())
    {
        pair<int,int> v=s.top();
        s.pop();
        int left=2*(v.first)+1;
        int right=2*(v.first)+2;
        if(v.second==0)
        {
            s.push(mk(v.first,1));
            cout<<tree[v.first]<<" ";
            if(tree[left]!=-1)
            {
                s.push(mk(left,0));
            }
        }
        else
        {
            if(tree[right]!=-1)
                    s.push(mk(right,0));
        }
    }
}

void postorder(int node)
{
    stack<pair<int,int>> s;
    s.push(mk(node,0));
    while(!s.empty())
    {
        pair<int,int> v=s.top();
        s.pop();
        int left=2*(v.first)+1;
        int right=2*(v.first)+2;
        if(v.second==0)
        {
            s.push(mk(v.first,1));
            if(tree[left]!=-1)
            {
                s.push(mk(left,0));
            }
        }
        else if(v.second==1)
        {
            s.push(mk(v.first,2));
            if(tree[right]!=-1)
                    s.push(mk(right,0));
        }
        else
        {
            cout<<tree[v.first]<<" ";
        }
        
    }
}