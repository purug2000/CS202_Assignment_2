#include<iostream>
#include<cstdlib>
#include<cstdio>
struct node
{
    int*elem;
    int size;
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
    void append(int*k,int size){
        node* el;
        el=(node*)malloc(sizeof(node));
        el->size=size;
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
            if(t->size==1){
                k=(t->elem)[0];
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
        int * el,s;
        el=f->elem;
        s=f->size;
        t=f->next;
        t=f->prev;
        if(f&&flag){
            rem_node(f);
            int l=0;
            for(int i=0;i<s;i++)
            {
                append(el+i,1);
                l=solve();
                if(l)
                    return 1;
                else
                    pop();
            }
            /*if(!l){
                add_node(t,NULL);
                return l;
            }*/
        }     

    }

    void print()
    {
        node* t=head;
        int j=0;
        while(t){
            int s=t->size;
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

using namespace std;
int main(int argc,char**argv){
    /*ifstream f:
    string line;
    f.open(argv[1]);
    while(f){
        getline(f,line);
        line
    }*/
    dll y(720);
    int **x;
    
    x=(int**)malloc(11*sizeof(int**));
    for(int j=0;j<11;j++){    
        x[j]=(int*)malloc(11*sizeof(int*));
        for (int i=0;i<11;i++)
        {
            x[j][i]=i*11+j+1;
        }
        if (j==4){
            x[j][2]=12;
        }
        y.append(x[j],11);
        
    }
    x[10][0]=-10;
    y.print();
    printf("Hurray!!!\n");
    node k= *tty;

   /* y.add_node(&k,tty->next->next);
    y.print();
    printf("Hurray!!!\n");
    y.pop();
    y.print();
    printf("Hurray!!!\n");
    y.append(x[10],11);
    y.print();
    y.solve();*/
    y.solve();

    y.print();

    return 0;
}