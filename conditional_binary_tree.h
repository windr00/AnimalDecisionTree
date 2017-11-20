//
// Created by 冉惟之 on 20/11/2017.
//

#ifndef ANIMALDECISIONTREE_CONDITIONAL_BINARY_TREE_H
#define ANIMALDECISIONTREE_CONDITIONAL_BINARY_TREE_H

//this binary tree accesses its child according to yes or no
//use a condition matcher to decide the yes path or no path
class conditional_binary_tree {
private:

    //the child node on the yes path
    //nullable
    conditional_binary_tree *_yes_child;

    //this bool indicates whether the yes child needs to be automatically recycled by deconstructing
    bool _is_yes_child_created = false;

    //the child node on the no path
    //nullable
    conditional_binary_tree *_no_child;

    //this bool indicates whether the no child needs to be automatically recycled by deconstructing
    bool _is_no_child_created = false;

    //the condition prompt message
    const char *_condition;
public:

    //constructor for this tree node
    conditional_binary_tree();

    //constructor to directly set children nodes and condition
    conditional_binary_tree(const char *condition, conditional_binary_tree *yes_child,
                            conditional_binary_tree *no_child);

    //set the condition for this node and returns this node itself
    conditional_binary_tree *set_condition(const char *condition);

    //create a child on the yes path use the given condition for this node, and return this node itself
    conditional_binary_tree *create_yes_child(const char *condition);

    //create a child on the no path use the given condition for this node, and return this node itself
    conditional_binary_tree *create_no_child(const char *condition);

    //get the yes child node
    conditional_binary_tree *get_yes_child();

    //get the no child node
    conditional_binary_tree *get_no_child();

    //try to ask the user to match condition, returns the child based on yes or no
    //if both yes and no children are no, then output the condition as the result
    void try_match_condition();

    //deconstruct the node and its children node
    ~conditional_binary_tree();

};


#endif //ANIMALDECISIONTREE_CONDITIONAL_BINARY_TREE_H
