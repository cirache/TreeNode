#include <iostream>
#include <string>

using namespace std;

class EmployeeInfo
{
private:
    string Name = "";
    int ID = 0;
    
public:
    void setName(string n) {Name = n;}
    string getName() { return Name;}
    
    void setID(int I) { ID = I;}
    int getID() {return ID;}
    
    EmployeeInfo(int i, string n) { ID = i; Name = n; }
};

struct TreeNode
{
public:
    EmployeeInfo* data;
    TreeNode* lChild;
    TreeNode* rChild;

    class DuplicateID {public: string message = "This ID already exists.";};
    
    TreeNode(EmployeeInfo* d = NULL, TreeNode* l = NULL, TreeNode* r = NULL)
    {
        data = d;
        lChild = l;
        rChild = r;
    }
    
    void insert(EmployeeInfo* em, TreeNode* &leaf)
    {
        
        if (leaf == NULL)
        {
            leaf = new TreeNode(em);
            return;
        }
        if (em->getID() == leaf->data->getID()) {
            throw DuplicateID();
        }
        else if (em->getID() < leaf->data->getID()) {
            insert(em, leaf->lChild);
        }
        else {
            insert(em, leaf->rChild);
        }
    }
    
    void traverse(TreeNode * r)
    {
        if (r != NULL)
        {
            traverse(r->lChild);
            cout << r->data->getID() << " " << r->data->getName() << endl;
            traverse(r->rChild);
        }
    }
    
    string search(int key, TreeNode *root)
    {
        TreeNode * leaf = root;

        while (leaf != NULL)
        {
            if (leaf->data->getID() == key) {
                cout << "Employee was found: ";
                return leaf->data->getName();
            }
            else if (key < leaf->data->getID()) {
                leaf = leaf->lChild;
            }
            else {
                leaf = leaf->rChild;
            }
        }
        string errorMsg = "ID Was Not Found";
        return errorMsg;
    }

};


