#include<iostream>
using namespace std;
class Command{
    public:
    string name;
    int duration;
    Command(string s,int d):name(s),duration(d){}
    ~Command(){}
};
class CommandNode{
    public:
    Command* cmd;
    CommandNode*next;
    CommandNode(Command*c):cmd(c),next(NULL){}
    ~CommandNode(){}
};
void printQueue(CommandNode* head);
void advanceQueue(CommandNode*& current,int n);
class Commandqueue{
    public:
    CommandNode* head;
    void enqueue(Command* c){
        CommandNode* newNode=new CommandNode(c);
        if(!head){
            head=newNode;
        }
        else{
            CommandNode* temp=head;
            while(temp->next){
                temp=temp->next;
            }
            temp->next=newNode;
        }
        
    }
    void executeNext(CommandNode*&curent){
        cout<<"Excuting "<<curent->cmd->name<<" for "<<curent->cmd->duration<<" seconds"<<endl;
        CommandNode* temp=curent;
        curent=curent->next;
        delete temp;
    }
    void executeAll(){
        printQueue(head);
    }
    void clear(){
        while(head){
            CommandNode*temp=head;
            head=head->next;
            delete temp;
        }
    }
};
class CommandExecuter{
    public:
    void run(Commandqueue& c){
        CommandNode* current=c.head;
        while(current){
            c.executeNext(current);
        }
    }   
     ~CommandExecuter(){}
};
void printQueue(CommandNode* head){
    CommandNode* temp=head;
    while(temp){
        cout<<"Command: "<<temp->cmd->name<<", Duration: "<<temp->cmd->duration<<" seconds"<<endl;
        temp=temp->next;
    }
}
void advanceQueue(CommandNode*& current){
    if(current){
        current=current->next;
    }
}
int main(){
    Commandqueue cq;
    cq.head=NULL;
    Command* c1=new Command("Start motor",100);
    Command* c2=new Command("Open Valve",50);
    Command* c3=new Command("Stop motor",80);
    cq.enqueue(c1);
    cq.enqueue(c2);
    cq.enqueue(c3);
    cout<<"Initial Queue:"<<endl;
    printQueue(cq.head);
    CommandExecuter ce;
    ce.run(cq);
    cq.clear();
    return 0;
}

