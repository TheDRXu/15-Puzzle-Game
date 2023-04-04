#include <stdio.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>
#include <cmath>
#include <utility>
#include <stack>
#include <cassert>
#include<string>
using namespace std;

int arr[4][4] = {0};
int goal[4][4] = {{0,1,2,3},{4,5,6,7},{8,9,10,11},{12,13,14,15}}; 
int gol_id = 0; 
int atime = 0;
string direction[] = {"up","down", "left", "right"};   

typedef struct node{
    string str;
    int f,g,h;
    int time;
    string action;
    int id;
    int parent_id;
}node;

node hisArray[1000000];

class Compare{
    public:
        bool operator()(const node& a, const node& b){
            if( a.f == b.f ){
                return a.time > b.time;
            }
            else{
                return a.f > b.f;
            }
        }  
};

int solvable(string str){
	int i , j , ans , place , count=0 ;
	for (i = 0 ; i < 16 ; i++){
    	if (str[i] == '0'){
    		place = i / 4;
    		continue;
		}
    	for (j = i ; j < 16 ; j++ ){
    		if (str[j] == '0'){
	    		continue;
			}
    		if (str[i]>str[j]){
    			count++;
			}	
		}
	}
	ans = (count + place) % 2 ;
	assert( ans >= 0);
	return ans;
	
}

bool isGoal(){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(arr[i][j]!=goal[i][j]) return false;
        }
    }
    return true;
}

int manhattan_distance() {
    int distance = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            int value = arr[i][j];
            if (value != 0) {
                int target_row = (value) / 4;
                int target_col = (value) % 4;
                distance += abs(i - target_row) + abs(j - target_col);
            }
        }
    }
    return distance;
}

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

pair<int, int> findZero(){
    for(int i = 0;i < 4;i++){
        for(int j = 0;j < 4;j++){
            if( arr[i][j] == 0 ){
                return pair<int,int>(i, j);
            }
        }
    }
    while(1);
    return pair<int,int>(-1, -1);
}

void initialize (node &a,string str, int f, int g, int h, int time, string action, int id, int parent_id ){
    a.str = str;
    a.g = g;
    a.f = f;
    a.h = h;
    a.time = time;
    a.action = action;
    a.id = id;
    a.parent_id = parent_id;
}

string toStr(){
    string s;
    for(int i = 0;i < 4;i++){
        for(int j =0 ;j < 4;j++){
            if( arr[i][j] >= 10 ){
                if( arr[i][j] == 10 ) s += "A";
                else if( arr[i][j] == 11 ) s += "B";
                else if( arr[i][j] == 12 ) s += "C";
                else if( arr[i][j] == 13 ) s += "D";
                else if( arr[i][j] == 14 ) s += "E";
                else if( arr[i][j] == 15 ) s += "F";
            }
            else{
                s += to_string(arr[i][j]);
            }
        }
    }
    return s;
}


priority_queue<node, vector<node>, Compare> pq;
void movement(node temp, int x, int y){
    node next;
    if(x-1>=0){
        swap(&arr[x][y],&arr[x-1][y]);
        initialize(next,toStr(),temp.g+1+manhattan_distance(),temp.g+1,manhattan_distance(),atime++,direction[0],gol_id++,temp.id);
        pq.push(next);
        hisArray[next.id] = next;
        swap(&arr[x][y],&arr[x-1][y]);
    }
    if(x+1<4){
        swap(&arr[x][y],&arr[x+1][y]);
        initialize(next,toStr(),temp.g+1+manhattan_distance(),temp.g+1,manhattan_distance(),atime++,direction[1],gol_id++,temp.id);
        pq.push(next);
        hisArray[next.id] = next;
        swap(&arr[x][y],&arr[x+1][y]);
    }
    if(y-1>=0){
        swap(&arr[x][y],&arr[x][y-1]);
        initialize(next,toStr(),temp.g+1+manhattan_distance(),temp.g+1,manhattan_distance(),atime++,direction[2],gol_id++,temp.id);
        pq.push(next);
        hisArray[next.id] = next;
        swap(&arr[x][y],&arr[x][y-1]);
    }
    if(y+1<4){
        swap(&arr[x][y],&arr[x][y+1]);
        initialize(next,toStr(),temp.g+1+manhattan_distance(),temp.g+1,manhattan_distance(),atime++,direction[3],gol_id++,temp.id);
        pq.push(next);
        hisArray[next.id] = next;
        swap(&arr[x][y],&arr[x][y+1]);
    }
}


void print(){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cout << arr[i][j] << " ";
        }
        cout<<endl;
    }
}

void toArray(string str){
    int pos = 0;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(str[pos]>='A') arr[i][j] = str[pos++] -'7';
            else            arr[i][j] = str[pos++] - '0';
        }
    }
}

int main(){
    string str;
    cin >> str;
    toArray(str);
    if(solvable(str)!=0){
        cout << "No solution!!" << endl;
    }
    else if(isGoal()){
        cout << "It is the goal state." << endl;
    }
    else{
        node test;
        initialize(test,str,0,0,0,atime++,"",gol_id,gol_id);
        gol_id++;
        pq.push(test);
        node finalGoal;
        while(!pq.empty()){
            node current;
            current = pq.top();
            pq.pop();
            toArray(current.str);
            // print();
            if(isGoal()){
                finalGoal = current;
                break;
            }
            pair<int,int> indexZero = findZero();
            int x = indexZero.first;
            int y = indexZero.second;
            movement(current,x,y);
        }
        stack<string>stk;
        while(finalGoal.id != finalGoal.parent_id){
            stk.push(finalGoal.action);
            finalGoal = hisArray[finalGoal.parent_id];
        }
        while(!stk.empty()){
            cout << "move 0 to " << stk.top() << endl;
            stk.pop();
        }
    }
    return 0;
}