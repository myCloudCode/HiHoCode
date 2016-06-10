#include "stdio.h"

struct Node{
    Node right;
    Node left;
    Node up;
    Node down;
    int x,y;
};

void build(int array[][] int col, int ,row, Node colHead[col];){
    //构建头节点
    Node head = {head,head,head,head,0,0};
    Node* pre = head;
    
    //构建列头节点
    for(int i =  0; i < col; i++){
        colHead[i].right = *pre;
        colHead[i].left = head;
        colHead[i].up = colHead[i];
        colHead[i].down = colHead[i];
        colHead[i].x = i;
        colHead[i].y = 0;
        pre = colHead[i];
    }
    
    //为数据标号
    int index = 0 ;
    int id[][];
    Node node[];
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(array[i][j] == 1){
                index++;
                id[i][j] = index;
                node[index] = {node[index],node[index],
                               node[index],node[index],
                               i,j};
                
            }
            else if(array[i][j] == 0)
                continue;
            else
                return null;
        }
    }
    
    //纵向添加节点
    for(int j = 0; j < col; j++){
        pre = colHead[j];
        
        for(int i = 0; i < row; i++){
            if(array[i][j] == 1){
            node[id[i][j]].up = *pre;
            node[id[i][j]].down = colHead[j];
            pre = node[id[i][j]];
            }
        }
    }
    
    
    //横向添加节点
    for(int i = 0; i < row; i++){
        pre = 0;
        for(int j = 0; j < col; j++){
            if(array[i][j] == 1){
                if(pre == 0){
                    node[id[i][j]].left = node[id[i][j]];
                    node[id[i][j]].right = node[id[i][j]];
                    pre = node[id[i][j]];
                }
                else{
                    node[id[i][j]].left = pre;
                    node[id[i][j]].right = pre.right;
                    pre = node[id[i][j]];
                }
            }
        }
    }
}
//删除节点
void deleteNode(Node col){
    Node pre;
    col.right.left = col.left;
    col.left.right = col.right;
    pre = col.down;
    
    while(pre.down != col){
        Node p2 = pre.right;
        while(p2.right != pre){
            p2.up.down = p2.down;
            p2.down.up = p2.up;
            p2 = p2.right;
        }
        per = pre.down;
    }
}

//恢复节点
void resumeNode(Node col){
    Node pre;
    col.right.left = col;
    col.left.right = col;
    pre = col.down;
    
    while(pre.down != col){
        Node p2 = pre.right;
        while(p2.right != pre){
            p2.up.down = p2;
            p2.down.up = p2;
            p2 = p2.right;
        }
        pre = pre.down;
    }
}

bool Dance(depth,Node colHead[]){
    if(head.right == head){
        return true;
    }
    
    Node p = head.right.down;
    if(p.down == p){
        return false;
    }
    
    deleteNode(colHead[head.right.y]); // 删除当前列
	
	while (p != head.right){ 
		// 枚举选取每一个节点
		ans[ depth ] = p.x;	// 将行压入答案栈中
		
		// 删除p所在行的其他列
		Node p2 = p.right;
		while (p2 != p){
			deleteNode(colHead[p2.y]);
			p2 = p2.right;
		}
		
		// 递归下一步
		if (Dance(depth + 1))
			return true;
		
		// 恢复p2所在行的其他列
		p2 = p.left // 这个地方需要反向来做
		while (p2 != p){
			resume(colHead[p2.y]);
			p2 = p2.left;
		}
		
		// 	枚举下一个节点
		p = p.down;
	}
	resume(colHead[head.right.y]); // 恢复当前列
	return false;
}

void main(){
    int example1[][]={
        {1,1,0,1},
        {0,1,0,1},
        {1,0,0,0},
        {0,1,0,1}
    };
    
    int example2[][]={
        {1,0,0,0},
        {0,1,0,0},
        {1,0,0,0},
        {0,0,1,1}
    };
    
    Node head;
    Node colHead[];
    build(example1,4,4,colHead[4]);
    Dance(1)?printf("Yes"):printf("No");
}