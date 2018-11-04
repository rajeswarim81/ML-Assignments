#15EC10044
#Rajeswari Mahapatra
#Assignmen 7
# python 15EC10044_7.py



import numpy as np 


#read the input file
with open('data7.csv', 'r') as f:
    train_data = []
    train_label=[]
    for line in f:
            line=line.rstrip()
            words = line.split(',')
            train_data.append(words[0:8])
            

#store it as an numpy array
x=np.asarray(train_data, dtype=np.float64)

#no of iterationsand k as specified in the question
epoch=10
k=2

rows=x.shape[0]
columns=x.shape[1]

#initialising random cluter centers
cmean1=x[np.random.randint(low=0, high=rows),:]
cmean2=x[np.random.randint(low=0, high=rows),:]

#cmean1=x[0,:]
#cmean2=x[1,:]

#function to compute euclidean distance
def euclideanDistance(instance1, instance2):
	distance = 0
	length=len(instance1)
	#print(instance2[0].dtype)
	for x in range(length):
		distance += pow((instance1[x] - instance2[x]), 2)
	return np.sqrt(distance)

#array to store membership values, initialised to zero
membership=np.zeros(rows)

for i in range(epoch):
    for j in range(rows):
    	d1=euclideanDistance(cmean1,x[j])        #calculate distances
    	d2=euclideanDistance(cmean2,x[j])
    	membership[j]=1*(d1 >= d2)               #deciding memberships
    
    count=0
    sum1=np.zeros(columns)                       #recalculating cluster centers
    sum2=np.zeros(columns)
    for j in range(rows):
       if(membership[j]==0):
         count=count+1
         for k in range(columns):
           sum1[k]+=x[j][k]

       else:
       	for k in range(columns):
       		sum2[k]+=x[j][k]

    if(count != 0):                               #computing mean
     sum1=np.divide(sum1,count)
    if(count != rows):
     sum2=np.divide(sum2,rows-count)
    
    #update cluster centers
    cmean1=sum1                  
    cmean2=sum2

#print(membership)
filename = open('15EC10044_7.out','w')

#add 1 to memebership values, to classify them as class 1 and 2
for i in range(membership.shape[0]):
	filename.write(str(((int)(membership[i]))+1)+" ")

filename.close()



