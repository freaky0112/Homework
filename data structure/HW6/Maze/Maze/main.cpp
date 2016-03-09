//
//  main.cpp
//  Maze
//
//  Created by JU YE on 16/3/8.
//  Copyright © 2016年 Freaky. All rights reserved.
//

#include <iostream>
using namespace std;
struct Node{
    int key=999;
    bool visited=true;//没有访问过
    int *neighbor;
    int length=0;
    int weight=0;
};

int R,C;
bool* visited;
Node* queue;
int head,length,tail;

void print_list(){
    for (int i=0; i<length; i++) {
        int n=(head+i)%(R*C);
        
        cout<<queue[n].key<<" ";
    }
    cout<<endl;
}


void enqueue(Node* node){
    tail=(tail+1)%(R*C);
    queue[tail]=*node;
    //cout<<queue[head].length<<endl;
    length++;
}

Node* dequeue(){
    if (length>0) {
        Node* node=&queue[head];
        head=(head+1)%(R*C);
        length--;
        return node;
    }
    return NULL;
}

int read_data(){
    cin>>R>>C;
    int start = 0,end = 0;
    bool maze[R][C];
    visited=new bool[R*C];
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            char x;
            cin>>x;
            visited[i]=true;
            switch (x) {
                case '.':
                    maze[i][j]=true;
                    break;
                case 'X':
                    maze[i][j]=false;
                    break;
                case 'S':
                    maze[i][j]=true;
                    start=i*C+j;
                    break;
                case 'E':
                    maze[i][j]=true;
                    end=i*C+j;
                    break;
                default:
                    break;
            }
        }
    }
    //初始化矩阵
    Node* matrix=new Node[R*C];
    for (int i=0;i<R; i++) {
        for (int j=0; j<C; j++) {
            if (maze[i][j]) {
                int current=i*C+j;
                Node* node=&matrix[current];
                node->key=current;
                node->neighbor=new int[4];
                //如果不在矩阵最上行
                int neighbor=(i-1)*C+j;
                if (i>0&&maze[i-1][j]) {
                    node->neighbor[node->length]=neighbor;
                    node->length++;
                }
                //如果不在矩阵最下行
                neighbor=(i+1)*C+j;
                if (i<R-1&&maze[i+1][j]) {
                    node->neighbor[node->length]=neighbor;
                    node->length++;
                }
                //如果不在矩阵最左列
                neighbor=i*C+j-1;
                if (j>0&&maze[i][j-1]) {
                    node->neighbor[node->length]=neighbor;
                    node->length++;
                }
                //如果不在矩阵最右列
                neighbor=i*C+j+1;
                if (j<C-1&&maze[i][j+1]) {
                    node->neighbor[node->length]=neighbor;
                    node->length++;
                }
            }
            //cout<<matrix[0].neighbor[0]<<endl;
        }
    }
    head=0;
    tail=length-1;
    //delete maze;
    queue=new Node[R*C];
    Node *start_node=&matrix[start];
    start_node->visited=false;
    enqueue(start_node);
    
    Node* node=dequeue();
    while (node->key!=end) {
        for (int i=0; i<node->length; i++) {
            Node* neighbor=&matrix[node->neighbor[i]];
            if (neighbor->visited) {
                neighbor->visited=false;
                neighbor->weight=node->weight+1;
                enqueue(neighbor);
                //print_list();
            }
        }
        //print_list();

        node=dequeue();
    }
    delete[] matrix;
    return node->weight;
}

int main(int argc, const char * argv[]) {
    int T;
    int sum=0;
    cin>>T;
    for (; T>0; T--) {
        sum+=read_data();
    }
    cout<<sum;
    return 0;
}

