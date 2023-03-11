/*
Remove leaf nodes in generic Tree
Send Feedback
Remove all leaf nodes from a given generic Tree. Leaf nodes are those nodes, which don't have any children.
Note : Root will also be a leaf node if it doesn't have any child. You don't need to print the tree, just remove all leaf nodes and return the updated root.
Input format :
Line 1 : Elements in level order form separated by space (as per done in class). Order is - `

Root_data, n (No_Of_Child_Of_Root), n children, and so on for every element `
Output Format :
Elements are printed level wise, each level in new line (separated by space)
Sample Input 1 :
10 3 20 30 40 2 40 50 0 0 0 0 
Sample Output 1 : (Level wise, each level in new line)
10
20
*/
// Following is the given Tree node structure.
/**************
class TreeNode {
	TreeNode<T>** children;
	int childCount;

	public:
	T data;

	TreeNode(T data);	// Constructor
	int numChildren();
	void addChild(TreeNode<T>* child);
	TreeNode<T>* getChild(int index);
	void setChild(int index, TreeNode<T>* child);
    void removeChild(int index);
 
};
***************/
#include<vector>
TreeNode<int>* removeLeafNodes(TreeNode<int>* root) {
    if(root==NULL||root->numChildren()==0)
        return NULL;
    
    for(int i =0;i<root->numChildren();i++){
        TreeNode<int>*child = removeLeafNodes(root->getChild(i));
        if(child == NULL)
        {
            root->removeChild(i);
            i--;//reason for this is that since numChildren will decrease so should i such that the shifted child(from i+1) at replaced index (i) is checked 
        }
    }
	
    return root;
}

//method 2:remove all leaf nodes and then recursively iterate
// Following is the given Tree node structure.
/**************
class TreeNode {
	TreeNode<T>** children;
	int childCount;

	public:
	T data;

	TreeNode(T data);	// Constructor
	int numChildren();
	void addChild(TreeNode<T>* child);
	TreeNode<T>* getChild(int index);
	void setChild(int index, TreeNode<T>* child);
    void removeChild(int index);
 
};
***************/
#include<vector>
TreeNode<int>* removeLeafNodes(TreeNode<int>* root) {
    if(root==NULL||root->numChildren()==0)
        return NULL;
    
    vector<int> indexes;
    
    for(int i=0;i<root->numChildren();i++)
    {
        TreeNode<int>*child = root->getChild(i);
        if(child->numChildren()==0){
            indexes.push_back(i);
        }
    }
    
    for(int i= indexes.size()-1;i>=0;i--){
        int j = indexes[i];
        root->removeChild(j);
    }
    
    for(int i =0;i<root->numChildren();i++){
        TreeNode<int>*child = removeLeafNodes(root->getChild(i));
        // if(child == NULL)//will never be reached, since all leaf nodes were removed and neither would size of numChildren would change
        //     root->removeChild(i);
    }
	
    return root;
}