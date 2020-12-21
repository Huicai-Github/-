// 1 数据结构，抽象数据类型
    数据        data
    数据项      data item
    数据元素    data element
    数据对象    data object
    数据类型    data type

// 2.1 线性结构的相关内容。
    逻辑结构
        线性结构：线性表，栈，队列，数组
        非线性结构：集合，树，图
// 2.2 通用线性表和特殊线性表（栈、队列、广义表等）的逻辑结构以及物理结构；
    栈
        逻辑结构
            只能在一段进行插入或删除操作的线性表
        物理结构
            顺序存储结构--顺序栈（sequential stack）// /sɪ'kwenʃ(ə)l/
        /*
                typedef struct{
                    ElemType data[MaxSize]; // 存放栈中的数据元素
                    int top;                // 栈顶指针，存放下标
                }SqStack;                   // 顺序栈类型
            链式存储结构--链栈（linked stack）
                typedef struct linknode{
                    ElemType data;             // 数据域
                    struct linknode *next;     // 指针域
                }LinkStNode;                   // 链栈结点类型
        */
    队列
        逻辑结构
            先进先出
        物理结构
            顺序存储结构--顺序队列（sequential queue）
            /* 
                typedef struct{
                    ElemType data[MaxSize];
                    int front,rear;
                }SqQueue;
            */
            链式存储结构--链队（linked queue）
            /*
                typedef struct qnode{
                    ElemType data;          // 存放元素
                    struct qnode *next;     // 下一个结点指针
                }DataNode;                  // 链队数据结点的类型
                typedef struct{             // 链队头节点类型
                    DataNode *front;
                    DataNode *rear;
                }LinkQuNode;
            */
    广义表
        逻辑结构
            A(·(a,·(a,b),·(·(a,b),c)))
        物理结构--链式存储结构      tag    sublist/data    link
        /* 共用体：一个带有多成员的共用体，但是任何时候只能有一个成员带有值。*/         
            typedef struct lnode{
                int tag;                    // 结点类型标示
                union{                      // 共用体
                    ElemType data;          // 原子值
                    struct lnode *sublist;  // 指向子表的指针
                }val;
                struct lnode *link;         // 指向下一个元素
            }GLNode;                        // 广义表的节点类型
// 2.3 线性结构上的查找、插入和删除等算法；
    顺序表
        查找
            int findElem(Sqlist L,int e){
                for(int i = 0;i<L.length;i++){
                    if(L.data==e)
                        return i+1;     // 下标为i的元素值等于e，返回其次序i+1
                }
                return -1;
            }
        插入--在第i个位置插入e
            bool ListInsert(Sqlist &L,int i,ElemType e){
                // 判断i的范围是否有效
                if(i<1||i>L.length+1)
                    return false;
                // 当前存储范围是否满
                if(L.length>=Maxsize)
                    return false;
                // 将其他元素后移
                for(int j = L.length;j>=1;j--)
                    L.data[i-1]=e;
                // 在第i个位置插入e
                L.data[i-1] = e;
                // 线性表长度+1
                L.length++
                return true;
            }
        删除--删除表中第i个位置的元素，并将其引回
            bool ListDelete(Sqlist &L,int i,ElemType &e){
                // 判断i的范围是否有效
                // 将被删除的元素赋值给e
                // 将第i个位置后的元素前移
                // 线性表长度减1
            }
    单链表

    双链表
    栈 
    队列 

// 2.4 线性结构的典型应用方法；
    栈
        简单表达式求值
        求解迷宫问题
    队列
        求解报数问题
        求解迷宫问题
    
// 2.5 广义表的定义，操作和典型应用；
        tag域    sublist/data    link
        标志字段    子表/原子       同一层下一个元素对应节点(兄弟节点)的地址，当没有兄弟节点时，link域为NULL

// 2.6 多项式的表示和实现方法。

// 3.1 树和二叉树的定义和结构特性，完全二叉树的性质；
// 3.2 树和二叉树的存储实现方法，遍历树和二叉树的算法；
    二叉树的存储实现
    typedef struct BiTNode{
        ElemType data       // 数据域
        struct BiTNode *lchild,*rchild; //左右孩子指针
    }BiTNode，*BiTree；
    树的存储实现
        双亲表示法
            #define MAX_TREE_SIZE 100   // 树中最多的节点数
            typedef struct{             // 树的节点定义
                ElemType data;          // 数据元素
                int parent;             // 双亲位置域
            }PTNode;
            typedef struct{             // 数的类型定义
                PTNode nodes[MAX_TREE_SIZE];    // 双亲表示
                int n;                  // 节点数
            }PTree;
        孩子表示法--每个节点的孩子节点都用单链表链接起来形成一个线性结构
        孩子兄弟表示法(二叉树表示法)--以二叉链表作为树的存储结构
            typedef struct CSNode{
                ElemType data;          // 数据域
                struct CSNode *firstchild,*nextsibling; //第一个孩子和右兄弟
            }CSNode,*CSTree;
            
    遍历树和二叉树


// 3.3 树，森林和二叉树的转换；
// 3.4 扩充二叉树和Huffman树的定义与实现，Huffman编解码及其应用；
    带权路径长度:WPL=wi·li
// 4.1 图的定义和两种存储结构（邻接矩阵、邻接表）
// 4.2 图的深度优先搜索和广度优先搜索以及相关的生成树
// 4.3 图的最小生成树的算法（普里姆算法和克鲁斯卡尔算法）
// 4.4 图的最短路径算法（迪杰克斯拉算法）
// 4.5 AOV有向无环网的拓扑排序及其AOE网络的关键路径求解算法；
    有向无环图(directed acycline graph,DAG)
    在一个有向图中找一个拓扑序列的过程称为拓扑排序(topological sort)
    用顶点表示活动，用有向边表示活动之间有限关系的有向图成为顶点表示活动的网(activity on vertex newtork,AOV网)
    图中入度为0的顶点表示工程的开始事件，出度为0的顶点表示工程结束事件(activity on edge newtork,AOE网)
    AOE网中，从源点到汇点的所有路径中具有最大路径长度的路径成为关键路径(critical path)
    关键路径上的活动称为关键活动(key active)    
    拓扑排序方法:
        (1).从有向图中选择一个没有前驱(即入度为0)的顶点并且输入它
        (2).从图中删去改定点，并且删去从该定点发出的全部有向边
        (3).重复上述两步，直到剩余的图中不再存在没有前驱的顶点为止
    ve(k)--决定了所有从vk开始的活动能够开工的最早时间
    e(i)--活动的最早开始时间--活动弧的起点所表示的事件的最早发生时间
    vl(k)--指在不推迟整个工程完成的前提下，该事件最迟必须发生的时间
    l(k)--活动的最迟开始时间--活动弧的终点所表示事件的最迟发生时间和该活动所需时间之差

    e(i)=ve(k)
    l(i)=vl(j)-Wight(vk,vj)

    d(i)=l(i)-e(i),表示在不增加完成整个工程所需总时间的情况下，活动ai可以拖延的时间，
        如果一个活动的时间余量为0，则说明该活动必须要如期完成，d(i)=0即l(i)=e(i)的活动ai是关键活动
    -->关键活动组成的路径为关键路径

// 5.1 静态查找表的查找方法
// 5.2 平均查找长度的计算方法
// 5.3 二叉排序树的构造、查找以及平衡化的方法；
// 5.4 多路平衡搜索树；
// 5.5 哈希查找的概念；

// 6.1 排序的定义和各种排序方法的思想及其特点
// 6.2 掌握快速排序、希尔排序、冒泡排序、归并排序、堆排序等经典排序算法
    插入排序
        直接插入排序 :每次从无序序列中取一个元素，然后在有序序列中遍历，寻找合适的位置将该元素插入有序序列中
        折半插入排序 :进行类似于二分法定界的方式，不断缩小其范围，最后对数据移动，对待排序算法进行插入 
        希尔排序    :先将带排序表分割成若干如L[i,i+d,i+2d,...,i+kd]的特殊字表，对每个子表分别进行直接插入排序。缩小增量d，重复上述过程，知道d=1为止
    交换排序
        冒泡排序    :从后往前(或从前往后)两两比较相邻元素的值，若为逆序(即A[i-1]>A[i]),则交换他们，知道序列比较完
        快速排序    :首先提取一个元素为枢纽，然后以此枢轴为界分为两个部分，左面小于枢轴值，右面大于该枢轴值，递归
    选择排序
        简单选择排序 :将表分为两部分，有序部分和无序部分，每次从无序部分中选取最小的元素，然后将其放入有序部分中
        堆排序      :构造-对第[n/2]个节点为根的子树筛选...
    归并排序和基数排序
        2路归并排序  :二合一
        基数排序     :
            最高位优先(MSD)法:按关键字位权重递减依次逐层划分成若干更小的子序列，最后将所有子序列依次连接成一个有序序列
            最低位优先(LSD)法:按关键字位权重递增依次进行排序，最后形成一个有序序列
// 6.3 进行时空复杂性和稳定性的分析；
                        最好           平均         最坏      空间复杂度      是否稳定
        直接插入排序      O(n)         O(n^2)       O(n^2)      O(1)          稳定
        折半插入排序      O(n)         O(n^2)       O(n^2)      O(1)          稳定      比较次数O(nlog_2(n))  
        希尔排序                      O(n^2)                   O(1)          不稳定
        冒泡排序         O(n)         O(n^2)       O(n^2)      O(1)          稳定
        快速排序         O(nlog_2(n)) O(nlog_2(n)) O(n^2)      O(log_2(n))   不稳定
        简单选择排序                   O(n^2)                   O(1)          不稳定
        堆排序                        O(nlog_2(n))             O(1)          不稳定     
        2路归并排序                    O(nlog_2(n))             O(n)          稳定
        基数排序                       O(d(n+r))                O(r)          稳定

// 7 能够灵活运用常见的数据结构解决实际问题；




/****************************************************************************/
1.线性结构上的查找、插入和删除等算法
// 2.广义表的定义，操作和典型应用 2019
// 3.多项式的表示和实现方法 2018
4.树和二叉树的存储实现方法，遍历树和二叉树的算法
5.扩充二叉树和Huffman树的定义与实现
6.图的最小生成树的算法（普里姆算法和克鲁斯卡尔算法）
7.图的最短路径算法（迪杰克斯拉算法）
8.AOV有向无环网的拓扑排序及其AOE网络的关键路径求解算法
9.快速排序、希尔排序、冒泡排序、归并排序、堆排序等经典排序算法
// 10.背包
/****************************************************************************/

2016.
    三元组-稀疏矩阵的转置算法
    哈夫曼树的生成和编码的实现算法
    双向循环链表的排序
2017.
    任意一种排序算法
    Dijkstra算法
2018.
    多项式相加算法
2019.
    层次遍历算法
    图的最小生成树算法
    图的最短路径算法
    广义表查找算法
2020.
    层次遍历算法
    证明无向图各点之间可达算法
    图的最短路径算法
    排序算法
    归并排序
    背包





/****************************************************************************/
