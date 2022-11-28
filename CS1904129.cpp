#include<iostream>
#include<cstdlib>
/*
 Auther : Rishabh Tripathi
 Rollno-1904129
 Branch-Computer science and engineering
 group-3
*/

//Here we try to make a class node which we will use in making our FamilyTree class
class node{
private:
    int data;
    int no_of_child;
    class node*brother;
    class node*child;
friend class FamilyTree;
public:
    node(){ brother=NULL;child=NULL;no_of_child=0;}     //constractor of node class
};
//here we make Family tree class which used to make family of tree;
class FamilyTree{
private:
    class node*root;
    int count;
    node*check(int x,node*pointer){             //it is check function which we used in search function we used " double recursion method for getting node pointer of respective child parents"
        node*temp=pointer;
        if(temp==NULL) return NULL;             //base case of recursion
        else if((temp->data)==x) return temp;
        else{
                node*abc=check(x,temp->brother);    //single recursion
                if(abc==NULL) {
                    abc=check(x,temp->child);       //double recursion if required;
                    count++;
                }
                return abc;
        }
    }
public:
    FamilyTree(int);                //constructer
    void insertChild(int,int);      //insertChild function
    node* search(int);              //search function
    void relationship(int,int);     //relationship function
    ~FamilyTree() {delete root;}    //here we define destructor
};

FamilyTree::FamilyTree(int a){
    count=1;
    root=new node;
    root->data=a;
}
void FamilyTree::insertChild(int x,int y){           //here x is parents of y this function used  for inserting the children
    node*rt=search(x);
    if(rt==NULL) printf("no such parents exit--%d for this pair (%d %d)",x,x,y);
    else {
        if((rt->no_of_child)==0){
            node*temp=new node;
            temp->data=y;
            rt->child=temp;
            ++(rt->no_of_child);
        }
        else{
        node*temp=new node;
        temp->data=y;
        temp->brother=rt->child;
        rt->child=temp;
        ++(rt->no_of_child);
    }}
}
node* FamilyTree::search(int x){
        return check(x,root);
}

void FamilyTree::relationship(int person1,int person2){     //it is relationship fuction which tell us relationship between two persons
    int count1,count2;
    count=1;
    node* rt=search(person1);
    count1=count;
    count=1;
    node*rta=search(person2);
    count2=count;
    if(rt==NULL) {
        printf("\nno relationship between (%d %d)",person1,person2);
        return;}
    else if(rta==NULL) {
        printf("\nno relationship between (%d %d)",person1,person2);
        return;}
    else{
    switch(abs(count1-count2)){                 //here we use switch function for because we have lot of cases;
        case (0):
        printf("\nrelationship between (%d %d) is Brother",person1,person2);
        return;
        case(1):
        printf("\nrelationship between (%d %d) is parents",person1,person2);
        return;
        case(2):
        printf("\nrelationship between (%d %d) is Grand parents",person1,person2);
        return;
        case(3):
        printf("\nrelationship between (%d %d) is G-grand parents",person1,person2);
        return;
        case(4):
        printf("\nrelationship between (%d %d) is G-g-grand parents",person1,person2);
        return;
        case(5):
        printf("\nrelationship between (%d %d) is G-g-g-grand parents",person1,person2);
        return;
        case(8):
        printf("\nrelationship between (%d %d) is Grand parents",person1,person2);
        return;
        case(7):
        printf("\nrelationship between (%d %d) is parents",person1,person2);
        return;
    }}
}

int main(){
    class FamilyTree rt(4);
    rt.insertChild(4,5);
    rt.insertChild(4,7);
    rt.insertChild(4,8);
    rt.insertChild(4,9);
    rt.insertChild(5,6);
    rt.insertChild(5,0);
    rt.insertChild(99,10);
    rt.insertChild(6,19);
    rt.insertChild(19,11);
    rt.insertChild(11,12);
    rt.insertChild(7,112);
    rt.insertChild(7,113);
    printf("\nnow we show relationship");
    rt.relationship(7,5);
    rt.relationship(4,7);
    rt.relationship(4,0);
    rt.relationship(4,19);
    rt.relationship(4,11);
    rt.relationship(4,12);
    rt.relationship(4,113);
    rt.relationship(7,113);
    rt.relationship(99,100);
    return 0;


}
