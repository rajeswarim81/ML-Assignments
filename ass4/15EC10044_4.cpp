/********

# Roll : 15EC10044
# Name : Rajeswari Mahapatra
# Assignment No : 4
# Run instructions : g++ 15EC10044_4.cpp -lm && ./a.out

********/

#include <bits/stdc++.h>

using namespace std;
int i,j,k;


bool compdist(const vector<float>& v1, const vector<float>& v2){
	return v1[1]<v2[1];
}

void KNNClassifier(vector< vector<float> > tab, vector<float> target){
	ifstream ifile;
	ifile.open("test4.csv");

	ofstream ofile;
	ofile.open("15EC10044_4.out");

	if(!ifile.is_open()){
		cout<<"File couldn't be read!";
		return ;
	}

	int rows=4,columns=8;
	vector< vector<float> > tabvtest;
    string tabtest[rows][columns];
    int x;

	for(i=0; i<rows; i++){
		vector<float> dummytest;
		for(j=0; j<columns-1; j++){
			getline(ifile, tabtest[i][j],',');
			stringstream s(tabtest[i][j]);
			s>>x;
			dummytest.push_back(x);
			//cout<<x;
		}
		ifile>>x;
		dummytest.push_back(x);
		//cout<<x;
        tabvtest.push_back(dummytest);
		//cout<<"\n";
	}

	

	float distance;
	int testrows=4, testcolumns=8, trainrows=20, traincolumns=8;
	int count;

	for(i=0;i<testrows;i++){
        vector< vector<float> > kdistance;
        distance=0,count=0;
		
        for(j=0;j<trainrows;j++){
             
             vector<float> dummy;
             for(k=0;k<traincolumns;k++)
             	distance+= ((tabvtest[i][k]-tab[j][k]) * (tabvtest[i][k]-tab[j][k]));
             
             //cout<<sqrt(distance)<<"\n";

             dummy.push_back(j);
             dummy.push_back(sqrt(distance));
             //cout<<dummy[1]<<"\n";

             kdistance.push_back(dummy);
             }
             
            // cout<<kdistance[j][0]<<"\t"<<kdistance[j][1]<<"\n";

            // for(j=0;j<trainrows;j++)
              // cout<<kdistance[j][0]<<"\t"<<kdistance[j][1]<<"\n";
             //cout<<"sorted\n";
             sort(kdistance.begin(), kdistance.end(), compdist);
             //for(j=0;j<trainrows;j++)
               //cout<<kdistance[j][0]<<"\t"<<kdistance[j][1]<<"\n";
             
             for(k=0;k<5;k++){
             	if(target[(int)kdistance[k][0]])
             		count++;
             }
             //cout<<count<<"\n";
             

             if(count>=3){
             	ofile<<1<<"\t";
             	//cout<<1<<"\t";
             }
             else{
             	ofile<<0<<"\t";
             	//cout<<0<<"\t";
             }

        

	}

    ifile.close();
	ofile.close();


}


main(){
	ifstream ifile;
	ifile.open("data4.csv");

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

	KNNClassifier(tabv, targetv);

	ifile.close();
}