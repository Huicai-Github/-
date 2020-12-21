// 邻接表的存储结构 
typedef struct ArcNode{
    int adjvex;     // 该边的邻接点编号
    struct ArcNode *nextarc;    // 指向下一条边的指针
    int info;   // 该边的相关信息（如权值）
}ArcNode;   //  边节点的类型

typedef struct{
    char data;  // 顶点的其他信息
    ArcNode *firstarc;  // 指向第一个边节点
}VNode;     //边节点的头节点类型

typedef struct{
    VNode adjlist[maxSize];  // 邻接表
    int n,e;    // 顶点数(n)和边数(e)
}AGraph;    // 完整的图的邻接表类型


// 非空线性链表第一个节点list
// 交换p所指节点与其在后继节点中的位置（假设p不指向最后一个节点）
void swap(linklist &list,linklist &p){
    linklist q = list,r = p->next;
    while(q->next!=p)
        q = q->next;
    q->next = r;
    p->next = r->next;
    r->next = p;
}


// 0/1背包问题，背包容量为c，有n个物品，物品i的重量为wi，价值为pi
// 求装入的物品价值最高？

/*
    状态转移方程
    f[i][j] 表示前i件物品恰放入一个容量为j的背包可以获得最大价值。
    f[i][j] = max{ f[i-1][j] , f[i-1][j-w[i]]+p[i] }
*/
    for(int i = 1;i<=n;i++)
        for(int j = c;j>=w[i];j--)
            f[i][j] = max(f[i-1][j],f[i-1][j-w[i]]+p[i]);


// 两艘船载重量分别是C1和C2。有n个集装箱，重量为wi(i=1...n)
// 且所有集装箱总重量不超过C1+C2
// 将所有集装箱全部装入两艘船？

// -->  讨论一艘船的最大装载问题    --> 递归
const int max=12;
int c1,c2,n,boxw[max],weight,best;
// weight -  当前重量
// best - 第一艘船的最大装载

void backtrack(int a){
    // a -  表示当前放了多少个集装箱
    if(a==n){
        if(weight>best)
            best = weight;
        return;
    }
    if(weight+boxw[a]<=c1){
        weight=weight+boxw[a];
        backtrack(a+1);
        weight=weight-boxw[a];
    }
    backtrack(a+1);
}
int main()
{
    int sum = 0;
    cin>>c1>>c2>>n;
    for(int i = 0;i<n;i++){
        cin>>boxw[i];
        sum+=boxw[i];
    }
    best=weight=0;
    backtrack(0);
    if(sum-best<=c2)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
    return 0;
}


// 两个有序单链表的合并排序算法
void MergeList(LNode* &HA,LNode* &HB){  // 此处默认头指针不含数据
    LNode *r = HA,*pa = HA->next,*pb=HB->next;
    while(pa!=NULL&&pd!=NULL){
        if(pa->data <= pb->data){
            r->next = pa;
            r = pa;
            pa = pa->next;
        }else{
            r->next = pb;
            r = pb;
            pb = pb->next;
        }
    }
    if(pa!=NULL)        // 令pb指向不为NULL的链表
        pb = pa;
    while(pb!=NULL){
        r->next = pd;
        r = pd;
        pd = pd->next;
    }
    r->next = NULL;
    free(HB);
}


// 判断二叉排序树是否为二叉搜索树
// --> 中序遍历
int predt = -99999999; // (8*9)
int JudgeBST(BiTree bt){
    int b1,b2;
    if(bt==NULL)
        return 1;
    else{
        b1 = JudgeBST(bt->lchild);
        if(b1==0||predt>=bt->data)  // 不满足条件，返回(0)
            return 0;
        predt = bt->data;
        b2 = JudgeBST(bt->rchild);
        return b2;
    }
}


// 判断字符串是否回文
// 回文 --> 栈  (参考)
#define Max_String_Len 100
bool ispalindrome(char *in_string){
    SqStack<char>s(Max_String_Len);
    char deblankstring[Max_String_Len],c;
    int i = 0;
    //  过滤空格字符
    while(*in_string!='\0'){
        if(*in_string!=' ')
            deblankstring[i++]=*in_string;
        in_string++;
    }
    deblankstring[i] = '\0';
    //  有效字符依次入栈
    i = 0;
    while(deblankstring[i]!='\0')
        s.Push(deblankstring[i++]);
    //  从栈中弹出字符依次比较
    i = 0;
    while(!s.Empty()){
        c = s.Top();
        s.Pop();
        if(c!=deblankstring[i])
            return false;
        i++;
    }
    return true;
}
int main(){
    char instring[Max_String_Len];
    cout<<"input a string:"<<endl;
    cin.get(instring,Max_String_Len);
    // cout<<instring;
    if(ispalindrome(instring))
        cout<<"\""<<instring<<"\""<<" is a palindrome."<<endl;
    else
        cout<<"\""<<instring<<"\""<<" is not a palindrome."<<endl;
    return 0;
}

// 回文 --> by huicai
bool ispalindrome(string str){
    int t = 0;
    for(int i = 0;i<str.length();i++)   // 过滤空格字符
        if(str[i]!=' ')
            str[t++] = str[i];
    for(int i = 0;i<str.length()/2;i++){
        if(str[i]!=str[str.length()-i-1])
            return 0;
    }
    return true;
}
int main(int argc, const char * argv[]) {
    string str;
    cin>>str;
    if(ispalindrome(str))
        cout<<"Nice!!"<<endl;
    else
        cout<<"No!!"<<endl;
    return 0;
}


// 快速排序
int Partition(int A[],int low,int high){
    int pivot = A[low];     // 第一个元素作为枢轴
    while(low<high){        // low,high搜索枢轴的最终位置
        while(low<high && A[high]>=pivot)
            high--;         // 比枢轴小的元素移动到左端
        A[low] = A[high];
        while(low<high && A[low]<=pivot)
            low++;          // 比枢轴大的元素移动到右端
        A[high] = A[low];
    }
    A[low] = pivot;         // 枢轴元素存放到最终位置
    return low;             // 返回存放枢轴的最终位置
}

void QuickSort(ElemType A[],int low,int high){
    if(low<high){
        // Partition() 这就是划分操作，将表A[low...high]划分为满足上述条件的两个子表
        int pivotpos = Partition(A,low,high);   //划分
        QuickSort(A, low, pivotpos-1);        // 依次对两个子表进行递归排序
        QuickSort(A, pivotpos+1, high);
    }
}
