#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<vector>
#include<sstream>
#include<fstream>

using namespace std;
struct node
{
    std::vector<int>  elem;
    node*prev;
    node*next;
};
node *tty;
class dll
{
    private:
    node*head,*tail;
    int*numstack;
    int size;

    void num_stack_refresh(){
        for(int i=0;i<size;i++){
            numstack[i]=0;
        }
        return;
    }
    int mod(int k){
        if (k>0)
        return k;
        else
        return -1*k;
    }

    public:
    dll(int s)
    {
        size=s;
        head=NULL;
        tail=NULL;
        numstack=(int*)malloc(sizeof(int)*size);
        num_stack_refresh();
    }
    void append(vector<int> k){
        node* el;
        el=(node*)malloc(sizeof(node));
        el->elem=k;
        if (head==NULL)
        {
            head=el;
            tail=el;
            el->next=NULL;
            el->prev=NULL;
        }
        else{
        tail->next=el;
        el->prev=tail;
        tail=el;
        tail->next=NULL;
        }
        
    }
    void pop(){
        node*k;
        k=tail->prev;
        free(tail);
        tail=k;
        tail->next=NULL;
    }
    void rem_node(node*x){
        node*prev,*next;
        prev=x->prev;
        next=x->next;
        if(prev){        
            prev->next=next;
        }
        else{
            head=next;
        }
        if(next){
        next->prev=prev;
        }
        else
            tail=prev;
    }
    void add_node(node*x,node*prev){
        node*k;
        if(prev){
        k=prev->next;
        x->prev=prev;
        x->next=k;
        prev->next=x;
        if(k){
            k->prev=x;
        }
        else
        {
            tail=x;
        }
        }
        else{
            head->prev=x;
            x->prev=NULL;
            x->next=head;
            head=x;
        }

    }
    int solve(){
        node*t=head,*f;
        int flag2=1,flag=1;
        int k;
        printf("FIne");
        while(t){
            if((t->elem).size()==1){
                k=(t->elem).at(0);
                if(numstack[mod(k)-1]==-1*(k)/mod(k)){
                flag=0;
                num_stack_refresh(); 
                return 0;
                }
                else
                numstack[mod(k)-1]=k/mod(k);
                t=t->next;
                continue;
            }
            if(flag2){
                f=t;
                flag2=0;
            }
            t=t->next;    
        }
        printf("FIne");
        if(flag&&flag2){
            return 1;
        }
        num_stack_refresh();
        int s;
        vector<int> el;
        el=f->elem;
        s=(f->elem).size();
        t=f->next;
        t=f->prev;
        if(f&&flag){
            rem_node(f);
            int l=0;
            for(int i=0;i<s;i++)
            {
                vector<int> j{el[i]} ;
                append(j);
                l=solve();
                if(l)
                    return 1;
                else
                    pop();
            }
            if(!l){
                //add_node(t,NULL);
                return l;
            }
        }     

    }

    void print()
    {
        node* t=head;
        int j=0;
        while(t){
            int s=(t->elem).size();
            printf("%d %d [",j+1,s);
            for(int i=0;i<s;i++)
                printf(" %d",(t->elem)[i]);
            printf(" ]\n");
            t=t->next;
            
            j++;
        }
        tty=tail->prev;
    }

};
vector<int> create(std::string line)
{
    int d;
    vector<int> k;
    std::istringstream iss(line);
    iss>>d;
    while(d!=0)
    {
        k.push_back(d);
        iss>>d;
    }
    return k;

}
    



int main(int argc,char**argv){
    /*ifstream f:
    string line;
    f.open(argv[1]);
    while(f){
        getline(f,line);
        line
    }*/
    /*std::ifstream f;
    
    f.open(argv[1]);
    
    std::string line;
    std::getline(f,line);
    
    std::istringstream iss(line);
    
    char c;
    std::string s;
    int ln;
    int p;
    vector<int> arr;
    
    iss>> c >> s >> p >> ln;
    
    dll y(p);
    for(int i=0;i<ln;i++)
    {
        std::getline(f,line);
        if(line.length()==0)
        {
            i--;
            continue;
        }
        arr=create(line);
        y.append(arr);
    }*/
    dll x(5);
    vector<int> t{1,2,3,4,5};
    x.append(t);
   /* y.add_node(&k,tty->next->next);
    y.print();
    printf("Hurray!!!\n");
    y.pop();
    y.print();
    printf("Hurray!!!\n");
    y.append(x[10],11);
    y.print();
    y.solve();*/
    x.solve();

    x.print();

    return 0;
}
