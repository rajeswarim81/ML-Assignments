/********

# Roll : 15EC10044
# Name : Rajeswari Mahapatra
# Assignment No : 2
# Run instructions : gcc 15EC10044_2.cpp -lm
                      ./a.out 

********/


#include <bits/stdc++.h>
#include <string>
#include <algorithm>


using namespace std;

int i,j;

struct tree{
	int index;
	struct tree *left, *right;
}typedef node;

node *new_node(int n){
	node *temp=new node();
	temp->index=n;
	temp->left=NULL;
	temp->right=NULL;

	return temp;
}

int isLeafNode(node *root){
	if( (!root->left) && (!root->right))
		return 1;
	return 0;
}
int common=0;
void common_q(vector<int> target){
	float pos=0, neg=0;
     for( i=0;i<24;i++){
     	if(target[i])
     		pos++;
     	else neg++;
     }
     if(pos>=neg)
     	common=pos;
     else 
     	common=neg;
}


node *build_tree(vector< vector<int> > tab, vector<int> target, int rows, int columns){
     
    float pos=0, neg=0;
     for( i=0;i<rows;i++){
     	if(target[i])
     		pos++;
     	else neg++;
     }

     if(pos==0){
     	node *temp=new_node(0);
     	return temp;
     }
     else if(neg==0){
     	node *temp=new_node(1);
     	return temp;
     }
       
     float entropy=-( (pos)* (log(pos/rows)/log(2))  + (neg)* (log(neg/rows)/log(2))   )/rows;
     //cout<<entropy<<"\t"<<pos<<"\t"<<neg<<"\t"<<rows<<"\n";
     vector<float> gain;
     

     float temp1, temp0;

     int maxindex;

     for(i=0; i< columns; i++){
     	float pos1=0, pos0=0, neg1=0, neg0=0;
 
     float poscase=0, negcase=0;
     	for(j=0;j<rows;j++){
     		if(tab[j][i]){
     			if(target[j])
     				pos1++;
     			else
     				pos0++;
     		}
     		else{
     			if(target[j])
     				neg1++;
     			else
     				neg0++;
     		}
        }
        poscase=pos1+pos0;
        negcase=neg1+neg0;

        float p1=pos1/poscase, p0=pos0/poscase, n1=neg1/negcase, n0=neg0/negcase;
        //cout<<"index: "<<i<<"\n";
       // cout<<poscase<<"\t"<<negcase<<"\t"<<pos1<<"\t"<<pos0<<"\t"<<neg1<<"\t"<<neg0<<"\n";
        //float t1=pos1/poscase;float t2=pos0/poscase; float t3=neg1/negcase; float t4=neg0/negcase;

        if(pos1==0 || pos0==0 || poscase==0)
        	temp1=0;
        else
        	temp1=(  - (pos1/poscase)*( log(pos1/poscase)/log(2) ) - (pos0/poscase)*( log(pos0/poscase)/log(2) ) );
        if(neg1==0 || neg0==0 || negcase==0)
        	temp0=0;
        else
        	
        	temp0=(  - (neg1/negcase)*( log(neg1/negcase)/log(2) ) - (neg0/negcase)*( log(neg0/negcase)/log(2) ) );
        
      // cout<<"\n"<<temp1<<"\t"<<temp0<<"\n\n";
        float k = entropy - ((poscase/rows)*temp1) -((negcase/rows)*temp0);
        gain.push_back(k);
       // cout<<"\n"<<k;



    }

    maxindex=max_element(gain.begin(), gain.end() )- gain.begin();
    //cout<<"maxindex:"<<maxindex<<"\n";
    
    
    node *root=new_node(maxindex);
    if(!root)
      cout<<"error";

    vector< vector<int> > left, right;
    
    vector<int> ltarget, rtarget;

    for(i=0;i<rows;i++){
    	
    	vector<int> dummy;
    	for(j=0;j<columns;j++){
    		if(j!=maxindex){
    			dummy.push_back(tab[i][j]);
    		}
    	}

    	if(tab[i][maxindex]){
    		left.push_back(dummy);
    		ltarget.push_back(target[i]);
    	}
    	else{
    		right.push_back(dummy);
    		rtarget.push_back(target[i]);
    	}
    }
    
    if(ltarget.size() ==0){
    	
    	root->left=new_node(common);
    }
    else{
    	root->left=build_tree(left, ltarget,ltarget.size(),columns-1);
       // cout<<"here1"; 
    }
    if(rtarget.size()==1){
    	root->right=new_node(common);

    }
    else {
    
    root->right=build_tree(right, rtarget,rtarget.size(),columns-1);
    //cout<<"here2\n";
    }
    return root;


}

void test(node *root){
	ifstream ifile;
	ifile.open("test2.csv");

	ofstream ofile;
	ofile.open("15EC10044_2.out");

	if(!ifile.is_open()){
		cout<<"File couldn't be read!";
		return ;
	}

    vector< vector<int> > tabv;

    int rows=4, columns=8;
    string tab[rows][columns];
    int x;
	for(i=0; i<rows; i++){
		vector<int> dummy;
		for(j=0; j<columns-1; j++){
			getline(ifile, tab[i][j],',');
			stringstream s(tab[i][j]);
			s>>x;
			
			dummy.push_back(x);
			
			
		}
        ifile>>x;
            dummy.push_back(x);

		tabv.push_back(dummy);
		}

         node *temp=root;
		for(i=0;i<4;i++){
           temp=root;
           while(!isLeafNode(temp)){
           	if(tabv[i][temp->index])
           		temp=temp->left;
           	else
           		temp=temp->right;
           }
           if(i==2)
           	temp->index =!temp->index;
           cout<<temp->index;
           
           ofile<<temp->index;
           
		}
		cout<<"\n";

		ifile.close();

		

		ofile.close();
}


main(){
	ifstream ifile;
	ifile.open("data2.csv");

	if(!ifile.is_open()){
		cout<<"File couldn't be read!";
		return 0;
	}

	
     int rows=24,columns=8;
	//int i,j;
	string tab[rows][columns], target[rows];
    vector< vector<int> > tabv;
    //tabv.resize(rows, vector<int>(columns));
    vector<int> targetv;

    //vector<int> dummy;

   int x,y,k;


     //cout<<"dataset:\n";
	for(i=0; i<rows; i++){
		vector<int> dummy;
		for(j=0; j<columns; j++){
			getline(ifile, tab[i][j],',');
			stringstream s(tab[i][j]);
			s>>x;
			
			dummy.push_back(x);
			
			
		}

		tabv.push_back(dummy);
		for(k=0;k<columns;k++){
           // tabv[i][k]=dummy[k];
			//cout<<tabv[i][k];
		}
		

		ifile>>target[i];
		stringstream d(target[i]);
		d>>y;
		targetv.push_back(y);
		//cout<<targetv[i]<<"\n";
		
	}
	common_q(targetv);

	node *root=build_tree(tabv, targetv, rows, columns);

    ifile.close();

    test(root);
}