#include<stdlib.h>
#include<iostream>
#include<stdio.h>
#include<string.h>
#define SIZE 26
using namespace std;
struct t_node{
	int vi;
	int ie;//1 if the string ends 0 if not ends
	t_node* chld[SIZE];
};
t_node* l_node;

void insert_string(string str, t_node* r_node){
	int len_ = str.size();
	int i = 0;
	t_node* n_node;
	t_node* c_node = r_node;
	while(i < len_){
		if(c_node->chld[(int)str[i]%SIZE]==NULL){
			n_node = (struct t_node*)malloc(sizeof(struct t_node));
			for(int j = 0; j< SIZE; ++j){
				n_node->chld[j] = NULL;
                n_node->ie = 0;
                n_node->vi = 0;
			}
			if(len_ == 1)
				r_node->vi+=1;
			if(i == len_-1)
				n_node->ie = 1;
			c_node->chld[(int)str[i]%SIZE] = n_node;
            l_node = c_node;
		}
        c_node = c_node->chld[(int)str[i]%SIZE];
        c_node->vi+=1;
		if(i == len_-1)
            c_node->ie=1;
        if(c_node->vi > 1 && c_node->ie == 1){
            cout <<"BAD SET"<< endl <<str <<endl;
            exit(0);
        }
        ++i;
	}

}
int main(){
	int nstr;
	t_node* root = (struct t_node*)malloc(sizeof(struct t_node));
	t_node* n_node;
	string nestr;
	for(int i = 0; i < SIZE; ++i){
		root->ie = 0;
		root->chld[i] = NULL;
	}
	cin >> nstr;
	while(nstr--){
		cin >> nestr;
		insert_string(nestr, root);
	}
	cout << "GOOD SET" << endl;
	return 0;
}
