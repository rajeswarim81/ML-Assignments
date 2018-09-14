/********

# Roll : 15EC10044
# Name : Rajeswari Mahapatra
# Assignment No : 4
# Run instructions : g++ 15EC10044_4.cpp && ./a.out

********/

#include <bits/stdc++.h>

using namespace std;
int i,j,k;


bool compdist(const vector<float>& v1, const vector<float>& v2){
	return v1[1]<v2[1];
}

void KNNClassifier(vector< vector<float> > tab, vector<float> target){
	ifstream ifile;               //read the test file
	ifile.open("test4.csv");

	ofstream ofile;               //ouput file
	ofile.open("15EC10044_4.out");

	if(!ifile.is_open()){
		cout<<"File couldn't be read!";
		return ;
	}

	int rows=26,columns=4;
	vector< vector<float> > tabvtest;
    string tabtest[rows][columns];
    float x;

	for(i=0; i<rows; i++){           //read the test file onto a 2d vector
		vector<float> dummytest;
		for(j=0; j<columns-1; j++){
			getline(ifile, tabtest[i][j],',');
			stringstream s(tabtest[i][j]);
			s>>x;
			dummytest.push_back(x);
			//cout<<x<<"\t";
		}
		ifile>>x;
		dummytest.push_back(x);
		//cout<<x<<"\n";
        tabvtest.push_back(dummytest);
	}

	

	float distance;
	int testrows=26, testcolumns=4, trainrows=74, traincolumns=4;
	int count;

	for(i=0;i<testrows;i++){                  //read each row of the test file
        vector< vector<float> > kdistance;
        distance=0,count=0;
		
        for(j=0;j<trainrows;j++){             //compute distances
             distance=0;
             vector<float> dummy;
             for(k=0;k<traincolumns;k++)
             	distance+= ((tabvtest[i][k]-tab[j][k]) * (tabvtest[i][k]-tab[j][k]));
             dummy.push_back(j);
             dummy.push_back(sqrt(distance));
             kdistance.push_back(dummy);
             }
            /* if(i==0)
             for(j=0;j<trainrows;j++)
             	cout<<kdistance[j][0]<<"\t"<<kdistance[j][1]<<"\n";
*/
            sort(kdistance.begin(), kdistance.end(), compdist);  //sort the distances
             
           /*  if(i==2)
             for(j=0;j<trainrows;j++)
             	cout<<kdistance[j][0]<<"\t"<<kdistance[j][1]<<"\n";
           */  
             for(k=0;k<5;k++){                       //choose majority of the nearest 5 neighbours
             	if(target[(int)kdistance[k][0]])
             		count++;
             }
            
             if(count>=3)  {        //write to the output file
             	ofile<<1<<"\t";
             	//cout<<1;
             }
             	
             else{
               //cout<<0;
             	ofile<<0<<"\t";
             }
             	
    }

    ifile.close();
	ofile.close();


}


main(){
	ifstream ifile;
	ifile.open("data4.csv"); //read the input file

	if(!ifile.is_open()){
		cout<<"File couldn't be read!";
		return 0;
	}

	const int rows=74, columns=4;

	string tab[rows][columns], target[rows];
    vector< vector<float> > tabv;
    vector<float> targetv; 

    float x,y,k;

	for(i=0; i<rows; i++){        //read the input file onto a string array and then convert to a float 2d vector
		vector<float> dummy;
		for(j=0; j<columns; j++){
			getline(ifile, tab[i][j],',');
			stringstream s(tab[i][j]);
			s>>x;
			dummy.push_back(x);
			//cout<<x<<"\t";
		
		}
        tabv.push_back(dummy);

		ifile>>target[i];
		stringstream d(target[i]);
		d>>y;
		targetv.push_back(y);
		//cout<<y<<"\n";
		
	}

	KNNClassifier(tabv, targetv);  //call the knn function

	ifile.close();  //close the file
}