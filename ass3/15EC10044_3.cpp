/********

# Roll : 15EC10044
# Name : Rajeswari Mahapatra
# Assignment No : 3
# Run instructions : g++ 15EC10044_3.cpp && ./a.out

********/

#include <bits/stdc++.h>

using namespace std;
int i,j;


void bayes(vector< vector<float> > tab, vector<float> target){
	float pc[2]={0,0};          // to store P(Ci)
	float pc0[2][8], pc1[2][8]; //to store conditional probabilities

    int count=0;
    int rows=20, columns=8;
    
    for(i=0;i<rows;i++){
    	for(j=0;j<columns;j++){

    	}
    }

	for(i=0;i<rows;i++){        //calculate P(Ci)
		if(target[i])
			count++;
	}

	pc[1]=count;
	pc[0]=rows-count;

	//cout<<pc[1]<<"\n"<<pc[0]<<"\n";

	for(i=0;i<2;i++){         //initialise the numerators of the likelihood
		for(j=0;j<columns;j++){
			pc0[i][j]=1;
			pc1[i][j]=1;
		}
	}

	for(i=0;i<rows;i++){
		for(j=0;j<columns;j++){
			if(target[i])
				pc1[(int)tab[i][j]][j]++;
			else
				pc0[(int)tab[i][j]][j]++;
			
		}
	}

	for(i=0;i<2;i++){
		for(j=0;j<8;j++){
			pc0[i][j]/=(20-count+2);
			pc1[i][j]/=(count+2);
		}
	}
 
	ifstream iifile;
	iifile.open("test3.csv");

	ofstream ofile;
	ofile.open("15EC10044_3.out");

	if(!iifile.is_open()){
		cout<<"File couldn't be read!";
		return ;
	}

	 vector< vector<int> > tabvtest;
    
    
    rows=4, columns=8;
    string tabtest[rows][columns];
    int x;

   // cout<<"\nTest cases\n";
	for(i=0; i<rows; i++){
		vector<int> dummytest;
		for(j=0; j<columns-1; j++){
			getline(iifile, tabtest[i][j],',');
			stringstream s(tabtest[i][j]);
			s>>x;
			

			dummytest.push_back(x);

			//cout<<x;
		}
		iifile>>x;
			dummytest.push_back(x);
			//cout<<x;
        
		tabvtest.push_back(dummytest);
		//cout<<"\n";
		}
		//cout<<"done\n";

        int y;
		float  c1test=1, c0test=1;

      //  cout<<"output\n";
		for(i=0;i<rows;i++){
			for(j=0;j<columns;j++){
				y=tabvtest[i][j];
                
                c1test*= pc1[y][j];
                c0test*= pc0[y][j];

			}

			c1test*=pc[1];
			c0test*=pc[0];

			if(c1test > c0test){
				//cout<<1<<"\t";
				ofile<<1<<"\t";
			}
			else {
				//cout<<0<<"\t";
				ofile<<0<<"\t";
			}
		}

		cout<<"\n";

    iifile.close();
	ofile.close();



}

main(){
	ifstream ifile;
	ifile.open("data3.csv");

	if(!ifile.is_open()){
		cout<<"File couldn't be read!";
		return 0;
	}

	const int rows=20, columns=8;

	string tab[rows][columns], target[rows];
    vector< vector<float> > tabv;
    vector<float> targetv; 

    int x,y,k;

	for(i=0; i<rows; i++){
		vector<float> dummy;
		for(j=0; j<columns; j++){
			getline(ifile, tab[i][j],',');
			stringstream s(tab[i][j]);
			s>>x;
			dummy.push_back(x);
		//cout<<x;
		
		}
        tabv.push_back(dummy);

		ifile>>target[i];
		stringstream d(target[i]);
		d>>y;
		targetv.push_back(y);
		//cout<<y<<"\n";
		
	}

	bayes(tabv, targetv);

	ifile.close();
}