import pandas as pd
import numpy as np
from sklearn.model_selection import train_test_split
from sklearn.svm import SVC
#%%
filename = 'data5.csv'
dataset = pd.read_csv(filename,header=None)


train, test = train_test_split(dataset, test_size=0.3)


train_x = train.iloc[:,:-1].values
train_y = train.iloc[:,57].values

test_x = test.iloc[:,:-1].values
test_y = test.iloc[:,57].values
#%%
test_acc=[]
train_acc=[]
for j in range(1,100,1):
    
    
    svclassifier = SVC(C=j, kernel='poly', degree=2,
                       coef0=0.0, shrinking=True,
                       probability=False, tol=0.001, cache_size=200, class_weight=None,
                       verbose=False, max_iter=100000, decision_function_shape='ovr', random_state=None)
    svclassifier.fit(train_x, train_y)  
    
  
    final_test = svclassifier.predict(test_x)
    final_train = svclassifier.predict(train_x)

    #calculate accuracy for train
    count1=0.0
    for i in range(3220):
        if (final_train[i] == train_y[i]):
            count1+=1
            
            
    print("train accuracy :",count1/3220,'C=',j,) 
    train_acc = np.append(train_acc,count1/3220)
    
    #calculate accuracy for test
    count=0.0
    for i in range(1381):
        if (final_test[i] == test_y[i]):
            count+=1
            
            
    print('test_accuracy :',count/1381,'C=',j)    
    test_acc = np.append(test_acc,count/1381)
    
    
#%%    
print(np.max(test_acc))
print((np.argmax(test_acc)+1))
    
    
    
    
    
    
    