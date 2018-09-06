/*
15EC10044
Rajeswari Mahapatra
Assignment_1

file name to be entered by user as input 
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
    
    const int columns=8;
    const int rows=20;

	ifstream ifile;
	string filename;
	getline(cin,filename);
	ifile.open(filename.c_str());

	if(!ifile.is_open()){
		cout<<"File couldn't be read!";
		return 0;
	}

	int i,j; 
	string tab[rows][columns],target[rows];

	for(i=0; i<rows; i++){
		for(j=0; j<columns; j++){
			getline(ifile, tab[i][j],',');
			//cout<<tab[i][j];
		}
		ifile>>target[i];
		//cout<<target[i]<<"\n";
	}
	//cout<<"\n";

	string hyp[columns];
	for(j=0;j<columns;j++)
		hyp[j]="-1";
    
    for(i=0;i<rows;i++){

    	if(target[i]=="1"){
    		for(j=0;j<columns;j++){
    			if(hyp[j]=="-1")
    				hyp[j]=tab[i][j];
    			else{
    				if(hyp[j] != tab[i][j])
    					hyp[j]="2";
    			}
    		}
    	}
    }

    int count=8;
    for(i=0;i<columns;i++)
    	if(hyp[i]=="2")
          count--;

    cout<<count<<",";
    for(i=0;i<columns;i++){
    	if(hyp[i]!="2"){
    		if(hyp[i]=="1")
    			cout<<i+1<<",";
    		else
    			cout<<-1*(i+1)<<",";
    	}
    }

    cout<<"\n";

	ifile.close();
	return 0;

}