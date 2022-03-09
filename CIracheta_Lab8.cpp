#include "Lab8.h"

int main() {
    TreeNode *employee = NULL;
   
    bool exit = false;
    
    //iteration for entering employee info
    while(exit != true) {
        
        int ID = 0;
        cout << "Enter ID: ";
        cin >> ID;
        
        string name;
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);
        
        //initializes the data for the TreeNode
        EmployeeInfo *emData = new EmployeeInfo(ID, name);
        
        //try catch block incase ID is duplicate
        try {
        employee->insert(emData, employee); //inserts TreeNode
        }
        catch(TreeNode::DuplicateID dupe) { cout << dupe.message;}
        cout << "\n\n";
        
        int choice = 0;
        cout << "Would you like to enter another employee?\n 1) Yes\n 2) No\n >> ";
        cin >> choice;
       
        if(choice == 2) { exit = true; cout << "\n\n"; }
        else if(choice == 1) { cout << "\n"; }
        else { cout << "Error input invalid\n\n"; return 0;}
        
    }
    //displays all IDs and emplyees
    //employee->traverse(employee);
    
    cout << "\n\nEnter ID to search for: ";
    int i = 0;
    cin >> i;
    //displays name of employee if found in search
    //else displays error messege
    cout << employee->search(i,employee) << "\n\n";
    
    return 0;
}
