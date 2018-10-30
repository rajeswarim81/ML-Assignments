#15EC10044
#Rajeswari Mahapatra
#Assignment: 6
#The number of epoch may be increased to get a converging value, it produces different results because of random weights with 10 epochs

import numpy as np 

features=8

with open('data6.csv', 'r') as f:
    train_data = []
    train_label=[]
    for line in f:
            line=line.rstrip()
            words = line.split(',')
            #print words[8]
            train_data.append(words[0:features])
            train_label.append(words[features])

train_data=np.asarray(train_data, dtype=np.float64)
train_label=np.asarray(train_label, dtype=np.float64)
train_label.shape=(train_label.shape[0],1)
#print(np.sum(train_label, axis=0))

with open('test6.csv','r') as f:
    test_data=[]
    for line in f:
        line=line.rstrip()
        words=line.split(',')
        test_data.append(words[0:features])

test_data=np.asarray(test_data,dtype=np.float64)


epoch=10
lr=0.1
weight=np.random.uniform(size=(features,1))
#print(weight)
bias=np.random.uniform()



def activation(x):
    return 1/(1 + np.exp(-x))

#print(weight.dtype.name)
for i in range(epoch):

    delta_w=np.zeros(train_data.shape[1])
    bias_update=0
    for j in range(train_data.shape[0]):
       output=np.dot(train_data[j],weight)
       output += bias
       output_=activation(bias)

       error=train_label[j]-output_

       for k in range(train_data.shape[1]):
         delta_w[k] += (lr*error*train_data[j][k])
       bias_update=lr*error
    
    
    for l in range(train_data.shape[1]):
      weight[l] += delta_w[l]
    bias += bias_update

def predict(x):
  return 1*(x>0.5)

filename = open('15EC10044_6.out','w')

                    


for i in range(test_data.shape[0]):
  output= np.dot(test_data[i],weight)+bias
  output_=activation(output)
  z=predict(output_)
  #print(z)
  filename.write(str(z)+" ")
    
filename.close()    



    
